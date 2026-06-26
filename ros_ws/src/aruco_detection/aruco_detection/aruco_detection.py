import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import PoseArray, Pose, TransformStamped
from visualization_msgs.msg import MarkerArray, Marker
from cv_bridge import CvBridge

from tf2_ros import TransformBroadcaster

import cv2
import cv2.aruco as aruco
import numpy as np

class ArucoDetectorNode(Node):
    def __init__(self):
        super().__init__('aruco_detector')

        self.declare_parameter("image_topic", "/camera/image_raw")
        self.declare_parameter("camera_info_topic", "/camera/camera_info")
        self.declare_parameter("marker_size", 0.3)
        self.declare_parameter("aruco_dictionary", "DICT_6X6_250")
        self.declare_parameter("publish_tf", True)
        self.declare_parameter("debug_image_topic", "/aruco/debug_image")
        self.declare_parameter("poses_topic", "/aruco/poses")

        self.image_topic = self.get_parameter("image_topic").value
        self.camera_info_topic = self.get_parameter("camera_info_topic").value
        self.marker_size = float(self.get_parameter("marker_size").value)
        self.aruco_dict_name = self.get_parameter("aruco_dictionary").value
        self.publish_tf = bool(self.get_parameter("publish_tf").value)
        self.debug_image_topic = self.get_parameter("debug_image_topic").value
        self.poses_topic = self.get_parameter("poses_topic").value

        fov = 1.089
        width = 640
        height = 480
        fx = (width / 2.0) / np.tan(fov / 2.0)
        fy = fx
        cx = width / 2.0
        cy = height / 2.0
        self.camera_matrix = np.array([
            [fx, 0.0, cx],
            [0.0, fy, cy ],
            [0.0, 0.0, 1.0]
        ], dtype=np.float32)
        self.dist_coeffs = np.zeros((5, 1), dtype=np.float32)
        self.camera_info_recieved = False
        
        dict_id = getattr(aruco, self.aruco_dict_name, None)
        if dict_id is None:
            self.get_logger().warn(
                f'Unknown dictionary {self.aruco_dict_name}, using DICT_6X6_250 as default'
            )
            dict_id = aruco.DICT_6X6_250
        self.aruco_dict = aruco.Dictionary_get(dict_id)
        self.aruco_params = aruco.DetectorParameters_create()

        self.bridge = CvBridge()
        self.tf_broadcaster = TransformBroadcaster(self)

        img_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history = HistoryPolicy.KEEP_LAST,
            depth = 1,
        )
        info_qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
        )

        self.image_sub = self.create_subscription(
            Image, self.image_topic, self.image_callback, img_qos
        )
        self.camera_info_sub = self.create_subscription(
            CameraInfo, self.camera_info_topic, self.camera_info_callback, info_qos
        )

        self.pose_pub = self.create_publisher(
            PoseArray, self.poses_topic, 10
        )
        self.marker_pub = self.create_publisher(
            MarkerArray, '/aruco/markers', 10
        )
        self.debug_pub = self.create_publisher(
            Image, self.debug_image_topic, 10
        )

        self.get_logger().info("Aruco detector node started")

    def camera_info_callback(self, msg: CameraInfo):

        if self.camera_info_recieved:
            return
        self.camera_matrix = np.array(msg.k, dtype=np.float32).reshape(3,3)
        if msg.d:
            self.dist_coeffs = np.array(msg.d, dtype=np.float32).reshape(-1, 1)
        self.camera_info_recieved = True
        self.get_logger().info(
            f'CameraInfo: fx={self.camera_matrix[0,0]:.1f} '
            f'fy={self.camera_matrix[1,1]:.1f} '
            f'cx={self.camera_matrix[0,2]:.1f} '
            f'cy={self.camera_matrix[1,2]:.1f}'
        )

    def image_callback(self, msg: Image):

        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        except Exception as e:
            self.get_logger().error(f"cv_bridge exception: {e}")
            return

        gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)

        corners, ids, rejected = aruco.detectMarkers(
            gray, self.aruco_dict, parameters=self.aruco_params
        )

        if ids is None or len(ids) == 0:
            return
        
        rvecs, tvecs, _ = aruco.estimatePoseSingleMarkers(
            corners, self.marker_size, self.camera_matrix, self.dist_coeffs
        )
        
        pose_array = PoseArray()
        pose_array.header = msg.header
        pose_array.header.frame_id = 'camera_optical_frame'

        marker_array = MarkerArray()

        for i, marker_id in enumerate(ids.flatten()):
            rvec = rvecs[i][0]
            tvec = tvecs[i][0]

            half = self.marker_size / 2.0
            obj_points = np.array([
                [-half, half, 0.0], 
                [half, half, 0.0], 
                [half, -half, 0.0],
                [-half, -half, 0.0]
            ], dtype=np.float32)

            projected, _ = cv2.projectPoints(
                obj_points, rvec, tvec, self.camera_matrix, self.dist_coeffs
            )
            error_px = float(np.mean(
                np.linalg.norm(projected.reshape(-1, 2) - corners[i].reshape(-1, 2), axis=1)
            ))

            R, _ = cv2.Rodrigues(rvec)
            qw = np.sqrt(1.0 + R[0, 0] + R[1,1] + R[2,2]) / 2.0
            qx = (R[2, 1] - R[1, 2]) / (4.0 * qw)
            qy = (R[0, 2] - R[2, 0]) / (4.0 * qw)
            qz = (R[1, 0] - R[0, 1]) / (4.0 * qw)

            pose = Pose()
            pose.position.x = float(tvec[0])
            pose.position.y = float(tvec[1])
            pose.position.z = float(tvec[2])

            pose.orientation.x = float(qx)
            pose.orientation.y = float(qy)
            pose.orientation.z = float(qz)
            pose.orientation.w = float(qw)

            pose_array.poses.append(pose)

            marker = Marker()
            marker.header = msg.header
            marker.header.frame_id = 'camera_optical_frame'
            marker.ns = 'aruco'
            marker.id = int(marker_id)
            marker.type = Marker.CUBE 
            marker.action = Marker.ADD
            marker.pose = pose
            marker.scale.x = self.marker_size
            marker.scale.y = self.marker_size
            marker.scale.z = 0.01
            marker.color.g = 1.0
            marker.color.a = 0.5
            marker.lifetime.sec = 1
            marker_array.markers.append(marker)

            if self.publish_tf:
                t = TransformStamped()
                t.header.stamp = msg.header.stamp
                t.header.frame_id = 'camera_optical_frame'
                t.child_frame_id = f'marker_{int(marker_id)}'
                t.transform.translation.x = float(tvec[0])
                t.transform.translation.y = float(tvec[1])
                t.transform.translation.z = float(tvec[2])
                t.transform.rotation.x = float(qx)
                t.transform.rotation.y = float(qy)
                t.transform.rotation.z = float(qz)
                t.transform.rotation.w = float(qw)
                self.tf_broadcaster.sendTransform(t)

            self.get_logger().info(
                f'marker_{int(marker_id)}: '
                f'pos=({tvec[0]:+.2f}, {tvec[1]:+.2f}, {tvec[2]:+.2f}) m, '
                f'reproj_err={error_px:.2f} px',
                throttle_duration_sec=0.5,
            )

        self.pose_pub.publish(pose_array)
        self.marker_pub.publish(marker_array)

        debug = cv_image.copy( )
        aruco.drawDetectedMarkers(debug, corners, ids)
        for i in range(len(ids)):
            cv2.drawFrameAxes(
                debug, self.camera_matrix, self.dist_coeffs,
                rvecs[i], tvecs[i], self.marker_size * 0.5
            )
        debug_msg = self.bridge.cv2_to_imgmsg(debug, encoding='bgr8')
        debug_msg.header = msg.header
        self.debug_pub.publish(debug_msg)

def main(args=None):
    rclpy.init(args=args)      
    node = ArucoDetectorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()


                
            


        
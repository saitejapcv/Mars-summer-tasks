import rclpy
from rclpy.node import Node 
from rclpy.node import QoSProfile, ReliabilityPolicy, HistoryPolicy

import os
import yaml

from sensor_msgs.msg import Image 
from cv_bridge import CvBridge
from vision_msgs.msg import Detection2dArray, Detection2d, ObjectHypothesisWithPose

import cv2
import numpy as np

try:
    from ultralytics import YOLO
    ULTRALYTICS_AVAILABLE = True
except ImportError:
    ULTRALYTICS_AVAILABLE = False
    print("Warning: Ultralytics not installed, install it by running: pip install ultralytics")


class ConeDetectionNode(Node):
    def __init__(self):
        super().__init__("cone_detector")

        self.declare_parameter('model_path', 'cone_model.pt')
        self.declare_parameter('class_names_file', '')
        self.declare_parameter('image_topic', '/camera/image_raw')
        self.declare_parameter('conf_threshold', 0.4)
        self.declare_parameter('device', 'cpu')
        self.declare_parameter('publish_debug_image', True)

        model_path = self.get_parameter('model_path').value
        class_names_file = self.get_parameter('class_names_file', '')
        conf = float(self.get_parameter('conf').value)
        self.device = self.get_parameter('device').value
        self.publish_debug = bool(self.get_parameter('publish_debug_image').value)

        self.class_names = {}

        if class_names_file and os.path.isfile(class_names_file):
            with open(class_names_file, 'r') as f:
                data = yaml.safe_load(f)
            self.class_names = {int(k): v for k, v in data['cone_detection']['classes'].items()}
            self.get_logger().info(f'Loaded {len(self.class_names)} class names from {class_names_file}')

        else:
            self.get_logger().warn('No class_names_file provided')

        if not ULTRALYTICS_AVAILABLE:
            self.get_logger().error("ultralytics not available")
            return

        if not os.path.isfile(model_path):
            self.get_logger().error(f"Model file not found at {model_path}")
            return

        self.bridge = CvBridge()

        qos = QoSProfile(
            reliability = ReliabilityPolicy.BEST_EFFORT,
            history = HistoryPolicy.KEEP_LAST,
            depth = 1
            )
        self.image_sub = self.create_subscription(
            Image, self.get_parameter('image_topic').value, self.image_callback, qos
            )

        self.detection_pub = self.create_publisher(
            Detection2dArray, "/cone_detections", 10
            )
        if self.publish_debug:
            self.debug_pub = self.create_publisher(
                Image, "/cones/cone_debug", 10
            )

        self.get_logger().info(f"cone detector node ready")

    def image_callback(self, msg: Image):
        if not ULTRALYTICS_AVAILABLE:
            return

        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding = "bgr8")
        except Exception as e:
            self.get_logger().error(f'cv_bridge conversion failed: {e}')
            return

        results = self.model(cv_image, conf=self.conf, device=self.device, verbose = False)
        result = results[0]

        detection_array = Detection2dArray()
        detection_array.header = msg.header

        for box in result.boxes:
            x1, y1, x2, y2 = box.xyxy[0].cpu().numpy()
            conf = float(box.conf[0])
            cls_id = int(box.cls[0])

            if self.class_names and cls_id in self.class_names:
                cls_name = self.class_names[cls_id]
            elif hasattr(result, 'names') and cls_id in result.names:
                cls_name = result.names[cls_id]
            else:
                cls_name = f'class_{cls_id}'

            det = Detection2d()
            det.header = msg.header
            det.bbox.center.position.x = float((x1 + x2) / 2.0)
            det.bbox.center.position.y = float((y1 + y2) / 2.0)
            det.bbox.size.x = float(x2 - x1)
            det.bbox.size.y = float(y2 - y1)

            hyp = ObjectHypothesis()
            hyp.hypothesis.class_id = cls_name
            hyp.hypothesis.score = conf
            det.hypothesis.append(hyp)
            detection_array.detecions.append(det)

            self.get_logger().info(
                f'{cls_name} at ({(x1+x2)/2.0:.1f},{({y1+y2})/2.0:.1f})'
                f'size = ({x2-x1:.0f}x{y2-y1:.0f} conf={conf:.2f})',
                throttle_duration_sec=0.5,
            )
        self.detections_pub.publish(detection_array)

        if self.publish_debug:
            annotated = result.plot()
            debug_msg = self.bridge.cv2_to_imgmsg(annotated, encoding = "bgr8")
            debug_msg.header = msg.header
            self.debug_pub.publish(debug_msg)

def main(args=None):
    rclpy.init(args=args)
    node = ConeDetectionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()

    
        
            


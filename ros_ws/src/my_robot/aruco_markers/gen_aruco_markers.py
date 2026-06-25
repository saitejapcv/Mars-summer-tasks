import cv2
import cv2.aruco as aruco
import os

aruco_dict = aruco.getPredefinedDictionary(aruco.DICT_6X6_250)

script_dir = os.path.dirname(os.path.abspath(__file__))
output_dir = os.path.join(script_dir, 'aruco_marker_images')
os.makedirs(output_dir, exist_ok=True)

for id in range(10):
    img = aruco.generateImageMarker(aruco_dict, id, 200)
    path = os.path.join(output_dir, f"marker_{id}.png")
    cv2.imwrite(path, img)
    print(f"Generated marker {id} at {path}")
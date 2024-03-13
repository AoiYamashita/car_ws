import base64
import simplejpeg
import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import Image
from std_msgs.msg import String
import numpy as np
import cv2
from cv_bridge import CvBridge

def Sarch_Circle(contours,min_size,max_size,number_of_circles):

    margin = 100

    circle_data = np.zeros((margin,3))

    count = 0

    if len(contours) > 0:
        for i ,cnt in enumerate(contours):
            if count >= margin:
                break

            center ,r = cv2.minEnclosingCircle(cnt)

            if min_size < int(r) and int(r) < max_size:
                circle_data[count,:] += [center[0],center[1],r]
                count+=1

    circles = circle_data[np.argsort(circle_data[:, 2])]

    if count > number_of_circles:
        return circle_data[0:number_of_circles,:]

    return circle_data[0:count,:]

class CircleImgPub(Node):
    def __init__(self):

        super().__init__("receiver")
        self.br = CvBridge()
        self.subscription = self.create_subscription(Image,"image_raw",self.cb,qos_profile_sensor_data)
        self.publisher = self.create_publisher(String,"circle_img",10)
    def cb(self,data):
        data = self.br.imgmsg_to_cv2(data,'bgr8')
        alpha = 1.2
        beta = 50

        frame= data * alpha
        frame[:,:,:] += beta

        frame = np.clip(frame,0,255).astype(np.uint8)
        
        #frame = cv2.blur(frame, (10, 10))

        new_img = cv2.Canny(frame,120,120)
        #ret, new_img = cv2.threshold(cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY), 127, 255, cv2.THRESH_BINARY)
        
        contours, hierarchy = cv2.findContours(new_img,cv2.RETR_LIST, cv2.CHAIN_APPROX_TC89_L1)

        circles = Sarch_Circle(contours,5,400,20)
        #circles = cv2.HoughCircles(new_img,cv2.HOUGH_GRADIENT,1,20,param1=50,param2=30,minRadius=0,maxRadius=0)
        #circles = np.uint16(np.around(circles))

        img_bgr = cv2.cvtColor(new_img, cv2.COLOR_GRAY2BGR)
        
        for i in circles:
            cv2.circle(img_bgr,(int(i[0]),int(i[1])),int(i[2]),(0,0,255),2)

        for i,cnt in enumerate(contours):
            img_bgr = cv2.drawContours(img_bgr,cnt,-1,(0,255,0),2)

        img_jpeg = simplejpeg.encode_jpeg(img_bgr, colorspace = "BGR", quality = 50)
        pub_msg = String()
        pub_msg.data = base64.b64encode(img_jpeg).decode()
        self.publisher.publish(pub_msg)


def main():
    rclpy.init()
    hoge = CircleImgPub()
    rclpy.spin(hoge)

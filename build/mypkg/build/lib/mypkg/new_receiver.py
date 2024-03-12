import base64
import simplejpeg
import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import Image
from std_msgs.msg import String
#from geometry_msgs.msg import Vector3
import numpy as np
import cv2
from cv_bridge import CvBridge

ksize = 7

def Get_Color_Point(img,rgb,under_thresh,upper_thresh):
    minBGR = np.array([rgb[2] - under_thresh, rgb[1] - under_thresh, rgb[0] - under_thresh])
    maxBGR = np.array([rgb[2] + upper_thresh, rgb[1] + upper_thresh, rgb[0] + upper_thresh])

    maskBGR = cv2.inRange(img,minBGR,maxBGR)

    resultRGB = cv2.bitwise_and(img, img, mask = maskBGR)

    gray_rgb = cv2.cvtColor(resultRGB,cv2.COLOR_BGR2GRAY)

    gray_rgb = cv2.medianBlur(gray_rgb,ksize)

    ret, th = cv2.threshold(gray_rgb, 90, 255, cv2.THRESH_BINARY)

    return th

px_rate = 8#distance of camera * px of object
ball_size = 0.288#meter
tan_view_angle = 11.4/23.8#horizon angle,Verticalangle

def Measure_Distance(center,r,frame_):
    coord = np.array([0,0,0])
    if int(r) < 5 or int(r) > 90:
        return coord
    distance = px_rate/r
    frame_coord = [center[0]-frame_.shape[1]/2,-center[1]+frame_.shape[0]/2]
    distance_xy = np.sqrt(center[0]**2 + center[1]**2)*ball_size/(2*r)

    coord = [
            distance_xy*frame_coord[0]/np.sqrt(center[0]**2 + center[1]**2),
            distance_xy*frame_coord[1]/np.sqrt(center[0]**2 + center[1]**2),
            np.sqrt(abs(distance**2-distance_xy**2))
            ]

    return coord

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


class ImgReceiver(Node):
    def __init__(self):

        super().__init__("receiver")
        self.br = CvBridge()
        self.subscription = self.create_subscription(Image,"image_raw",self.cb,qos_profile_sensor_data)
        self.publisher = self.create_publisher(Image,"processed",10)
        #self.publisher = self.create_publisher(Vector3,"balls",10)
        self.pub = self.create_publisher(String, 'web_image', 10)
    def cb(self,data):

        #process of opencv
        #self.get_logger().info("roop")

        data = self.br.imgmsg_to_cv2(data,'bgr8')
        
        alpha = 1.2
        beta = 50

        frame= data * alpha
        frame[:,:,:] += beta

        frame = np.clip(frame,0,255).astype(np.uint8)
        
        #ret,frame = cap.read()

        no_img = np.zeros(frame.shape)

        color_point= Get_Color_Point(frame,[244,54,76],80,80)#[244,54,76][254,209,65]

        contours, hierarchy = cv2.findContours(color_point,cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        for i,cnt in enumerate(contours):
            area = cv2.contourArea(cnt,False)
            if area > 500 :#and area < 1000:
                cv2.drawContours(no_img,cnt,-1,(255,255,255),2)
                cv2.circle(no_img,(int(np.average(cnt[:,0,0])),int(np.average(cnt[:,0,1]))),2,(0,255,0),2)
                cv2.putText(no_img,text=str(area),org=(int(np.average(cnt[:,0,0])),int(np.average(cnt[:,0,1]))),fontFace=cv2.FONT_HERSHEY_SIMPLEX,fontScale=1.0,color=(0, 255, 0),thickness=2,lineType=cv2.LINE_AA)

        
        circles = Sarch_Circle(contours,5,70,10)

        for i in circles:
            cv2.circle(frame,(int(i[0]),int(i[1])),int(i[2]),(0,255,0),2)
            coord = Measure_Distance([i[0],i[1]],i[2],frame)
            cv2.putText(frame,text="x="+str(coord[0]),org=(int(i[0]),int(i[1])-20),fontFace=cv2.FONT_HERSHEY_SIMPLEX,fontScale=1.0,color=(0, 255, 0),thickness=2,lineType=cv2.LINE_AA)
            cv2.putText(frame,text="y="+str(coord[1]),org=(int(i[0]),int(i[1])),fontFace=cv2.FONT_HERSHEY_SIMPLEX,fontScale=1.0,color=(0, 255, 0),thickness=2,lineType=cv2.LINE_AA)
            cv2.putText(frame,text="z="+str(coord[2]),org=(int(i[0]),int(i[1])+20),fontFace=cv2.FONT_HERSHEY_SIMPLEX,fontScale=1.0,color=(0, 255, 0),thickness=2,lineType=cv2.LINE_AA)

        img_jpeg = simplejpeg.encode_jpeg(frame, colorspace = "BGR", quality = 50)
        pub_msg = String()
        pub_msg.data = base64.b64encode(img_jpeg).decode()
        self.pub.publish(pub_msg)

        #result = self.br.cv2_to_imgmsg(no_img,'64FC3')
        #self.publisher.publish(result)

        pass

def main():
    rclpy.init()
    img_receiver = ImgReceiver()
    rclpy.spin(img_receiver)

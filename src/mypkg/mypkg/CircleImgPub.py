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
ball_size = 1.288#meter
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

counter = 0

class ImgReceiver(Node):
    def __init__(self):

        
        super().__init__("receiver")
        self.br = CvBridge()
        self.subscription = self.create_subscription(Image,"image_raw",self.cb,qos_profile_sensor_data)
        self.publisher = self.create_publisher(Image,"processed",10)
        #self.publisher = self.create_publisher(Vector3,"balls",10)
        self.pub = self.create_publisher(String, 'web_image', 10)
        self.clip_pub = self.create_publisher(String, 'clip_image', 10)
    def cb(self,data):


        color = [244,54,76]#[234,44,66]#[244,54,76]

        data = self.br.imgmsg_to_cv2(data,'bgr8')
        
        alpha = 1.3
        beta = 50

        frame= data * alpha
        frame[:,:,:] += beta

        frame = np.clip(frame,0,255).astype(np.uint8)

        no_img = np.zeros(frame.shape)

        color_point= Get_Color_Point(frame,color,60,60)#[244,54,76][254,209,65]

        contours, hierarchy = cv2.findContours(color_point,cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        circles = Sarch_Circle(contours,0,10000,100)

        circle_imgs = []

        for t in circles:
          edge = 1.0*t[2]
          k = [int(t[1]-t[2])-edge,int(t[1]+t[2])+edge,int(t[0]-t[2])-edge,int(t[0]+t[2])+edge]
          if int(k[0]) < 0:
            k[0] = 0
          if int(k[1]) > frame.shape[0]:
            k[1] = frame.shape[0]-1
          if int(k[2]) < 0:
            k[2] = 0
          if int(k[3]) > frame.shape[1]:
            k[3] = frame.shape[1]-1

          img = frame[int(k[0]):int(k[1]),int(k[2]):int(k[3])].copy()
          dst = cv2.resize(img, (120,120))
          dst = cv2.blur(dst,(5,5))
          dst_ = cv2.cvtColor(dst,cv2.COLOR_BGR2GRAY)
          hough = cv2.HoughCircles(dst_, cv2.HOUGH_GRADIENT, dp=1.0, minDist=200, param1=100, param2=20, minRadius=0, maxRadius=0)

          if hough is None:
            continue
          circles_hough = np.uint16(np.around(hough))

          color_point = Get_Color_Point(dst,color,50,50)
          contours, hierarchy = cv2.findContours(color_point,cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
          if len(contours) <= 0:
            continue
          point_area = 0
          for i in contours:
            point_area += cv2.contourArea(i)

          #dst = cv2.drawContours(dst, contours, -1, (255, 255, 0), 5)

          if point_area/(120*120) > 0.015:
              for l in circles_hough[0,:]:
                cv2.circle(frame,(int(t[0]+(l[0]-60)*t[2]/30),int(t[1]+(l[1]-60)*t[2]/30)),int(l[2]*t[2]/30),     (255, 0, 0), 2)
                #cv2.putText(frame,str(point_area/(120*120)),(int(t[0]+(l[0]-60)*t[2]/30),int(t[1]+(l[1]-60)*t[2]/30)),cv2.FONT_HERSHEY_SIMPLEX,1,(255,0,0),2,cv2.LINE_4)
                cv2.circle(dst,(l[0],l[1]),l[2],(255,0,0),2)
              circle_imgs.append(dst)
            #print(point_area/(120*120))


        for i in circles:
          cv2.circle(frame,(int(i[0]),int(i[1])),int(i[2]),(0,255,0),2)

        """
        coord = Measure_Distance([i[0],i[1]],i[2],frame)
        cv2.putText(frame,text="x="+str(coord[0]),org=(int(i[0]),int(i[1])-20),fontFace=cv2.FONT_HERSHEY_SIMPLEX,fontScale=1.0,color=(0, 255, 0),thickness=2,lineType=cv2.LINE_AA)
        cv2.putText(frame,text="y="+str(coord[1]),org=(int(i[0]),int(i[1])),fontFace=cv2.FONT_HERSHEY_SIMPLEX,fontScale=1.0,color=(0, 255, 0),thickness=2,lineType=cv2.LINE_AA)
        cv2.putText(frame,text="z="+str(coord[2]),org=(int(i[0]),int(i[1])+20),fontFace=cv2.FONT_HERSHEY_SIMPLEX,fontScale=1.0,color=(0, 255, 0),thickness=2,lineType=cv2.LINE_AA)
        """

        for t in circle_imgs:
            img_jpeg = simplejpeg.encode_jpeg(t, colorspace = "BGR", quality = 50)
            pub_msg = String()
            pub_msg.data = base64.b64encode(img_jpeg).decode()
            self.clip_pub.publish(pub_msg)

        img_jpeg = simplejpeg.encode_jpeg(frame, colorspace = "BGR", quality = 50)
        pub_msg = String()
        pub_msg.data = base64.b64encode(img_jpeg).decode()
        self.pub.publish(pub_msg)

        

        global counter
        counter += 1
          #print("-------------------------------------------------------------------------")

        pass
        #cv2_imshow(frame)

def main():
    rclpy.init()
    img_receiver = ImgReceiver()
    #try:
    rclpy.spin(img_receiver)
    #except KeyboardInterrupt:
        #pass
    #rclpy.shutdown()

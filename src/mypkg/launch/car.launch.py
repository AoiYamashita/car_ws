import launch
import launch.actions
import launch.substitutions
import launch_ros.actions

def generate_launch_description():
    camera = launch_ros.actions.Node(
            package = 'mypkg',
            executable = 'camera',
            output = 'screen',
            )
    serial = launch_ros.actions.Node(
            package = 'mypkg',
            executable = 'serial',
            output = 'screen',
            )
    usb_cam = launch_ros.actions.Node(
            package = 'usb_cam',
            executable = 'usb_cam_node_exe',
            parameters=[{"image_width","640"},{"image_height","480"},{"pixel_format","yuyv"}],
            output = 'screen',
            )
    web = launch_ros.actions.Node(
            package = 'rosbridge_server',
            executable = 'rosbridge_websocket.py',
            parameters=[{'port': 9092}],
            output = 'screen',
            )
    circle = launch_ros.actions.Node(
            package = 'mypkg',
            executable = 'CircleImgPub',
            output = 'screen',
            )
    return launch.LaunchDescription([web,usb_cam,circle])#,serial])

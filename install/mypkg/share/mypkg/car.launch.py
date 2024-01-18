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
            output = 'screen',
            )
    return launch.LaunchDescription([camera,serial,usb_cam])

#include"ros/ros.h"
#include"tf2_ros/static_transform_broadcaster.h"
#include"geometry_msgs/TransformStamped.h"
#include"tf2/LinearMath/Quaternion.h"

int main(int argc,char **argv)
{
    ros::init(argc, argv, "static_pub");
    ros::NodeHandle handle;
    //3、创建发布对象
    tf2_ros::StaticTransformBroadcaster pub;
    //4、组织被发布数据
    geometry_msgs::TransformStamped tfs;
    tfs.header.stamp = ros::Time::now();
    tfs.header.frame_id = "base_link";
    tfs.child_frame_id = "laser";
    tfs.transform.translation.x = 0.2;
    tfs.transform.translation.y = 0.0;
    tfs.transform.translation.z = 0.5;
    //需要根据欧拉角转换
    tf2::Quaternion qtn;//创建四元数对象
    //向该对象设置欧拉角，这个对象将欧拉角转换成四元数
    qtn.setRPY(0, 0, 0);//欧拉角单位：弧度

    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();
    //5、发布数据
    pub.sendTransform(tfs);

    //6、spin()
    ros::spin();
    
    return 0;
}
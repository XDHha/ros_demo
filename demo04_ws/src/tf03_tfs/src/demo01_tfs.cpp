#include"ros/ros.h"
#include"tf2_ros/transform_listener.h"
#include"tf2_ros/buffer.h"
#include"geometry_msgs/PointStamped.h"
#include"tf2_geometry_msgs/tf2_geometry_msgs.h"
#include"geometry_msgs/TransformStamped.h"

int main(int argc, char** argv)
{
    //2、初始化、NodeHandle
    ros::init(argc, argv, "tfs_sub");
    ros::NodeHandle handle;

    //3、创建订阅对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);

    //4、编写解析逻辑

    //创建坐标点
    geometry_msgs::PointStamped psAtSon1;

    psAtSon1.header.stamp = ros::Time::now();
    psAtSon1.header.frame_id = "son1";
    psAtSon1.point.x = 1.0;
    psAtSon1.point.y = 2.0;
    psAtSon1.point.z = 3.0;

    ros::Rate rate(10);
    while (ros::ok()) {
        //核心
        try
        {
            //1、计算son1和son2的相对关系
            geometry_msgs::TransformStamped son1ToSon2 = buffer.lookupTransform("son2", "son1", ros::Time(0));
            ROS_INFO("Son1 versus Son2:parent lever:%s,child lever:%s The offset(%.2f,%.2f,%.2f))",
                    son1ToSon2.header.frame_id.c_str(),
                    son1ToSon2.child_frame_id.c_str(),
                    son1ToSon2.transform.translation.x,
                    son1ToSon2.transform.translation.y,
                    son1ToSon2.transform.translation.z);
            //2、计算son1某个坐标点在son2中的坐标值
            geometry_msgs::PointStamped psAtSon2 = buffer.transform(psAtSon1, "son2");
            ROS_INFO("The value of the coordinate point in Son2:(%.2f,%.2f,%.2f)",
                    psAtSon2.point.x,
                    psAtSon2.point.y,
                    psAtSon2.point.z);
        }
        catch(const std::exception& e)
        {
            ROS_INFO("error tip:%s", e.what());
        }
        
        rate.sleep();
        ros::spinOnce();
    }

    return 0;

}
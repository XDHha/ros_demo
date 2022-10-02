#include "ros/ros.h"
#include "turtlesim/Pose.h"

/* 
    需求：订阅乌龟位姿信息
    topic: /turtle1/pose
    msg:  turtlesim/Pose

 */

void doPose(const turtlesim::Pose::ConstPtr &pose)
{
    ROS_INFO("Turtle pose information:coordinates(%.2f,%.2f),"
             "toward(%.2f),Linear velocity:%.2f,angular velocity%.2f",
             pose->x, pose->y, pose->theta, pose->linear_velocity, pose->angular_velocity);
}

int main(int argc,char *argv[])
{
    //2、初始化ros节点
    ros::init(argc, argv, "sub_pose");

    //3、创建节点句柄
    ros::NodeHandle handle;

    //4、创建订阅者对象
    ros::Subscriber sub = handle.subscribe("/turtle1/pose", 100, doPose);

    ros::spin();

    return 0;
}
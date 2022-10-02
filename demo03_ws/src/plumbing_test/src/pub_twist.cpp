#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
/* 
    需求：发布速度消息
        topic: /turtle1/cmd_vel
        msg:   geometry_msgs/Twist
    
 */
int main(int argc,char *argv[])
{
    //2、初始化ros节点
    ros::init(argc, argv, "my_control");

    //3、创建节点句柄
    ros::NodeHandle handle;

    //4  创建发布者对象
    ros::Publisher pub = handle.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    
    //5  发布逻辑
    ros::Rate rate(10);//设置发布频率
    //组织发布的消息
    geometry_msgs::Twist twist;
    twist.linear.x = 2;
    twist.linear.y = 0;
    twist.linear.z = 0;

    twist.angular.x = 0;
    twist.angular.y = 0;
    twist.angular.z = 3.14;

    //循环发布
    while (ros::ok())
    {
        pub.publish(twist);
        //休眠
        rate.sleep();
        //回头
        ros::spinOnce();
    }
}
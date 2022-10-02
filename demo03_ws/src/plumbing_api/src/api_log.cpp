#include "ros/ros.h"


int main(int argc,char *argv[])
{
    //2、初始化ros节点
    ros::init(argc, argv, "pub_node",ros::init_options::AnonymousName);

    //3、创建节点句柄
    ros::NodeHandle handle;

    ROS_DEBUG("DEBUG");
    ROS_INFO("INFO");
    ROS_WARN("WARN");
    ROS_ERROR("ERROR");
    ROS_FATAL("FATAL");

    
    return 0;
}
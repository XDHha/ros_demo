#include "ros/ros.h"

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hello_node");

    ROS_INFO("hello,哈哈哈");
    
    
    return 0;
}
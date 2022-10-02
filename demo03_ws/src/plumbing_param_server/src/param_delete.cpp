#include "ros/ros.h"
    
int main(int argc,char *argv[])
{
    ros::init(argc, argv, "delete_paramter");

    ros::NodeHandle nh;

    bool flag1 = nh.deleteParam("radius");
    if(flag1)
        ROS_INFO("Delete successfully!!!");
    else
        ROS_INFO("Delete failed!!!");
        
    return 0;
}
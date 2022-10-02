#include "ros/ros.h"
/* 
    实现参数新增和修改
    需求：首先设置机器人的共享参数，类型，半径（0.15)
          再修改半径(0.2)
 */

int main(int argc,char *argv[])
{
    ros::init(argc, argv, "set_paramter");

    ros::NodeHandle nh;

    //Add param
    //plan one:nh
    nh.setParam("type", "yellow car");
    nh.setParam("radius", 0.5);
    //plan two:param
    ros::param::set("type_param", "white car");
    ros::param::set("radius_param", 0.15);

    //Modify param
    //plan one:nh
    nh.setParam("radius", 0.3);
    //plan two:param
    ros::param::set("radius_param", 0.25);
    
    return 0;
}
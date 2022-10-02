#include "ros/ros.h"

int main(int argc,char *argv[])
{
    ros::init(argc, argv, "get_paramter");

    ros::NodeHandle nh;

    //1  param
    // double radius = nh.param("radius", 0.1);
    // ROS_INFO("radius=%.2f", radius);

    //2  getParam
    // double radiusStore = 0.0;
    // bool result = nh.getParam("radius", radiusStore);
    // if(result)
    //     ROS_INFO("the radius is %.2f", radiusStore);
    // else
    //     ROS_INFO("the various searched is noexit");

    //3  getParamCached
    // double radiusStore = 0.2;
    // bool result = nh.getParamCached("radius", radiusStore);
    // if(result)
    //     ROS_INFO("the radius is %.2f", radiusStore);
    // else
    //     ROS_INFO("the various searched is noexit");

    //4  getParamNames
    // std::vector<std::string> names;
    // nh.getParamNames(names);
    // for(auto &&name:names)
    //     ROS_INFO("The element that is traversed:%s", name.c_str());

    //5  hasParam
    // bool flag1 = nh.hasParam("radius");
    // bool flag2 = nh.hasParam("raduis");
    // ROS_INFO("The radius?  %d", flag1);
    // ROS_INFO("The raduis?  %d", flag2);

    //6
    std::string key;
    nh.searchParam("radius", key);
    ROS_INFO("The search results:%s", key.c_str());

    return 0;
}
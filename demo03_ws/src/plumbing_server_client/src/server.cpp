#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

bool doNums(plumbing_server_client::AddInts::Request &req,
            plumbing_server_client::AddInts::Response &res)
{
    //处理请求
    res.sum = req.num1 + req.num2;

    return true;
}
int main(int argc,char *argv[])
{
    ros::init(argc, argv, "server_node");

    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("addInts", doNums);

    ROS_INFO("server is start!!");
    
    ros::spin();

    return 0;
}
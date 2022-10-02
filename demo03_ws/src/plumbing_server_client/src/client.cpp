#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        ROS_INFO("Incorrect number of parameters were submitted!!");
        return 1;
    }
    ros::init(argc, argv, "client_node");

    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");

    plumbing_server_client::AddInts ai;

    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    // client.waitForExistence();//挂起功能函数
    ros::service::waitForService("addInts");
    bool flag = client.call(ai);
    if (flag)
    {
        ROS_INFO("response is successful!!");
        ROS_INFO("sum=%d", ai.response.sum);
    }
    else
    {
        ROS_INFO("response is failure!!");
    }

    return 0;
}
#include"ros/ros.h"
#include"std_msgs/String.h"

int main(int argc,char ** argv)
{
    ros::init(argc, argv, "hello");
    // ros::NodeHandle handle;
    // 核心：设置不同类型话题
    // 1、全局
    // ros::Publisher pub = handle.advertise<std_msgs::String>("/chatter", 1000);

    //2、相对
    // ros::Publisher pub = handle.advertise<std_msgs::String>("chatter", 1000);


    //3、私有---需要创建特定NodeHandle
    ros::NodeHandle handle("~");
    ros::Publisher pub = handle.advertise<std_msgs::String>("chatter", 1000);

    while(ros::ok()){

    }

    return 0;
}
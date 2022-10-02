#include "ros/ros.h"
#include "turtlesim/Spawn.h"
/* 
    需求：向服务端发送请求，生成一只新乌龟
        topic:/Spawn
        srv:turtlesim/Spawn
 */

int main(int argc,char *argv[])
{

    //2、初始化ros节点
    ros::init(argc, argv, "set_turtle");

    //3、创建节点句柄
    ros::NodeHandle handle;

    //4、创建客户端对象
    ros::ServiceClient client = handle.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Spawn spawn;

    // spawn.request.x = atoi(argv[1]);
    // spawn.request.y = atoi(argv[2]);
    // spawn.request.theta = atoi(argv[3]);
    // spawn.request.name = argv[4];
    spawn.request.x = 2;
    spawn.request.y = 3;
    spawn.request.theta = 2;
    spawn.request.name = "my";
    
    ros::service::waitForService("/spawn");
    bool flag = client.call(spawn);

    if(flag)
    {
        ROS_INFO("The new turtle name is:%s", spawn.request.name.c_str());
    }
    else
    {
        ROS_INFO("Turtle generation failed!!!");
    }

    return 0;
}
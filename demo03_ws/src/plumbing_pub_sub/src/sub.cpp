#include"ros/ros.h"
#include"std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr &msg)
{
    //通过msg获取并操作订阅到的数据
    ROS_INFO("subscriber's data: %s", msg->data.c_str());
}

int main(int argc,char *argv[])
{
    //2、初始化ros节点
    ros::init(argc, argv, "sub_node");

    //3、创建节点句柄
    ros::NodeHandle nh;

    //4、创建订阅者对象
    ros::Subscriber sub = nh.subscribe("hello_topic", 10, doMsg);

    //5、处理订阅到的数据
    ros::spin();
    
    return 0;
}
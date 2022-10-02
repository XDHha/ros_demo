#include"ros/ros.h"
#include"rosbag/bag.h"
#include"std_msgs/String.h"

int main(int argc, char** argv)
{
    // 1、初始化
    ros::init(argc, argv, "bag_write");
    ros::NodeHandle handle;
    //2、创建rosbag对象
    rosbag::Bag bag;
    //3、打开文件流
    bag.open("hello.bag", rosbag::BagMode::Write);
    //4、写数据
    std_msgs::String msg;
    msg.data = "hello you";
    bag.write("/chatter", ros::Time::now(), msg);
    //5、关闭文件流
    bag.close();
    return 0;
}
//1、包含头文件
#include"ros/ros.h"
#include"std_msgs/String.h"
#include<sstream>

int main(int argc,char *argv[])
{
    //2、初始化ros节点
    ros::init(argc, argv, "pub_node",ros::init_options::AnonymousName);

    //3、创建节点句柄
    ros::NodeHandle nh;

    //4、创建发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("hello_topic", 10, true);

    //5、编写发布逻辑,发布数据:要求以10HZ频率发布数据，并且文本后添加编号
    //先创建被发布的消息
    std_msgs::String msg;
    //发布频率
    ros::Rate rate(5);
    ros::Duration(3).sleep();
    //编写循环，循环中发布数据
    //设置编号
    int count=0;
    while (ros::ok())
    {
        count++;
        // msg.data = "hello";
        std::stringstream ss;
        ss << "hello --->" << count;
        msg.data = ss.str();
        
        pub.publish(msg);

        ROS_INFO("data published is:%s", ss.str().c_str());
        
        rate.sleep();

        ros::spinOnce();

    }

    // ros::spin();
    return 0;
}
#include "ros/ros.h"

void cb(const ros::TimerEvent &event)
{
    ROS_INFO("-----------");
    ROS_INFO("method called time:%.2f", event.current_real.toSec());
}
int main(int argc,char *argv[])
{
    ros::init(argc, argv, "hello_time");

    ros::NodeHandle handle;

    ros::Time right_now = ros::Time::now();

    ROS_INFO("now time:%.2f", right_now.toSec());
    ROS_INFO("now time:%d", right_now.sec);

    ros::Time t1(20, 844234567);
    ROS_INFO("t1:%.2f", t1.toSec());

    //持续时间
    ros::Time start = ros::Time::now();
    ros::Duration du(4.5);
    du.sleep();
    ros::Time end = ros::Time::now();
    ROS_INFO("sleep time=%.2f", end.toSec() - start.toSec());
    
    //定时器
    ros::Timer timer1 = handle.createTimer(ros::Duration(1), cb, false, false);

    timer1.start();

    ros::spin();

    return 0;
}
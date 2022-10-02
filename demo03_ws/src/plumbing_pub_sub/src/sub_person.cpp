#include"ros/ros.h"
#include"std_msgs/String.h"
#include"plumbing_pub_sub/Person.h"

void doPerson(const plumbing_pub_sub::Person::ConstPtr &person)
{
    //通过msg获取并操作订阅到的数据
    ROS_INFO("student's data: name=%s,age=%d,height=%.2f", person->name.c_str(),person->age,person->height);
}

int main(int argc,char *argv[])
{
    //2、初始化ros节点
    ros::init(argc, argv, "parent_sub");

    //3、创建节点句柄
    ros::NodeHandle nh;

    //4、创建订阅者对象
    ros::Subscriber sub = nh.subscribe("chatter_topic", 10, doPerson);

    //5、处理订阅到的数据

    //6
    ros::spin();

    return 0;
}
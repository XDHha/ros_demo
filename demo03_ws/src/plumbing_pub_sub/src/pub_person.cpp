#include"ros/ros.h"
#include"plumbing_pub_sub/Person.h"

int main(int argc,char *argv[])
{
    //2、初始化ros节点
    ros::init(argc, argv, "marster_pub");

    //3、创建节点句柄
    ros::NodeHandle nh;

    //4、创建发布者对象
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Person>("chatter_topic", 10);

    //5、编写发布逻辑,发布数据
    plumbing_pub_sub::Person person;
    person.name = "xdh";
    person.age = 24;
    person.height = 1.8;

    ros::Rate rate(1);

    while (ros::ok())
    {
        person.age++;
        //发布数据
        pub.publish(person);

        rate.sleep();
        //6 spinOnce
        ros::spinOnce();
    }
    return 0;
}
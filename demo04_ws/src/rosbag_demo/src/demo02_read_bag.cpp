#include"ros/ros.h"
#include"rosbag/bag.h"
#include"rosbag/view.h"
#include"std_msgs/String.h"

int main(int argc, char** argv)
{
    // 1、初始化
    ros::init(argc, argv, "bag_read");
    ros::NodeHandle handle;
    //2、创建rosbag对象
    rosbag::Bag bag;
    //3、打开文件流
    bag.open("hello.bag", rosbag::BagMode::Read);
    //读数据
    //获取消息集合，迭代取出消息的字段
    for (auto&& m : rosbag::View(bag)) {
        //解析
        std::string topic = m.getTopic();
        ros::Time time = m.getTime();
        std_msgs::StringPtr p = m.instantiate<std_msgs::String>();
        ROS_INFO("Content of parsing,topic:%s,The time stamp:%.2f,msg value:%s",
            topic.c_str(),
            time.toSec(),
            p->data.c_str());
    }
    //5、关闭文件流
    bag.close();
    






    
    return 0;
}
#include <ros/ros.h>
#include <leap_subscriber/leapros.h>

using namespace std;

void call_back_leapdata(const leap_subscriber::leapros msg)
{
		cout<<"x:"<<msg.ypr.x<<" ";
		cout<<"y:"<<msg.ypr.y<<" ";
		cout<<"z:"<<msg.ypr.z<<endl;
}

int main(int argc,char **argv)
{
		ros::init(argc,argv,"leap_sub");
		ros::NodeHandle n;

		leap_subscriber::leapros msgs;
		ros::Subscriber leap_sub = n.subscribe("leapmotion/data",1000,call_back_leapdata);
		ros::spin();

		return 0;
}


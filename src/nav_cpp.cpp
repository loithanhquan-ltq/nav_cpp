#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <nav_msgs/Odometry.h>

int main(int argc, char** argv)
{
    ros::init(argc,argv,"nav_cpp");
    ros::NodeHandle n;
    ros::Publisher publisher = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose",1);
    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        geometry_msgs::PoseWithCovarianceStamped init_msg;
        nav_msgs::Odometry odom_msg = *( ros::topic::waitForMessage<nav_msgs::Odometry>("/odom",n) );

        init_msg.header.frame_id = "map";

        // Position
        init_msg.pose.pose.position.x = odom_msg.pose.pose.position.x;
        init_msg.pose.pose.position.y = odom_msg.pose.pose.position.y;

        // Orientation
        init_msg.pose.pose.orientation.x = odom_msg.pose.pose.orientation.x;
        init_msg.pose.pose.orientation.y = odom_msg.pose.pose.orientation.y;
        init_msg.pose.pose.orientation.z = odom_msg.pose.pose.orientation.z;
        init_msg.pose.pose.orientation.w = odom_msg.pose.pose.orientation.w;

        publisher.publish(init_msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
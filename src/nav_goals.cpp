#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <string>
#include "file_reader_class.cpp"

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
using namespace std;

int main(int argc, char **argv)
{

    ros::init(argc, argv, "nav_goals");

    // we want to spin a thread by default
    MoveBaseClient ac("move_base", true);

    // wait for action server to come up
    while (!ac.waitForServer(ros::Duration(5.0)))
    {
        ROS_INFO("Waiting for the move_base action server to come up");
    }

    move_base_msgs::MoveBaseGoal goal;

    GetRooms room;
    room.readFile("test.txt");
    vector<roomData> rooms = room.getRooms();
    int i = 0;

    // we'll send a goal to the robot to move 1 meter forward
    while (rooms[i].Name != "0")
    {
        goal.target_pose.header.frame_id = "base_link";
        goal.target_pose.header.stamp = ros::Time::now();

        goal.target_pose.pose.position.x = 1.0;
        goal.target_pose.pose.orientation.w = 1.0;

        ROS_INFO("sending goal");
        ac.sendGoal(goal);

        ac.waitForResult();

        if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
            ROS_INFO("base moved forward");
        else
            ROS_INFO("the base failed to move for some reason");
        i ++;

    }

    return 0;
}
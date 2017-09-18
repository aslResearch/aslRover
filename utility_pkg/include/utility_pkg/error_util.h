#ifndef UTILITY_PKG__PARAM_ERROR_UTIL_H
#define UTILITY_PKG__PARAM_ERROR_UTIL_H

#include <ros/ros.h>

namespace utility_pkg{

void throw_error(const std::string& param_name, int line_num)
{
    ROS_ERROR("%s: At line [%d] ~ can't access param-> %s", 
                ros::this_node::getName().c_str(),
                line_num,
                param_name.c_str());
}

void throw_warn(const std::string& param_name, int line_num)
{
    ROS_WARN("%s: At line [%d] ~ can't access param-> %s",
                ros::this_node::getName().c_str(),
                line_num,
                param_name.c_str());
}

void throw_warn(const std::string& param_name, int line_num, const std::string& msg)
{
    ROS_WARN("%s: At line [%d] ~ can't access param-> %s, %s",
                ros::this_node::getName().c_str(),
                line_num,
                param_name.c_str(),
                msg.c_str());
}


void throw_error_and_shutdown(const std::string& param_name, int line_num)
{
    throw_error(param_name, line_num);
    ROS_ERROR("Shutting down node: %s", 
            ros::this_node::getName().c_str());

    ros::shutdown();
}

} //end namespace{utility_pkg}


#endif
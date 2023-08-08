#include <rclcpp/rclcpp.hpp>
#include <rclcpp/qos.hpp>
#include "ublox_status_monitor_node.hpp"
#include "ublox_msgs/msg/nav_pvt.hpp"

#include <string.h>

void UbloxStatusMonitor::_topic_callback(const ublox_msgs::msg::NavPVT::SharedPtr msg){
  std::string fix_status;
  switch(msg->flags & 192){
    case 0:
      fix_status = std::string("NO FIX");
      break;
    case 64:
      fix_status = std::string("FLOAT");
      break;
    case 128:
      fix_status = std::string("FIX");
      break;
    default:
      fix_status = std::string("ERROR");
      break;
  }

  RCLCPP_INFO(this->get_logger(), fix_status);
}

UbloxStatusMonitor::UbloxStatusMonitor(
  const rclcpp::NodeOptions& options
): UbloxStatusMonitor("",options){}

UbloxStatusMonitor::UbloxStatusMonitor(
  const std::string& name_space, 
  const rclcpp::NodeOptions& options
): Node("UbloxStatusMonitor", name_space, options){
  _subscription = this->create_subscription<ublox_msgs::msg::NavPVT>(
    "navpvt",
    rclcpp::QoS(1),
    std::bind(&UbloxStatusMonitor::_topic_callback, this, std::placeholders::_1)
  );
}

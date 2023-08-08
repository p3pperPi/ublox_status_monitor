#include <rclcpp/rclcpp.hpp>
#include "ublox_msgs/msg/nav_pvt.hpp"

class UbloxStatusMonitor : public rclcpp::Node{
private:
  rclcpp::Subscription<ublox_msgs::msg::NavPVT>::SharedPtr _subscription;
  void _topic_callback(const ublox_msgs::msg::NavPVT::SharedPtr msg);

public:
  UbloxStatusMonitor(
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );

  UbloxStatusMonitor(
    const std::string& name_space, 
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );

};
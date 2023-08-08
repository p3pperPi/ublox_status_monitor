#include <rclcpp/rclcpp.hpp>
#include "ublox_status_monitor_node.hpp"

int main(int argc, char * argv[]){
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<UbloxStatusMonitor>());
  rclcpp::shutdown();
  return 0;
}

// ref
// https://qiita.com/NeK/items/cd00705f7e473f83ca44
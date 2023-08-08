cmake_minimum_required(VERSION 3.5)
project(ublox_status_monitor)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)

find_package(ublox_msgs REQUIRED)
find_package(ublox_serialization REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


include_directories(
  include/ublox_status_monitor
)

add_executable(fix_monitor
  src/ublox_status_monitor_node.cpp
  src/ublox_monitor.cpp
)

ament_target_dependencies(fix_monitor
  rclcpp
  "ublox_msgs"
  "ublox_serialization"
)

install(TARGETS
  fix_monitor
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

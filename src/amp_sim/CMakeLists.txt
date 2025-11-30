cmake_minimum_required(VERSION 3.8)
project(amp_sim)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(amp_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

#include eigen headers
include_directories(${EIGEN3_INCLUDE_DIRS})

#include the headers
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/amp_sim)

#create the libraries
add_library(dynamic_object src/dynamic_object.cpp)
target_include_directories(dynamic_object PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

add_library(dynamic_ball src/dynamic_ball.cpp)
target_link_libraries(dynamic_ball PUBLIC dynamic_object)

add_library(omni_agent src/omni_agent.cpp)
target_link_libraries(omni_agent PUBLIC dynamic_object)

#create the executable 
add_executable(sim_node src/run_sim.cpp)
ament_target_dependencies(sim_node PUBLIC rclcpp geometry_msgs tf2 tf2_ros amp_msgs)
target_link_libraries(sim_node PUBLIC dynamic_ball omni_agent)

install(TARGETS sim_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_export_targets(export_amp_sim HAS_LIBRARY_TARGET)
ament_export_dependencies()
ament_export_include_directories(include)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS dynamic_object omni_agent dynamic_ball
  EXPORT export_amp_sim
  DESTINATION lib
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

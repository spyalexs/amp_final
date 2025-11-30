cmake_minimum_required(VERSION 3.8)
project(amp_agents)

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
find_package(amp_sim REQUIRED)
find_package(OpenCV REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

#include eigen
include_directories(${EIGEN3_INCLUDE_DIRS})

#include opencv
include_directories( ${OpenCV_INCLUDE_DIRS} )

#declare the sst t as a library
add_library(sst_tree src/propagate_sst.cpp)
ament_target_dependencies(sst_tree PUBLIC amp_sim)
target_link_libraries(sst_tree PUBLIC dynamic_object omni_agent)
target_include_directories(sst_tree PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

#declare the backend as a library
add_library(backend src/agent_backend.cpp)
ament_target_dependencies(backend PUBLIC rclcpp geometry_msgs tf2_ros amp_msgs amp_sim)
target_link_libraries(backend PUBLIC sst_tree dynamic_object omni_agent)
target_include_directories(backend PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

#build the tree visualizer
add_library(tree_visualizer src/visualize_tree.cpp)
ament_target_dependencies(tree_visualizer PUBLIC OpenCV)
target_include_directories(tree_visualizer PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

add_executable(run src/run_agent.cpp)
ament_target_dependencies(run PUBLIC rclcpp amp_sim tf2_ros amp_msgs)
target_include_directories(run PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS run
  DESTINATION lib/${PROJECT_NAME}
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

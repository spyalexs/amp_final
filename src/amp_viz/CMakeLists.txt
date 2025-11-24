cmake_minimum_required(VERSION 3.8)
project(amp_viz)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(rviz_common REQUIRED)
find_package(pluginlib REQUIRED)
find_package(amp_msgs REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(Eigen3 REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

#include Eigen
include_directories(${EIGEN3_INCLUDE_DIRS})


#compile QT macros
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

qt5_wrap_cpp(MOC_FILES
  include/amp_viz/template_panel.hpp
)

#link rviz plugins
add_library(template_panel src/template_panel.cpp ${MOC_FILES})
target_include_directories(template_panel PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(template_panel
  pluginlib
  rviz_common
  amp_msgs
)

#install rviz pannel
install(TARGETS template_panel
  EXPORT export_template_panel
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY include/
  DESTINATION include
)

install(FILES rviz_common_plugins.xml
  DESTINATION share/${PROJECT_NAME}
)

#export plugin
ament_export_include_directories(include)
ament_export_targets(export_template_panel)
pluginlib_export_plugin_description_file(rviz_common rviz_common_plugins.xml)

file(GLOB_RECURSE python_exec RELATIVE ${PROJECT_SOURCE_DIR} src/*.py)

install(PROGRAMS ${python_exec}
  DESTINATION lib/${PROJECT_NAME})

install(PROGRAMS ${python_exec}
  DESTINATION share/${PROGECT_NAME})

file(GLOB launch RELATIVE ${PROJECT_SOURCE_DIR} launch/*.py)

#install the launch files
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME}/)

#install the meshes
file(GLOB meshes RELATIVE ${PROJECT_SOURCE_DIR} meshes/*.stl)

install(DIRECTORY meshes DESTINATION share/${PROJECT_NAME}/)

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

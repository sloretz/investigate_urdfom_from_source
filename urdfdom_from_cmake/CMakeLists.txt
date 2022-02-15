cmake_minimum_required(VERSION 3.10)
project(urdfdom_from_cmake)

find_package(urdfdom REQUIRED)

add_executable(use_urdfdom_oldstyle use_urdfdom.cpp)
target_include_directories(use_urdfdom_oldstyle PRIVATE ${urdfdom_INCLUDE_DIRS})
target_link_libraries(use_urdfdom_oldstyle ${urdfdom_LIBRARIES})

if(TARGET urdfdom::urdfdom_model)
  add_executable(use_urdfdom_modern use_urdfdom.cpp)
  target_link_libraries(use_urdfdom_modern urdfdom::urdfdom_model)
else()
  message(WARNING "No urdfdom::urdfdom_model target found")
endif()

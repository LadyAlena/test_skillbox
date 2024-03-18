cmake_minimum_required(VERSION 3.22.0)
project(project_robo)

# Set the language standard C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the librobo library
add_library(librobo 
    source/librobo/Robot2D/Robot2D.h
    source/librobo/Robot2D/Robot2D.cpp
    source/librobo/Robot3D/Robot3D.h
    source/librobo/Robot3D/Robot3D.cpp
    source/librobo/IRobot.h
)

# Set the path for header files lookup
target_include_directories(librobo PUBLIC source)

# Add the main.cpp executable
add_executable(project_robo source/main.cpp)

# Link librobo with project_robo
target_link_libraries(project_robo PRIVATE librobo)
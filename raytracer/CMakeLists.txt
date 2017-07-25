cmake_minimum_required(VERSION 2.8.9)
project(raytracer)

 find_package(ImageMagick COMPONENTS Magick++)
include_directories(${ImageMagick_INCLUDE_DIRS})

#Bring the headers, such as Student.h into the project
include_directories(include)
 
#Can manually add the sources using the set command as follows:
INCLUDE_DIRECTORIES ( Eigen )

 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")



add_library(raytracer SHARED ${SOURCES})
target_link_libraries(raytracer ${ImageMagick_LIBRARIES})

cmake_minimum_required(VERSION 2.8.9)
project (Animation)

#For the shared library:
set ( PROJECT_LINK_LIBS libraytracer.dylib )
link_directories( raytracer/build )


include_directories(raytracer/include)

add_executable(Animation main.cpp)
target_link_libraries(Animation ${PROJECT_LINK_LIBS} )

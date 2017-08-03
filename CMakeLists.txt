cmake_minimum_required(VERSION 3.5)

SET(PROJECT_NAME pewpew)

project(${PROJECT_NAME})

#Add our own Find modules to Cmake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

#Find SDL2 and SDL2_Image
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})


add_executable(${PROJECT_NAME} src/main.cpp
                        src/graphics.cpp
                        src/main.cpp
                        src/main.cpp)


target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
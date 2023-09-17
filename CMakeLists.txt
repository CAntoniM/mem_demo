cmake_minimum_required(VERSION 3.16)

project(example)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

enable_testing()
include(CTest)

endif()

file(GLOB ${PROJECT_NAME}_src "src/*.cpp")
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_src})
target_include_directories(${PROJECT_NAME} PUBLIC "inc")
add_test( NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME})

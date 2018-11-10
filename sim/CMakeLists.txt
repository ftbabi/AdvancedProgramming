cmake_minimum_required(VERSION 3.8)
project(sim)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Person.h Student.cpp Student.h Teacher.cpp Teacher.h Manage.cpp Manage.h Person.cpp)
add_executable(sim ${SOURCE_FILES})
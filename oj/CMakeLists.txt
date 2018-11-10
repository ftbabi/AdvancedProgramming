cmake_minimum_required(VERSION 3.8)
project(oj)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp QuadraticEquation.cpp QuadraticEquation.h Stack.h sort.h Queue.h Manager.cpp Manager.h Member.cpp Member.h Student.cpp Student.h Teacher.cpp Teacher.h Set.cpp Set.h List.h Bike.cpp Bike.h OfoBike.cpp OfoBike.h HelloBike.cpp HelloBike.h BikeSystem.cpp BikeSystem.h Shell.h)
add_executable(oj ${SOURCE_FILES})
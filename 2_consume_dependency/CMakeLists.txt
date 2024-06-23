cmake_minimum_required(VERSION 3.15)

project(network-app CXX)

add_executable(network-app src/main.cpp)

install(TARGETS network-app DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )

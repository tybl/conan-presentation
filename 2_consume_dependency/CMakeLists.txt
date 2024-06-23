cmake_minimum_required(VERSION 3.15)

project(network-app CXX)

find_package(cppzmq REQUIRED)

add_executable(network-app src/main.cpp)
target_link_libraries(network-app PRIVATE cppzmq)

install(TARGETS network-app DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )

cmake_minimum_required(VERSION 3.15)
project(boost-app CXX)

find_package(Boost REQUIRED)

add_executable(boost-app src/main.cpp)
target_link_libraries(boost-app PRIVATE Boost::headers)

install(TARGETS boost-app DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )

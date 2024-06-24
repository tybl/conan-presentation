cmake_minimum_required(VERSION 3.15)
project(proto-resampler CXX)

# New stuff
find_package(Protobuf REQUIRED)

file(GLOB_RECURSE config_proto proto/*.proto)

add_library(config-definitions)
target_include_directories(config-definitions PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(config-definitions PUBLIC protobuf::libprotobuf)
target_sources(config-definitions PUBLIC ${config_proto})

protobuf_generate(TARGET config-definitions IMPORT_DIRS proto)
# End new stuff

add_executable(proto-resampler src/main.cpp)
target_link_libraries(proto-resampler PRIVATE config-definitions)

install(TARGETS proto-resampler DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )

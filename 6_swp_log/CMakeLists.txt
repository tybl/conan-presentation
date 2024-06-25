#****************************************************************************
# RESTRICTED RIGHTS
#
# Contract No.         RealTime SAR ENIRD.FY23.PD.OR.LB.01
# Contractor Name      SRC, Inc.
# Contractor Address   7502 Round Pond Road
#                         North Syracuse, NY 13212
#
#
# Copyright 2023, SRC Inc. as an unpublished work.  All rights reserved
#
#****************************************************************************
#
#  SRC INC. PROPRIETARY INFORMATION
#  This document contains proprietary data or information pertaining to items, or components, or processes,
#  or other matter developed or acquired at the private expense of SRC Inc., and is restricted to use only by
#  persons authorized by SRC in writing to use it. Disclosure to unauthorized persons would likely cause
#  substantial competitive harm to SRC's business position. This technical data or information shall
#  not be furnished or disclosed to or copied or used by persons outside SRC without the express written
#  approval of SRC.
#
#****************************************************************************
#
# NAME: CMakeLists.txt
#
# PURPOSE: Build the SRC Log library
#
# AUTHOR/DATE: $Author: asherwin $ $Date: 2023/03/03 $
# SOURCE/DATE: New
# ORIGINATOR/DATE:
#
# CODE BASELINE: <project and version number where was this code taken from>
#
# REVISION HISTORY:
# $Log:$
#
#****************************************************************************
#
#  SRC INC. PROPRIETARY INFORMATION
#  03/2023: Developed exclusively at private expense with SRC Private Investment ENIRD.FY23.PD.OR.LB.01
#
#  Copyright 2023 SRC, Inc. as an unpublished work. All rights reserved
#
#****************************************************************************
cmake_minimum_required(VERSION 3.15)
project(log_srcinc)

message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

find_package(GTest REQUIRED)

file(GLOB_RECURSE lib_src log/lib/log/src/*.cpp)

add_library(log_srcinc)
target_include_directories(log_srcinc PUBLIC log/include log/include/log)
target_sources(log_srcinc PRIVATE ${lib_src})

add_executable(log_srcinc_test)
target_link_libraries(log_srcinc_test PRIVATE GTest::gmock_main log_srcinc)
target_sources(log_srcinc_test PRIVATE log/lib/log/test/TestLoggerTest.cpp)
add_test(NAME log_srcinc_test COMMAND log_srcinc_test)

install(TARGETS log_srcinc)
install(DIRECTORY log/include/log TYPE INCLUDE FILES_MATCHING PATTERN "*.hpp")

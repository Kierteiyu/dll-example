cmake_minimum_required(VERSION 3.12)
project(dllloaderexample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)
include_directories($(CMAKE_CURRENT_SOURCE_DIR)/external/dynalo/include)

# Glob all source files in /src
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create the program
#add_library(${PROJECT_NAME} SHARED ${SOURCES})
add_executable(${PROJECT_NAME} ${SOURCES})

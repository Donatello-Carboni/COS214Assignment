cmake_minimum_required(VERSION 3.10)
project(COS214_Project)

# Compiler flags
set(CMAKE_CXX_STANDARD 14)

# Locate and configure Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Set the output directory
set(EXECUTABLE_OUTPUT_PATH "../bin")

# Add your source files
file(GLOB SOURCES "./src/*.cpp")
include_directories(src)

# Create the production executable
add_executable(main ${SOURCES} "./src/Main/Main.cpp")

# Create the test executable
add_executable(test ${SOURCES} "./src/tests/test_main.cpp")

# Link against Google Test libraries
target_link_libraries(test ${GTEST_LIBRARIES} pthread)

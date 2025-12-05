
cmake_minimum_required(VERSION 3.28)

project(RogueClone VERSION 1.0.0 LANGUAGES CXX)

# Enforce C++ 17 (Good balance of features and compatibility)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SFML package installed via apt
# We request specific components: graphics, window, and system
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Define our source files
set(SOURCES src/main.cpp)

# Create the executable named "RogueGame"
add_executable(RogueGame ${SOURCES})

# Link SFML to our executable
target_link_libraries(RogueGame PRIVATE sfml-graphics sfml-window sfml-system)

# Include the "include" directory so we can use #include "header.h" cleanly
target_include_directories(RogueGame PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
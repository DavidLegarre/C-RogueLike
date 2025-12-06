
cmake_minimum_required(VERSION 3.28)

project(RogueClone VERSION 1.0.0 LANGUAGES CXX)

# Enforce C++ 17 (Good balance of features and compatibility)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SFML package installed via apt
# We request specific components: graphics, window, and system
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# ✅ THE NEW, AUTOMATIC WAY (Using globbing)
file(GLOB_RECURSE SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Now, add the executable using the automatically generated list
add_executable(RogueGame ${SOURCES})

target_link_libraries(RogueGame PRIVATE sfml-graphics sfml-window sfml-system)
target_include_directories(RogueGame PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
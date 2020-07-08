# Top-level cmake build script
cmake_minimum_required(VERSION 3.1...3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# use semantic versioning
project(
    PortAudioSandbox
    VERSION 0.1.0
    DESCRIPTION "Sandbox for testing C++ PortAudio"
    LANGUAGES CXX
)

# Create a var for the project specific include dir
# then add the dir to the compiler includes path
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/inc/port_audio_plus_plus)

# Ensure any cmake helpers / find lib x files are in the path
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# src contains lib files and apps contains main driver code
add_subdirectory(src)
add_subdirectory(apps)
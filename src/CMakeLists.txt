# src dir CMakeLists
cmake_minimum_required(VERSION 3.1...3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

find_package(portaudio REQUIRED)
find_package(Boost REQUIRED)

# convenience vars for src and includes
set(
    PAPP_SRC
    Audio.cpp
    AudioDevice.cpp
    AudioConfig.cpp
)

set(
    PAPP_HDR
    ${PROJECT_INCLUDE_DIR}/Audio.hpp
    ${PROJECT_INCLUDE_DIR}/AudioDevice.hpp
    ${PROJECT_INCLUDE_DIR}/AudioConfig.hpp
    ${PROJECT_INCLUDE_DIR}/PortAudioPlusPlus.hpp
)

# Build and link our main library
add_library(papp SHARED ${PAPP_SRC} ${PAPP_HDR})

target_link_libraries(papp PUBLIC portaudio)
target_include_directories(papp PUBLIC ${PROJECT_INCLUDE_DIR})
target_compile_features(papp PUBLIC cxx_std_17)
cmake_minimum_required(VERSION 3.14)
project(agsserialport VERSION 0.1.0 DESCRIPTION "Serial Port plugin for Adventure Game Studio.")

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    # WIN32 is set by CMake for any Windows platform
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(LINUX TRUE)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOS TRUE)
else()
    message(FATAL_ERROR "Unsupported system: ${CMAKE_SYSTEM_NAME}")
endif ()

include_directories(../ags/Engine/)
include_directories(../ags/Common/)

# include_directories(.)

add_library(agsserialport SHARED
    agsserialport/agsp_globalvars.h
    agsserialport/AgsNumberInterface.h
    agsserialport/SerializationHelper.h
    agsserialport/SerializationHelper.cpp
    agsserialport/agsserialport_ash.h
    agsserialport/agsserialport.cpp
    agsserialport/AgspSaneCheck.h
    agsserialport/AgspSaneCheck.cpp
    agsserialport/AgspPort.h
    agsserialport/AgspPort.cpp
    agsserialport/AgspPortConfig.h
    agsserialport/AgspPortConfig.cpp)
                
set_target_properties(agsserialport PROPERTIES CMAKE_CXX_VISIBILITY_PRESET hidden)


set(BUILD_SHARED_LIBS OFF CACHE BOOL "Shared (non-static) build")
set(BUILD_EXAMPLES OFF CACHE BOOL "Build examples")
set(BUILD_DOCS OFF CACHE BOOL "Build documentation")
add_subdirectory(agsserialport/libserialport/    EXCLUDE_FROM_ALL)

target_link_libraries(agsserialport serialport)

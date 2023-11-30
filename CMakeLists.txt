# -------------- CMAKE/PROJECT SETTINGS -------------- #

cmake_minimum_required(VERSION 3.21)

project(wlgen LANGUAGES CXX) #${CMAKE_PROJECT_NAME}

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_DEBUG_POSTFIX "d")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# -------------------- INCLUDES -------------------- #

#include (cmake/postbuild.cmake)
#include (cmake/default_source_groups.cmake)
#include (cmake/get_install_destination.cmake)
#include (cmake/ThirdPartyLibs.cmake)
#include (CMakePackageConfigHelpers)

# ----------------- LIBRARY TARGET ----------------- #

#set(LIB_TARGET YAML)

#add_library (${LIB_TARGET} STATIC)

#get_install_destination()

#if(INSTALL_DESTINATION)
#    set(CMAKE_INSTALL_PREFIX ${INSTALL_DESTINATION}/${LIB_TARGET})
#endif()

#set(INSTALL_INCLUDE_FOLDER include/${LIB_TARGET})

#message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

# --------------- EXECUTABLE --------------- #

add_executable(${CMAKE_PROJECT_NAME})


#include_directories(
#  ${CMAKE_CURRENT_SOURCE_DIR}/include
#  ${CMAKE_CURRENT_SOURCE_DIR}/src
#)

target_sources (${CMAKE_PROJECT_NAME}
    PRIVATE
        src/main.cpp
        src/wordlist.cpp
        src/wordlist.h
        src/options.cpp
        src/options.h
        src/resolver.cpp
        src/resolver.h
        src/bitflags.cpp
        src/bitflags.h
)

target_include_directories(${CMAKE_PROJECT_NAME}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

message(STATUS "CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

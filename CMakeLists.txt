# Madrigal Ascension - CMake Build Configuration
# Modern build system replacing legacy Visual Studio projects
# 
# Version: 1.0.0

cmake_minimum_required(VERSION 3.20)

# Project definition
project(MadrigalAscension
    VERSION 1.0.0
    DESCRIPTION "Madrigal Ascension - The Next Generation MMORPG"
    LANGUAGES CXX
)

# ============================================================================
# Project Configuration
# ============================================================================

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# ============================================================================
# Global Settings
# ============================================================================

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Compiler flags
if(MSVC)
    # MSVC specific flags
    add_compile_options(
        /W4                 # High warning level
        /WX-                # Don't treat warnings as errors (for now)
        /permissive-        # Disable non-conforming code
        /Zc:__cplusplus     # Enable proper __cplusplus macro
    )
    
    # Release optimizations
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        add_compile_options(/O2 /Ob2 /Ot)
    endif()
    
    # Debug settings
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(/Od /Zi)
        add_definitions(-DMADRIGAL_DEBUG=1)
    endif()
    
elseif(GCC OR CLANG)
    # GCC/Clang specific flags
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-parameter
    )
    
    # Release optimizations
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        add_compile_options(-O3 -flto)
    endif()
    
    # Debug settings
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-g -O0)
        add_definitions(-DMADRIGAL_DEBUG=1)
    endif()
endif()

# ============================================================================
# Platform Detection
# ============================================================================

if(WIN32)
    add_definitions(-DMADRIGAL_PLATFORM_WINDOWS=1)
    add_definitions(-D_WIN32_WINNT=0x0601)  # Windows 7+
    add_definitions(-DUNICODE -D_UNICODE)
elseif(UNIX AND NOT APPLE)
    add_definitions(-DMADRIGAL_PLATFORM_LINUX=1)
elseif(APPLE)
    add_definitions(-DMADRIGAL_PLATFORM_MACOS=1)
endif()

# ============================================================================
# Dependencies
# ============================================================================

# Find required packages
if(WIN32)
    # DirectX for Windows
    find_package(DirectX QUIET)
    if(DirectX_FOUND)
        add_definitions(-DMADRIGAL_USE_DIRECTX=1)
    endif()
endif()

# OpenGL for cross-platform
find_package(OpenGL)
if(OPENGL_FOUND)
    add_definitions(-DMADRIGAL_USE_OPENGL=1)
endif()

# Threading
find_package(Threads REQUIRED)

# ============================================================================
# Include Directories
# ============================================================================

# Global include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/Source
    ${CMAKE_SOURCE_DIR}/Config
    ${CMAKE_SOURCE_DIR}/Resource
    ${CMAKE_SOURCE_DIR}/Resource/MadrigalAscension
)

# Platform-specific includes
if(WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/External/Windows)
elseif(UNIX)
    include_directories(${CMAKE_SOURCE_DIR}/External/Linux)
endif()

# ============================================================================
# Source File Collections
# ============================================================================

# Client source files
set(MADRIGAL_CLIENT_SOURCES
    Source/MadrigalClient/MadrigalClient.cpp
    Source/MadrigalClient/MadrigalClient.h
)

# Server common sources
set(MADRIGAL_SERVER_COMMON_SOURCES
    Source/Servers/Common/ServerBase.cpp
    Source/Servers/Common/ServerBase.h
    Source/Servers/Common/NetworkManager.cpp
    Source/Servers/Common/NetworkManager.h
)

# World Server sources
set(MADRIGAL_WORLD_SERVER_SOURCES
    ${MADRIGAL_SERVER_COMMON_SOURCES}
    Source/Servers/WorldServer/MadrigalWorldServer_Simple.h
)

# Login Server sources  
set(MADRIGAL_LOGIN_SERVER_SOURCES
    ${MADRIGAL_SERVER_COMMON_SOURCES}
    Source/Servers/LoginServer/MadrigalLoginServer.h
)

# Database Server sources
set(MADRIGAL_DATABASE_SERVER_SOURCES
    ${MADRIGAL_SERVER_COMMON_SOURCES}
    Source/Servers/DatabaseServer/MadrigalDatabaseServer.h
)

# ============================================================================
# Executable Targets
# ============================================================================

# Madrigal Ascension Client
if(MADRIGAL_BUILD_CLIENT)
    add_executable(MadrigalClient ${MADRIGAL_CLIENT_SOURCES})
    
    target_compile_definitions(MadrigalClient PRIVATE
        MADRIGAL_CLIENT=1
        MADRIGAL_VERSION_MAJOR=1
        MADRIGAL_VERSION_MINOR=0
        MADRIGAL_VERSION_PATCH=0
    )
    
    if(WIN32)
        target_link_libraries(MadrigalClient
            user32.lib
            gdi32.lib
            winmm.lib
            ws2_32.lib
        )
        
        if(DirectX_FOUND)
            target_link_libraries(MadrigalClient ${DirectX_LIBRARIES})
        endif()
    endif()
    
    target_link_libraries(MadrigalClient Threads::Threads)
    
    set_target_properties(MadrigalClient PROPERTIES
        OUTPUT_NAME "MadrigalAscension"
        DEBUG_POSTFIX "_d"
    )
endif()

# World Server
if(MADRIGAL_BUILD_WORLD_SERVER)
    add_executable(WorldServer ${MADRIGAL_WORLD_SERVER_SOURCES})
    
    target_compile_definitions(WorldServer PRIVATE
        MADRIGAL_WORLD_SERVER=1
    )
    
    if(WIN32)
        target_link_libraries(WorldServer ws2_32.lib)
    endif()
    
    target_link_libraries(WorldServer Threads::Threads)
    
    set_target_properties(WorldServer PROPERTIES
        OUTPUT_NAME "MadrigalWorldServer"
        DEBUG_POSTFIX "_d"
    )
endif()

# Login Server
if(MADRIGAL_BUILD_LOGIN_SERVER)
    add_executable(LoginServer ${MADRIGAL_LOGIN_SERVER_SOURCES})
    
    target_compile_definitions(LoginServer PRIVATE
        MADRIGAL_LOGIN_SERVER=1
    )
    
    if(WIN32)
        target_link_libraries(LoginServer ws2_32.lib)
    endif()
    
    target_link_libraries(LoginServer Threads::Threads)
    
    set_target_properties(LoginServer PROPERTIES
        OUTPUT_NAME "MadrigalLoginServer"
        DEBUG_POSTFIX "_d"
    )
endif()

# Database Server
if(MADRIGAL_BUILD_DATABASE_SERVER)
    add_executable(DatabaseServer ${MADRIGAL_DATABASE_SERVER_SOURCES})
    
    target_compile_definitions(DatabaseServer PRIVATE
        MADRIGAL_DATABASE_SERVER=1
    )
    
    if(WIN32)
        target_link_libraries(DatabaseServer ws2_32.lib)
    endif()
    
    target_link_libraries(DatabaseServer Threads::Threads)
    
    set_target_properties(DatabaseServer PROPERTIES
        OUTPUT_NAME "MadrigalDatabaseServer"
        DEBUG_POSTFIX "_d"
    )
endif()

# ============================================================================
# Build Options
# ============================================================================

# Build configuration options
option(MADRIGAL_BUILD_CLIENT "Build Madrigal Ascension Client" ON)
option(MADRIGAL_BUILD_WORLD_SERVER "Build World Server" ON)
option(MADRIGAL_BUILD_LOGIN_SERVER "Build Login Server" ON)
option(MADRIGAL_BUILD_DATABASE_SERVER "Build Database Server" ON)
option(MADRIGAL_BUILD_CORE_SERVER "Build Core Server" ON)

# Feature options
option(MADRIGAL_ENABLE_MULTITHREADING "Enable multi-threading support" ON)
option(MADRIGAL_ENABLE_MODERN_GRAPHICS "Enable modern graphics features" ON)
option(MADRIGAL_ENABLE_ANTI_CHEAT "Enable anti-cheat system" ON)
option(MADRIGAL_ENABLE_AI_ASSISTANT "Enable AI assistant (Phase 6)" OFF)

# Development options
option(MADRIGAL_BUILD_TESTS "Build unit tests" OFF)
option(MADRIGAL_BUILD_TOOLS "Build development tools" OFF)
option(MADRIGAL_ENABLE_PROFILING "Enable performance profiling" OFF)

# ============================================================================
# Feature Configuration
# ============================================================================

if(MADRIGAL_ENABLE_MULTITHREADING)
    add_definitions(-DMADRIGAL_ENABLE_MULTITHREADING=1)
endif()

if(MADRIGAL_ENABLE_MODERN_GRAPHICS)
    add_definitions(-DMADRIGAL_USE_DIRECTX11=1)
endif()

if(MADRIGAL_ENABLE_ANTI_CHEAT)
    add_definitions(-DMADRIGAL_ENABLE_ANTICHEAT=1)
endif()

if(MADRIGAL_ENABLE_AI_ASSISTANT)
    add_definitions(-DMADRIGAL_ENABLE_AI_ASSISTANT=1)
endif()

# ============================================================================
# Installation
# ============================================================================

# Install client
if(MADRIGAL_BUILD_CLIENT)
    install(TARGETS MadrigalClient
        RUNTIME DESTINATION bin
        COMPONENT Client
    )
endif()

# Install servers
if(MADRIGAL_BUILD_WORLD_SERVER)
    install(TARGETS WorldServer
        RUNTIME DESTINATION server
        COMPONENT Server
    )
endif()

# Install configuration files
install(DIRECTORY Config/
    DESTINATION config
    FILES_MATCHING PATTERN "*.h" PATTERN "*.cfg" PATTERN "*.ini"
    COMPONENT Configuration
)

# Install resources
install(DIRECTORY Resource/MadrigalAscension/
    DESTINATION data
    FILES_MATCHING PATTERN "*.inc" PATTERN "*.txt"
    COMPONENT GameData
)

# ============================================================================
# Package Configuration
# ============================================================================

set(CPACK_PACKAGE_NAME "MadrigalAscension")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Madrigal Ascension - The Next Generation MMORPG")
set(CPACK_PACKAGE_VENDOR "Madrigal Ascension Studio")

if(WIN32)
    set(CPACK_GENERATOR "ZIP;NSIS")
    set(CPACK_NSIS_DISPLAY_NAME "Madrigal Ascension")
    set(CPACK_NSIS_PACKAGE_NAME "MadrigalAscension")
elseif(UNIX)
    set(CPACK_GENERATOR "TGZ;DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Madrigal Ascension Team")
endif()

include(CPack)

# ============================================================================
# Status Information
# ============================================================================

message(STATUS "========================================")
message(STATUS "Madrigal Ascension Build Configuration")
message(STATUS "========================================")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Platform: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "")
message(STATUS "Build Targets:")
message(STATUS "  Client: ${MADRIGAL_BUILD_CLIENT}")
message(STATUS "  World Server: ${MADRIGAL_BUILD_WORLD_SERVER}")
message(STATUS "  Login Server: ${MADRIGAL_BUILD_LOGIN_SERVER}")
message(STATUS "  Database Server: ${MADRIGAL_BUILD_DATABASE_SERVER}")
message(STATUS "")
message(STATUS "Features:")
message(STATUS "  Multi-threading: ${MADRIGAL_ENABLE_MULTITHREADING}")
message(STATUS "  Modern Graphics: ${MADRIGAL_ENABLE_MODERN_GRAPHICS}")
message(STATUS "  Anti-cheat: ${MADRIGAL_ENABLE_ANTI_CHEAT}")
message(STATUS "  AI Assistant: ${MADRIGAL_ENABLE_AI_ASSISTANT}")
message(STATUS "========================================")

# ============================================================================
# Legacy Compatibility Notice
# ============================================================================

message(STATUS "")
message(STATUS "Legacy Flyff/Neuz compatibility mode enabled")
message(STATUS "This will be removed in Madrigal Ascension v2.0")
message(STATUS "")
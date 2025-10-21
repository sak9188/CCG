cmake_minimum_required(VERSION 3.16)

# Prefer clang on Linux, MSVC on Windows (default)
if(NOT CMAKE_C_COMPILER AND NOT CMAKE_CXX_COMPILER)
  if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux" OR CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "No compiler specified, defaulting to clang/clang++ on Linux")
    set(CMAKE_C_COMPILER clang CACHE STRING "" FORCE)
    set(CMAKE_CXX_COMPILER clang++ CACHE STRING "" FORCE)
  endif()
endif()

project(CCG LANGUAGES C CXX)

# Global project settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
  add_compile_options(/permissive- /W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_subdirectory(CCG)

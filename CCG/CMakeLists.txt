# CCG Engine and App

set(CCG_ENGINE_SOURCES
  CGGGame.cpp
  WINEventActor.cpp
  arena.cpp
  cardStack.cpp
  charactor.cpp
  gameObject.cpp
  gameround.cpp
  media.cpp
  profession.cpp
  recorder.cpp
  scene.cpp
  sceneItem.cpp
)

set(CCG_APP_SOURCES
  CCG.cpp
)

# Try to locate SDL2 and SDL2_image in a robust cross-platform way
# 1) Prefer CMake package config (e.g., from vcpkg/official packages)
# 2) Fallback to CMake Find modules
# 3) Fallback to pkg-config

# SDL2
set(_sdl2_found FALSE)
find_package(SDL2 CONFIG QUIET)
if(TARGET SDL2::SDL2)
  set(_sdl2_found TRUE)
  set(SDL2_LIBRARIES SDL2::SDL2)
  # SDL2main is optional depending on platform
  if(TARGET SDL2::SDL2main)
    list(APPEND SDL2_LIBRARIES SDL2::SDL2main)
  endif()
elseif(NOT _sdl2_found)
  find_package(SDL2 QUIET)
  if(SDL2_FOUND)
    set(_sdl2_found TRUE)
    # Legacy FindSDL2.cmake variables
    set(SDL2_LIBRARIES ${SDL2_LIBRARIES})
    set(SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIRS})
  endif()
endif()

if(NOT _sdl2_found)
  find_package(PkgConfig QUIET)
  if(PKG_CONFIG_FOUND)
    pkg_check_modules(PC_SDL2 QUIET sdl2)
    if(PC_SDL2_FOUND)
      set(_sdl2_found TRUE)
      set(SDL2_INCLUDE_DIRS ${PC_SDL2_INCLUDE_DIRS})
      set(SDL2_LIBRARIES ${PC_SDL2_LIBRARIES})
    endif()
  endif()
endif()

if(NOT _sdl2_found)
  message(FATAL_ERROR "SDL2 not found. Please install SDL2 development files or provide a CMake toolchain with SDL2.")
endif()

# SDL2_image
set(_sdl2_image_found FALSE)
find_package(SDL2_image CONFIG QUIET)
if(TARGET SDL2::SDL2_image)
  set(_sdl2_image_found TRUE)
  set(SDL2_IMAGE_LIBRARIES SDL2::SDL2_image)
elseif(NOT _sdl2_image_found)
  find_package(SDL2_image QUIET)
  if(SDL2_IMAGE_FOUND)
    set(_sdl2_image_found TRUE)
    set(SDL2_IMAGE_INCLUDE_DIRS ${SDL2_IMAGE_INCLUDE_DIRS})
    set(SDL2_IMAGE_LIBRARIES ${SDL2_IMAGE_LIBRARIES})
  endif()
endif()

if(NOT _sdl2_image_found)
  find_package(PkgConfig QUIET)
  if(PKG_CONFIG_FOUND)
    pkg_check_modules(PC_SDL2_IMAGE QUIET SDL2_image)
    if(PC_SDL2_IMAGE_FOUND)
      set(_sdl2_image_found TRUE)
      set(SDL2_IMAGE_INCLUDE_DIRS ${PC_SDL2_IMAGE_INCLUDE_DIRS})
      set(SDL2_IMAGE_LIBRARIES ${PC_SDL2_IMAGE_LIBRARIES})
    endif()
  endif()
endif()

if(NOT _sdl2_image_found)
  message(FATAL_ERROR "SDL2_image not found. Please install SDL2_image development files or provide a CMake toolchain with SDL2_image.")
endif()

# Engine library
add_library(ccg_engine ${CCG_ENGINE_SOURCES})

# Public include directories for engine
# The code uses headers relative to this folder and subfolders
# so expose them as PUBLIC include paths

target_include_directories(ccg_engine
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/card
    ${CMAKE_CURRENT_SOURCE_DIR}/enum
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
)

# Link SDL2 libraries
# Note: SDL2_LIBRARIES may be a list of imported targets or plain library paths
# target_link_libraries can handle both

target_link_libraries(ccg_engine
  PUBLIC
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
)

# App executable
add_executable(ccg_app ${CCG_APP_SOURCES})

# On Windows, prefer the WIN32 subsystem to avoid a console if using SDL2main
if(WIN32)
  # Nothing special here; keeping console by default helps with logging
endif()

# Link engine + SDL2 to the app (transitively provided by the engine)

target_link_libraries(ccg_app PRIVATE ccg_engine)

# Ensure the runtime can find asset files (images)
# Copy the img folder next to the built executable
add_custom_command(TARGET ccg_app POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
          ${CMAKE_CURRENT_SOURCE_DIR}/img
          $<TARGET_FILE_DIR:ccg_app>/img)

# Nice grouping in IDEs
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CCG_ENGINE_SOURCES} ${CCG_APP_SOURCES})

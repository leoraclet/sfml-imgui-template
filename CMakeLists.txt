cmake_minimum_required(VERSION 3.31)

# Project name This will be used as the executable name and the CMake project name.
project(example)

# C++ compile flags Windows uses MSVC, while Linux and macOS use GCC/Clang
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
endif()

# Directories Set the directories for ImGUI, SFML, and other libraries
set(IMGUI_SRC_DIR libs/imgui)
set(LIB_SFML_PATH libs/sfml)
set(LIB_DIR libs)
set(INCLUDE_DIR includes)
set(SRC_DIR src)
set(BUILD_SHARED_LIBS ON)

# Load OpenGL
set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)

# Load SFML with provided path to the SFML libraries
find_package(
    SFML 2.6.1 COMPONENTS REQUIRED
    system
    window
    graphics
    PATHS ${LIB_SFML_PATH}
)

# Load source and header files
# This will search for all .cpp files in the src directory and all .hpp files in the includes directory
# and store them in the SOURCES and HEADERS variables respectively.
# You can also specify individual files if you prefer.
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${INCLUDE_DIR}/*.hpp)

# Load ImGUI src files
set(
    IMGUI_LIB_SRC
    ${IMGUI_SRC_DIR}/imgui.cpp
    ${IMGUI_SRC_DIR}/imgui_draw.cpp
    ${IMGUI_SRC_DIR}/imgui_tables.cpp
    ${IMGUI_SRC_DIR}/imgui_widgets.cpp
    ${IMGUI_SRC_DIR}/imgui-SFML.cpp
)

# Load GLAD and STB src files
set(
    LIBS_SRC
    ${LIB_DIR}/stb/stb_image.cpp
    ${LIB_DIR}/glad/src/glad.c
)

# Include directories
include_directories(
    ${LIB_DIR}
    ${INCLUDE_DIR}
    ${LIB_DIR}/glad/include
)

# Executable
add_executable(
    ${CMAKE_PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${LIBS_SRC}
    ${IMGUI_LIB_SRC}
)

# Include directory to target
target_include_directories(
    ${CMAKE_PROJECT_NAME} PRIVATE
    ${IMGUI_SRC_DIR}
)

# Link libraries to target
target_link_libraries(
    ${CMAKE_PROJECT_NAME} PRIVATE
    sfml-system
    sfml-window
    sfml-graphics
    dl
    ${OPENGL_LIBRARY}
)

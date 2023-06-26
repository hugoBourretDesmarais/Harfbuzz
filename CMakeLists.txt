cmake_minimum_required(VERSION 3.10)
project(your_project_name VERSION 1.0)

set(CMAKE_OSX_ARCHITECTURES arm64)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# List all source files
set(SOURCES main.cpp TextShapingPerformanceTester.cpp FontHandler.cpp Renderer.cpp)

# Define the executable with source files
add_executable(main ${SOURCES})

# Include directories (use relative paths)
target_include_directories(main PRIVATE 
    ${PROJECT_SOURCE_DIR}/harfbuzz/src
    /opt/homebrew/Cellar/freetype/2.13.0_1/include/freetype2
)

# Link directories 
link_directories(
    ${PROJECT_SOURCE_DIR}/harfbuzz/build/src
    /opt/homebrew/Cellar/freetype/2.13.0_1/lib
    /usr/local/lib
    /usr/local/include
)

# Find and link Harfbuzz library
find_library(HARFBUZZ_LIBRARY NAMES harfbuzz PATHS ${PROJECT_SOURCE_DIR}/harfbuzz/build/src)
if(HARFBUZZ_LIBRARY)
    target_link_libraries(main ${HARFBUZZ_LIBRARY})
else()
    message(FATAL_ERROR "Harfbuzz library not found")
endif()

# Find and link FreeType library
find_library(FREETYPE_LIBRARY NAMES freetype PATHS /opt/homebrew/Cellar/freetype/2.13.0_1/lib)
if(FREETYPE_LIBRARY)
    target_link_libraries(main ${FREETYPE_LIBRARY})
else()
    message(FATAL_ERROR "FreeType library not found")
endif()

# Find and link OpenGL library
find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
    target_include_directories(main PRIVATE ${OPENGL_INCLUDE_DIRS})
    target_link_libraries(main ${OPENGL_LIBRARIES})
else()
    message(FATAL_ERROR "OpenGL library not found")
endif()

# Find and link GLEW library
find_library(GLEW_LIBRARY NAMES GLEW GLEWmx PATHS /usr/local/opt/glew/lib)
if(NOT GLEW_LIBRARY)
    message(FATAL_ERROR "GLEW library not found")
endif()

target_include_directories(main PRIVATE /usr/local/opt/glew/include)
target_link_libraries(main ${GLEW_LIBRARY})


# Find and link GLFW library
find_library(GLFW_LIBRARY NAMES glfw3 PATHS /usr/local/lib)
if(NOT GLFW_LIBRARY)
    message(FATAL_ERROR "GLFW library not found")
endif()

target_include_directories(main PRIVATE /usr/local/include)
target_link_libraries(main ${GLFW_LIBRARY})

# Find CoreFoundation library
find_library(COREFOUNDATION_LIBRARY CoreFoundation)
if(NOT COREFOUNDATION_LIBRARY)
    message(FATAL_ERROR "CoreFoundation library not found")
endif()

# Link CoreFoundation library
target_link_libraries(main ${COREFOUNDATION_LIBRARY})

# Find CoreGraphics library
find_library(COREGRAPHICS_LIBRARY CoreGraphics)
if(NOT COREGRAPHICS_LIBRARY)
    message(FATAL_ERROR "CoreGraphics library not found")
endif()

# Link CoreGraphics library
target_link_libraries(main ${COREGRAPHICS_LIBRARY})

# Find IOKit library
find_library(IOKIT_LIBRARY IOKit)
if(NOT IOKIT_LIBRARY)
    message(FATAL_ERROR "IOKit library not found")
endif()

# Link IOKit library
target_link_libraries(main ${IOKIT_LIBRARY})

# Find Cocoa library
find_library(COCOA_LIBRARY Cocoa)
if(NOT COCOA_LIBRARY)
    message(FATAL_ERROR "Cocoa library not found")
endif()

# Link Cocoa library
target_link_libraries(main ${COCOA_LIBRARY})


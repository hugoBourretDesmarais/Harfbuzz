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

# Link directories (use relative paths)
link_directories(
    ${PROJECT_SOURCE_DIR}/harfbuzz/build/src
    /opt/homebrew/Cellar/freetype/2.13.0_1/lib
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

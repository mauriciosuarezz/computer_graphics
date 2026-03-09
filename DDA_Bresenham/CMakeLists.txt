cmake_minimum_required(VERSION 3.10)
project(LineAlgorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/graphics)

# Define the executables
add_executable(dda_master dda_master.cpp)
add_executable(bresenham_master bresenham_master.cpp)

# Include the graphics directory for headers
target_include_directories(dda_master PRIVATE ${CMAKE_SOURCE_DIR}/graphics)
target_include_directories(bresenham_master PRIVATE ${CMAKE_SOURCE_DIR}/graphics)

# Common libraries to link
set(GRAPHICS_LIBS
    ${CMAKE_SOURCE_DIR}/graphics/libbgi.a
    gdi32 
    comdlg32 
    uuid 
    oleaut32 
    ole32
    -static-libgcc
    -static-libstdc++
)

# Link the WinBGIM library and required Windows libraries
target_link_libraries(dda_master ${GRAPHICS_LIBS})
target_link_libraries(bresenham_master ${GRAPHICS_LIBS})

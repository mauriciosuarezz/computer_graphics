cmake_minimum_required(VERSION 3.10)
project(LineAlgorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Usamos una variable para la ruta de la librería para que sea más legible
set(BGI_LIB_PATH "${CMAKE_SOURCE_DIR}/graphics/libbgi.a")

# 2. Definir los ejecutables
add_executable(dda_master dda_master.cpp)
add_executable(bresenham_master bresenham_master.cpp)

# 3. Incluir cabeceras (Usamos INTERFACE para que sea más limpio)
target_include_directories(dda_master PRIVATE "${CMAKE_SOURCE_DIR}/graphics")
target_include_directories(bresenham_master PRIVATE "${CMAKE_SOURCE_DIR}/graphics")

# 4. Configuración de librerías
# Nota: He movido los flags estáticos a una configuración separada
set(GRAPHICS_LIBS 
    "${BGI_LIB_PATH}"
    gdi32 
    comdlg32 
    uuid 
    oleaut32 
    ole32
)

# 5. Enlace de librerías
target_link_libraries(dda_master PRIVATE ${GRAPHICS_LIBS})
target_link_libraries(bresenham_master PRIVATE ${GRAPHICS_LIBS})

# 6. Forzar enlace estático (Para que el .exe funcione sin depender de DLLs de MSYS2)
target_link_options(dda_master PRIVATE -static-libgcc -static-libstdc++ -static)
target_link_options(bresenham_master PRIVATE -static-libgcc -static-libstdc++ -static)
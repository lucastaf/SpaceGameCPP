cmake_minimum_required(VERSION 3.10)
project(SpaceGameCPP LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# Diretórios principais
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(RAYLIB_DIR "C:/raylib/raylib_msvc") # <- ajuste se necessário

# Arquivos
file(GLOB_RECURSE SRCS      "${SRC_DIR}/*.cpp")
file(GLOB_RECURSE HDRS      "${SRC_DIR}/*.hpp")
file(GLOB_RECURSE INC_HDRS  "${INCLUDE_DIR}/*.hpp")

# Organiza no Visual Studio pelas pastas reais
source_group(TREE ${CMAKE_SOURCE_DIR} FILES 
    ${SRCS} 
    ${HDRS} 
    ${INC_HDRS}
    main.cpp
)

# Executável
add_executable(SpaceGameCPP 
    main.cpp 
    ${SRCS} 
    ${HDRS}
    ${INC_HDRS}
)

# Inclui headers internos
target_include_directories(SpaceGameCPP PRIVATE ${INCLUDE_DIR})

# Inclui headers do raylib (MSVC) 
target_include_directories(SpaceGameCPP PRIVATE "${RAYLIB_DIR}/include" ) 
# Link com raylib compilado para MSVC 
target_link_directories(SpaceGameCPP PRIVATE "${RAYLIB_DIR}/lib" )

cmake_minimum_required(VERSION 3.10)
project(SpaceGameCPP)

# Lista de fontes
set(SOURCES
    main.cpp
)

add_executable(SpaceGameCPP ${SOURCES})

# Adiciona a pasta include ao include path
target_include_directories(SpaceGameCPP
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
cmake_minimum_required(VERSION 3.16)

project(ChessEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ChessEngine
    src/main.cpp
    src/Board.cpp
    src/Attacks.cpp
    src/moveGen.cpp
)
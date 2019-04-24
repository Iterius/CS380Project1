cmake_minimum_required(VERSION 3.12.2)

project(CS380Proj1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project1 main.cpp CRandom.cpp CPlayer.cpp CDominoes.cpp CTable.cpp)

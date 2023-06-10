cmake_minimum_required(VERSION 3.24)
project(Chinpokomon)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chinpokomon main.cpp monster.cpp monster.h trainer.cpp trainer.h selectMonster.h item.cpp item.h)

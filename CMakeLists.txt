cmake_minimum_required(VERSION 3.24)
project(Chinpokomon)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chinpokomon main.cpp monster.cpp monster.h trainer.cpp trainer.h selectMonster.h item.cpp item.h arena.cpp arena.h selectArena.cpp selectArena.h skill.cpp skill.h skillpool.cpp skillpool.h)

target_compile_options(Chinpokomon PRIVATE -std=c++11)

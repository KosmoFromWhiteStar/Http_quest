cmake_minimum_required(VERSION 3.25)

set(PATH ${CMAKE_SOURCE_DIR}/incl)

add_executable(Http_quest main.cpp ${PATH}/exs.h)
target_include_directories(Http_quest PUBLIC ${PATH})
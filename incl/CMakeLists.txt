cmake_minimum_required(VERSION 3.25)
#Include HTTP li
project(lib LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(lib exs.h cpr::cpr)
target_link_libraries(lib PRIVATE cpr::cpr)
set_target_properties(lib PROPERTIES LINKER_LANGUAGE CXX)



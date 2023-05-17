cmake_minimum_required(VERSION 3.25)
project(Http_quest LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG fc4241a4e15b04b061b85bb9054554587a772b11)
FetchContent_MakeAvailable(cpr)

add_subdirectory(src)
add_subdirectory(incl)

target_link_libraries(Http_quest PRIVATE lib)
target_link_libraries(Http_quest PRIVATE cpr::cpr)







cmake_minimum_required(VERSION 3.10)

project(gosu-quad-test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(extern/gosu)

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE GOSUTEST_SOURCE_FILES src/*.cpp)
file(GLOB_RECURSE GOSUTEST_HEADER_FILES src/*.hpp)
add_executable(gosu-quad-test
    ${GOSUTEST_SOURCE_FILES}
    ${GOSUTEST_HEADER_FILES}
)
target_link_libraries(gosu-quad-test Gosu::Gosu OpenGL::GL SDL2)
set_target_properties(gosu-quad-test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

cmake_minimum_required(VERSION 3.10)
project(TridiagonalSolver)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(TridiagonalSolver main.cpp)

target_link_libraries(TridiagonalSolver PRIVATE tridiagonal_solver)

add_executable(TridiagonalSolverTest test.cpp)

target_link_libraries(TridiagonalSolverTest PRIVATE tridiagonal_solver)

target_include_directories(TridiagonalSolverTest PRIVATE ${CMAKE_SOURCE_DIR}/src)

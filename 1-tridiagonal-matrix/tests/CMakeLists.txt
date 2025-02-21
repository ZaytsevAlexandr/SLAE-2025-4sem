add_executable(TridiagonalSolverTest test.cpp)

# Подключаем библиотеку tridiagonal_solver
target_link_libraries(TridiagonalSolverTest PRIVATE tridiagonal_solver)

# Добавляем include-директорию src
target_include_directories(TridiagonalSolverTest PRIVATE ${CMAKE_SOURCE_DIR}/src)

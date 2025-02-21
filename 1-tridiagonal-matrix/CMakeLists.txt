cmake_minimum_required(VERSION 3.10)
project(TridiagonalSolver)

set(CMAKE_CXX_STANDARD 14)

# Добавляем поддиректории с исходниками и тестами
add_subdirectory(src)
add_subdirectory(tests)

# Создаём исполняемый файл для основной программы
add_executable(TridiagonalSolver main.cpp)

# Подключаем библиотеку из src
target_link_libraries(TridiagonalSolver PRIVATE tridiagonal_solver)

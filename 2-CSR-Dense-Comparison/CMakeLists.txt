cmake_minimum_required(VERSION 3.10)
project(MatrixOperations)

set(CMAKE_CXX_STANDARD 17)

add_executable(matrix_operations 
    main.cpp
    DenseMatrix.cpp
    CSRMatrix.cpp
    benchmark.cpp
)

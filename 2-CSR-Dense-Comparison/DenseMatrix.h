#ifndef DENSE_MATRIX_H
#define DENSE_MATRIX_H

#include <vector>
#include <stdexcept>

class DenseMatrix {
private:
    std::vector<std::vector<double>> data;
    size_t rows, cols;

public:
    DenseMatrix(size_t rows, size_t cols);
    
    double& operator()(size_t i, size_t j);
    double operator()(size_t i, size_t j) const;
    
    size_t getRows() const;
    size_t getCols() const;

    // Операции
    DenseMatrix operator+(const DenseMatrix& other) const;
    std::vector<double> operator*(const std::vector<double>& vec) const;
};

#endif

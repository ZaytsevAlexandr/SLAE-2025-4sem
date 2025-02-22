#include "DenseMatrix.h"

DenseMatrix::DenseMatrix(size_t rows, size_t cols)
    : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {}

double& DenseMatrix::operator()(size_t i, size_t j) {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[i][j];
}

double DenseMatrix::operator()(size_t i, size_t j) const {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[i][j];
}

size_t DenseMatrix::getRows() const { return rows; }
size_t DenseMatrix::getCols() const { return cols; }

DenseMatrix DenseMatrix::operator+(const DenseMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Sizes don't match. Try again.");
    }
    
    DenseMatrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] + other(i, j);
        }
    }
    return result;
}

std::vector<double> DenseMatrix::operator*(const std::vector<double>& vec) const {
    if (cols != vec.size()) {
        throw std::invalid_argument("Sizes don't match. Try again.");
    }

    std::vector<double> result(rows, 0.0);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[i] += data[i][j] * vec[j];
        }
    }
    return result;
}

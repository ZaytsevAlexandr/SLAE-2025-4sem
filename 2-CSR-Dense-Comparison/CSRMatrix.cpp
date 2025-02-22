#include "CSRMatrix.h"

CSRMatrix::CSRMatrix(size_t rows, size_t cols)
    : rows(rows), cols(cols), row_ptr(rows + 1, 0) {}

void CSRMatrix::addElement(size_t i, size_t j, double value) {
    values.push_back(value);
    columns.push_back(j);
    row_ptr[i + 1]++;
}

void CSRMatrix::finalize() {
    for (size_t i = 1; i <= rows; ++i) {
        row_ptr[i] += row_ptr[i - 1];
    }
}

double CSRMatrix::operator()(size_t i, size_t j) const {
    for (size_t idx = row_ptr[i]; idx < row_ptr[i + 1]; ++idx) {
        if (columns[idx] == j) {
            return values[idx];
        }
    }
    return 0.0;
}

size_t CSRMatrix::getRows() const { return rows; }
size_t CSRMatrix::getCols() const { return cols; }

std::vector<double> CSRMatrix::operator*(const std::vector<double>& vec) const {
    if (cols != vec.size()) {
        throw std::invalid_argument("Sizes don't match. Try again.");
    }

    std::vector<double> result(rows, 0.0);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t idx = row_ptr[i]; idx < row_ptr[i + 1]; ++idx) {
            result[i] += values[idx] * vec[columns[idx]];
        }
    }
    return result;
}

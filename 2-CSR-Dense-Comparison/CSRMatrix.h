#ifndef CSR_MATRIX_H
#define CSR_MATRIX_H

#include <vector>
#include <stdexcept>

class CSRMatrix {
private:
    std::vector<double> values;
    std::vector<size_t> columns;
    std::vector<size_t> row_ptr;
    size_t rows, cols;

public:
    CSRMatrix(size_t rows, size_t cols);

    void addElement(size_t i, size_t j, double value);
    void finalize();

    double operator()(size_t i, size_t j) const;
    size_t getRows() const;
    size_t getCols() const;

    std::vector<double> operator*(const std::vector<double>& vec) const;
};

#endif

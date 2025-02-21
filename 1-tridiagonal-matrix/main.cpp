#include <iostream>
#include <vector>
#include "tridiagonal_solver.h"

int main() {
    size_t n;
    std::cout << "Введите размер матрицы: ";
    std::cin >> n;

    std::vector<double> a(n), b(n), c(n), d(n);

    std::cout << "Введите верхнюю диагональ (c): ";
    for (size_t i = 0; i < n - 1; ++i) std::cin >> c[i];

    std::cout << "Введите центральную диагональ (b): ";
    for (size_t i = 0; i < n; ++i) std::cin >> b[i];

    std::cout << "Введите нижнюю диагональ (a): ";
    for (size_t i = 1; i < n; ++i) std::cin >> a[i];

    std::cout << "Введите правую часть (d): ";
    for (size_t i = 0; i < n; ++i) std::cin >> d[i];

    std::vector<double> x = TridiagonalSolver::solve(a, b, c, d);

    std::cout << "Решение: ";
    for (double xi : x) std::cout << xi << " ";
    std::cout << std::endl;

    return 0;
}
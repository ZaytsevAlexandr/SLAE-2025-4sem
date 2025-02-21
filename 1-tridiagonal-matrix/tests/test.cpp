#include <iostream>
#include <vector>
#include "../src/tridiagonal_solver.h"

void testTridiagonalSolver() {
    std::vector<double> a = {0, 1, 1};  // Нижняя диагональ
    std::vector<double> b = {2, 2, 2};  // Центральная диагональ
    std::vector<double> c = {1, 1, 0};  // Верхняя диагональ
    std::vector<double> d = {1, 1, 1};  // Правая часть

    std::vector<double> x = TridiagonalSolver::solve(a, b, c, d);

    std::cout << "Тестовое решение: ";
    for (double xi : x) std::cout << xi << " ";
    std::cout << std::endl;
}

int main() {
    testTridiagonalSolver();
    return 0;
}
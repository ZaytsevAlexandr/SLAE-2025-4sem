#include "tridiagonal_solver.h"
#include <vector>

std::vector<double> TridiagonalSolver::solve(const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d) {
    std::size_t n = b.size();
    std::vector<double> alpha(n), beta(n), x(n);

    // Прямой ход
    alpha[0] = -c[0] / b[0];
    beta[0] = d[0] / b[0];
    for (std::size_t i = 1; i < n - 1; ++i) {
        double denominator = b[i] + a[i] * alpha[i - 1];
        alpha[i] = -c[i] / denominator;
        beta[i] = (d[i] - a[i] * beta[i - 1]) / denominator;
    }
    beta[n - 1] = (d[n - 1] - a[n - 1] * beta[n - 2]) / (b[n - 1] + a[n - 1] * alpha[n - 2]);

    // Обратный ход
    x[n - 1] = beta[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        x[i] = alpha[i] * x[i + 1] + beta[i];
    }

    return x;
}
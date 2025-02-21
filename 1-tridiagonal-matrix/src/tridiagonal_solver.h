#ifndef TRIDIAGONAL_SOLVER_H
#define TRIDIAGONAL_SOLVER_H

#include <vector>

class TridiagonalSolver {
public:
    static std::vector<double> solve(const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d);
};

#endif // TRIDIAGONAL_SOLVER_H
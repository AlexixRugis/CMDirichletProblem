#include "SeidelSolver.h"
#include "Problem.h"

#include <vector>
#include <algorithm>

namespace CMDirichlet {
    DiricletProblemSolution SeidelSolver::solve(const DirichletProblem& problem) {
        const auto n = problem.n();
        const auto m = problem.m();

        std::vector<double> grid((n + 1) * (m + 1), 0.0);

        for (size_t j = 1; j < m; j++) {
            grid[j] = problem.mu1(problem.y(j));
        }

        for (size_t j = 1; j < m; j++) {
            size_t offset = n * (m + 1);
            grid[offset + j] = problem.mu1(problem.y(j));
        }

        for (size_t i = 1; i < n; i++) {
            grid[i * (m + 1)] = problem.mu3(problem.x(i));
        }

        for (size_t i = 1; i < n; i++) {
            grid[i * (m + 1) + m] = problem.mu4(problem.x(i));
        }

        const double inv_h2 = 1.0 / (problem.h() * problem.h());
        const double inv_k2 = 1.0 / (problem.k() * problem.k());
        const double A = -2.0 * (inv_h2 + inv_k2);
        const double neg_inv_A = -1.0 / A;

        // vij = -1/A(1/h2 * vi-1j + 1/k2 * vij-1 + 1/h2 * vi+1j + 1/k2 * vij+1 + fij)
        size_t iter = 0;
        double eps_n = std::numeric_limits<double>::max();
        double r_norm = 0.0;

        for (; iter < maxN() && eps_n > eps(); iter++) {

            eps_n = 0.0;

            for (size_t i = 1; i < n; i++) {
                for (size_t j = 1; j < m; j++) {
                    double old_val = grid[i * (m + 1) + j];

                    grid[i * (m + 1) + j] = neg_inv_A * (
                        inv_h2 * (grid[(i - 1) * (m + 1) + j] + grid[(i + 1) * (m + 1) + j]) +
                        inv_k2 * (grid[i * (m + 1) + j - 1] + grid[i * (m + 1) + j + 1]));

                    eps_n = std::max(eps_n, std::abs(grid[i * (m + 1) + j] - old_val));
                }
            }
        }

        return DiricletProblemSolution{
            iter,
            eps_n,
            r_norm,
            grid
        };
    }
}
#include "SeidelSolver.h"
#include "Problem.h"

#include <vector>
#include <algorithm>

namespace CMDirichlet {
    DiricletProblemSolution SeidelSolver::solve(const DirichletProblem& problem) {
        const auto n = problem.n();
        const auto m = problem.m();

        std::vector<double> grid((n + 1) * (m + 1), 0.0);
        std::vector<double> f((n + 1) * (m + 1), 0.0);

        for (size_t j = 0; j <= m; j++) {
            for (size_t i = 0; i <= n; i++) {
                f[j * (n + 1) + i] = problem.f(problem.x(i), problem.y(j));
            }
        }

        for (size_t j = 0; j <= m; j++) {
            grid[j * (n + 1)] = problem.mu1(problem.y(j));
        }

        for (size_t j = 0; j <= m; j++) {
            grid[j * (n + 1) + n] = problem.mu2(problem.y(j));
        }

        for (size_t i = 1; i < n; i++) {
            grid[i] = problem.mu3(problem.x(i));
        }

        for (size_t i = 1; i < n; i++) {
            size_t offset = m * (n + 1);
            grid[offset + i] = problem.mu4(problem.x(i));
        }

        double x_diff_inv = 1.0 / (problem.b() - problem.a());
        for (size_t j = 1; j < m; j++) {
            double y = problem.y(j);
            double mu1_y = problem.mu1(y);
            double mu2_y = problem.mu2(y);

            for (size_t i = 1; i < n; i++) {
                double x = problem.x(i);
                double t = (x - problem.a()) * x_diff_inv;
                grid[j * (n + 1) + i] = mu1_y * (1.0 - t) + mu2_y * t;
            }
        }

        const double inv_h2 = 1.0 / (problem.h() * problem.h());
        const double inv_k2 = 1.0 / (problem.k() * problem.k());
        const double neg_A = 2.0 * (inv_h2 + inv_k2);
        const double neg_inv_A = 1.0 / neg_A;

        double r0_norm = 0.0;
        for (size_t j = 1; j < m; j++) {
            for (size_t i = 1; i < n; i++) {
                size_t row_offset = (n + 1);
                size_t index = j * row_offset + i;
                double r =
                    inv_h2 * (grid[index - 1] - 2.0 * grid[index] + grid[index + 1]) +
                    inv_k2 * (grid[index - row_offset] - 2.0 * grid[index] + grid[index + row_offset]) +
                    f[index];
                r0_norm = std::max(r0_norm, r);
            }
        }

        // vij = -1/A(1/h2 * vi-1j + 1/k2 * vij-1 + 1/h2 * vi+1j + 1/k2 * vij+1 + fij)
        size_t iter = 0;
        double eps_n = std::numeric_limits<double>::max();

        for (; iter < maxN() && eps_n > eps(); iter++) {

            eps_n = 0.0;

            for (size_t j = 1; j < m; j++) {
                for (size_t i = 1; i < n; i++) {
                    double old_val = grid[j * (n + 1) + i];

                    size_t row_offset = (n + 1);
                    size_t index = j * row_offset + i;
                    grid[index] =
                        inv_h2 * (grid[index - 1] + grid[index + 1]) +
                        inv_k2 * (grid[index - row_offset] + grid[index + row_offset]);
                    grid[index] += f[index];
                    grid[index] *= neg_inv_A;

                    eps_n = std::max(eps_n, std::abs(grid[index] - old_val));
                }
            }
        }

        double r_norm = 0.0;
        for (size_t j = 1; j < m; j++) {
            for (size_t i = 1; i < n; i++) {
                size_t row_offset = (n + 1);
                size_t index = j * row_offset + i;
                double r =
                    inv_h2 * (grid[index - 1] - 2.0 * grid[index] + grid[index + 1]) +
                    inv_k2 * (grid[index - row_offset] - 2.0 * grid[index] + grid[index + row_offset]) +
                    f[index];
                r_norm = std::max(r_norm, r);
            }
        }

        return DiricletProblemSolution{
            iter,
            eps_n,
            r_norm,
            grid,
            r0_norm
        };
    }
}
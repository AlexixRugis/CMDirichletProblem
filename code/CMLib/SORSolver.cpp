#include "SORSolver.h"
#include "Problem.h"

#include <vector>
#include <algorithm>
#include <limits>

namespace CMDirichlet {
    DiricletProblemSolution SORSolver::solve(const DirichletProblem& problem) {
        const auto n = problem.n();
        const auto m = problem.m();
        const size_t stride = n + 1;

        std::vector<double> grid((n + 1) * (m + 1), 0.0);
        std::vector<double> f((n + 1) * (m + 1), 0.0);

        for (size_t j = 0; j <= m; j++) {
            for (size_t i = 0; i <= n; i++) {
                f[j * stride + i] = problem.f(problem.x(i), problem.y(j));
            }
        }

        for (size_t j = 0; j <= m; j++) {
            grid[j * stride] = problem.mu1(problem.y(j));
        }

        for (size_t j = 0; j <= m; j++) {
            grid[j * stride + n] = problem.mu2(problem.y(j));
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
                grid[j * stride + i] = mu1_y * (1.0 - t) + mu2_y * t;
            }
        }

        const double inv_h2 = 1.0 / (problem.h() * problem.h());
        const double inv_k2 = 1.0 / (problem.k() * problem.k());
        const double neg_A = 2.0 * (inv_h2 + inv_k2);
        const double neg_inv_A = 1.0 / neg_A;

        double r0_norm = 0.0;
        for (size_t j = 1; j < m; j++) {
            for (size_t i = 1; i < n; i++) {
                size_t index = j * stride + i;
                double r =
                    inv_h2 * (grid[index - 1] - 2.0 * grid[index] + grid[index + 1]) +
                    inv_k2 * (grid[index - stride] - 2.0 * grid[index] + grid[index + stride]) +
                    f[index];
                r0_norm = std::max(r0_norm, r);
            }
        }

        std::vector<double> diagStorage((n + m + 1) * (n + 1));
        std::vector<double> fDiagStorage((n + m + 1) * (n + 1));

        for (size_t d = 0; d <= n + m; d++) {
            size_t i_max = std::min(n, d);
            for (size_t i = 0; i <= i_max; i++) {
                size_t j = d - i;
                if (j <= m) {
                    diagStorage[d * stride + i] = grid[j * stride + i];
                    fDiagStorage[d * stride + i] = f[j * stride + i];
                }
            }
        }

        // vij = -1/A * ((1-w)(-A)*vij + w(inv_h2*(vi-1j+vi+1j) + invk2*(vij-1+vij+1) + f))

        size_t iter = 0;
        double eps_n = std::numeric_limits<double>::max();
        const  double eps_stop = eps();
        const  size_t max_iter = maxN();

        const double* fPtr = fDiagStorage.data();
        double* dPtr = diagStorage.data();

        for (; iter < max_iter && eps_n > eps_stop; ++iter) {
            eps_n = 0.0;

            for (size_t d = 2; d <= n + m - 2; ++d) {

                const size_t i_lo = (d > m - 1) ? (d - (m - 1)) : 1;
                const size_t i_hi = std::min(d - 1, n - 1);
                if (i_lo > i_hi) [[unlikely]] continue;

                const double* fCur = fPtr + d * stride;
                const double* prev = dPtr + (d - 1) * stride;
                double* cur = dPtr + d * stride;
                const double* next = dPtr + (d + 1) * stride;

                double local_eps = 0.0;

                for (size_t i = i_lo; i <= i_hi; ++i) {
                    const size_t j = d - i;
                    const double old = cur[i];

                    double v =
                        (1.0 - w()) * neg_A * cur[i] + w() * (
                            inv_h2 * (prev[i - 1] + next[i + 1]) +
                            inv_k2 * (prev[i] + next[i]) +
                            fCur[i]
                            );
                    v *= neg_inv_A;

                    cur[i] = v;
                    double diff = v - old;
                    if (diff < 0) diff = -diff;
                    if (diff > local_eps) local_eps = diff;
                }

                if (local_eps > eps_n) eps_n = local_eps;
            }
        }

        for (size_t d = 0; d <= n + m; d++) {
            size_t i_max = std::min(n, d);
            for (size_t i = 0; i <= i_max; i++) {
                size_t j = d - i;
                if (j <= m) {
                    grid[j * stride + i] = diagStorage[d * stride + i];
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
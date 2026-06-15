#pragma once

namespace CMDirichlet {
    class DirichletProblem;
    struct DiricletProblemSolution;

    class SeidelSolver {
    public:
        SeidelSolver(size_t maxN, double eps) : m_MaxN(maxN), m_Eps(eps) {}

        size_t maxN() const { return m_MaxN; }
        double eps() const { return m_Eps; }

        DiricletProblemSolution solve(const DirichletProblem& problem);

    private:
        size_t m_MaxN;
        double m_Eps;
    };
}

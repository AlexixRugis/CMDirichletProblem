#pragma once

namespace CMDirichlet {
    class DirichletProblem;
    struct DiricletProblemSolution;

    class SORSolver {
    public:
        SORSolver(size_t maxN, double eps, double w) : m_MaxN(maxN), m_Eps(eps), m_W(w) {}

        size_t maxN() const { return m_MaxN; }
        double eps() const { return m_Eps; }
        double w() const { return m_W; }

        DiricletProblemSolution solve(const DirichletProblem& problem);

    private:
        size_t m_MaxN;
        double m_Eps;
        double m_W;
    };
}

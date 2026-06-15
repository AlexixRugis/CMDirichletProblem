#pragma once

#include <utility>
#include <vector>
#include <cstddef>
#include <functional>

namespace CMDirichlet {
    class DirichletProblem {
    public:

        using f_xy_t = std::function<double(double,double)>;
        using mu_xy_t = std::function<double(double, double)>;

        DirichletProblem(
            size_t n, size_t m, double a, double b, double c, double d,
            f_xy_t f, mu_xy_t mu1, mu_xy_t mu2, mu_xy_t mu3, mu_xy_t mu4) :
            m_N(n), m_M(m), m_A(a), m_B(b), m_C(c), m_D(d),
            m_F(f), m_Mu1(mu1), m_Mu2(mu2), m_Mu3(mu3), m_Mu4(mu4), m_H((b - a) / n), m_K((d - c) / m) {
        }

        size_t n() const { return m_N; }
        size_t m() const { return m_M; }

        double a() const { return m_A; }
        double b() const { return m_B; }
        double c() const { return m_C; }
        double d() const { return m_D; }

        double h() const { return m_H; }
        double k() const { return m_K; }

        double x(size_t i) const { return m_A + m_H * i; }
        double y(size_t j) const { return m_C + m_K * j; }

        std::pair<double, double> point(size_t i, size_t j) const {
            return { x(i), y(j) };
        }

        double mu1(double y) const { return m_Mu1(y, m_A); }
        double mu2(double y) const { return m_Mu2(y, m_B); }
        double mu3(double x) const { return m_Mu3(x, m_C); }
        double mu4(double x) const { return m_Mu4(x, m_D); }

        double f(double x, double y) const { return m_F(x, y); }

    private:
        size_t m_N;
        size_t m_M;
        double m_A;
        double m_B;
        double m_C;
        double m_D;

        double m_H;
        double m_K;

        f_xy_t m_F;
        mu_xy_t m_Mu1;
        mu_xy_t m_Mu2;
        mu_xy_t m_Mu3;
        mu_xy_t m_Mu4;
    };

    struct DiricletProblemSolution {
        size_t n;
        double eps;
        double r_norm;
        std::vector<double> v;
        double r0_norm;
    };
}

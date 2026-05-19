#include "Functions.h"
#include <cmath>

namespace CMDirichlet {
    double func_f_main(double x, double y) {
        return abs(x * x - y * y);
    }
    double func_mu1_main(double y) {
        return -y * y + 1.0;
    }
    double func_mu2_main(double y) {
        return (1.0 - y * y) * exp(y);
    }
    double func_mu3_main(double x) {
        return 1 - x * x;
    }
    double func_mu4_main(double x) {
        return 1 - x * x;
    }

    double func_u_test(double x, double y) {
        return exp(1 - x * x - y * y);
    }
    double func_f_test(double x, double y) {
        return -4.0 * (x * x + y * y - 1.0) * func_u_test(x, y);
    }
    double func_mu1_test(double y, double a) {
        return exp(1.0 - a * a - y * y);
    }
    double func_mu2_test(double y, double b) {
        return exp(1.0 - b * b - y * y);
    }
    double func_mu3_test(double x, double c) {
        return exp(1.0 - x * x - c * c);
    }
    double func_mu4_test(double x, double d) {
        return exp(1.0 - x * x - d * d);
    }
}
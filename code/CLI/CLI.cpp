#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <stdexcept>

#include "Functions.h"
#include "Problem.h"
#include "SeidelSolver.h"
#include "SORSolver.h"

using namespace CMDirichlet;

// ===================================================================
// Чтение INI-файла
// ===================================================================
using IniMap = std::map<std::string, std::string>;

IniMap read_ini(const std::string& path) {
    IniMap cfg;
    std::ifstream f(path);
    if (!f.is_open())
        throw std::runtime_error("Не удалось открыть файл: " + path);

    std::string line;
    while (std::getline(f, line)) {
        // Убираем пробелы и комментарии
        auto it = std::find(line.begin(), line.end(), '#');
        if (it != line.end()) line.erase(it, line.end());
        if (line.empty()) continue;

        auto eq = line.find('=');
        if (eq == std::string::npos) continue;

        std::string key = line.substr(0, eq);
        std::string value = line.substr(eq + 1);

        // trim
        auto trim = [](std::string& s) {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isspace(c); }));
            s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !std::isspace(c); }).base(), s.end());
            };
        trim(key); trim(value);
        std::replace(value.begin(), value.end(), ',', '.');

        cfg[key] = value;
    }
    return cfg;
}

double get_double(const IniMap& cfg, const std::string& key, double def = 0.0) {
    auto it = cfg.find(key);
    if (it == cfg.end()) return def;
    return std::stod(it->second);
}

size_t get_size(const IniMap& cfg, const std::string& key, size_t def = 0) {
    auto it = cfg.find(key);
    if (it == cfg.end()) return def;
    return static_cast<size_t>(std::stoull(it->second));
}

std::string get_str(const IniMap& cfg, const std::string& key, const std::string& def = "") {
    auto it = cfg.find(key);
    return (it == cfg.end()) ? def : it->second;
}

// ===================================================================
// Вспомогательные функции вывода
// ===================================================================
void write_table(std::ofstream& out,
    const std::string& title,
    size_t n, size_t m,
    double a, double b, double c, double d,
    const std::vector<double>& sol,
    int prec = 6) {
    double h = (b - a) / n;
    double k = (d - c) / m;

    out << "\n=== " << title << " ===\n";

    // Шапка: x-значения
    out << std::setw(14) << "y \\ x";
    for (size_t i = 0; i <= n; i++)
        out << std::setw(prec + 8) << std::fixed << std::setprecision(4) << (a + i * h);
    out << "\n";

    // Строки: j -> y_j, потом значения
    for (size_t j = 0; j <= m; j++) {
        double yj = c + j * k;
        out << std::setw(14) << std::fixed << std::setprecision(4) << yj;
        for (size_t i = 0; i <= n; i++) {
            double val = sol[j * (n + 1) + i];
            out << std::setw(prec + 8) << std::scientific << std::setprecision(prec) << val;
        }
        out << "\n";
    }
}

// ===================================================================
// Решатель (аналог GUI-метода Solve)
// ===================================================================
DiricletProblemSolution run_solver(const DirichletProblem& problem,
    size_t nmax, double epsn, double w,
    int method_idx,   // 0=Seidel, 1=SOR
    double& time_secs) {
    auto t0 = std::chrono::high_resolution_clock::now();

    DiricletProblemSolution solution;
    if (method_idx == 0) {
        SeidelSolver solver(nmax, epsn);
        solution = solver.solve(problem);
    }
    else {
        SORSolver solver(nmax, epsn, w);
        std::cout << w << std::endl;
        solution = solver.solve(problem);
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    time_secs = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() * 1e-3;
    return solution;
}

// ===================================================================
// Задача 0 — тестовая
// ===================================================================
void solve_test(const IniMap& cfg, std::ofstream& out) {
    size_t n = get_size(cfg, "n", 10);
    size_t m = get_size(cfg, "m", 10);
    size_t nmax = get_size(cfg, "nmax", 20000);
    double a = get_double(cfg, "a", -1.0);
    double b = get_double(cfg, "b", 1.0);
    double c = get_double(cfg, "c", -1.0);
    double d = get_double(cfg, "d", 1.0);
    double epsn = get_double(cfg, "epsn", 1e-9);
    double w = get_double(cfg, "w", 1.8);
    int    meth = std::stoi(get_str(cfg, "method", "0")); // 0=Seidel,1=SOR

    DirichletProblem problem(n, m, a, b, c, d,
        func_f_test,
        func_mu1_test, func_mu2_test,
        func_mu3_test, func_mu4_test);

    double time_secs = 0.0;
    const auto solution = run_solver(problem, nmax, epsn, w, meth, time_secs);
    const auto& v = solution.v;

    // Точное решение u
    std::vector<double> u(v.size(), 0.0);
    std::vector<double> diff(v.size(), 0.0);
    double eps_1 = 0.0, eps_x = 0.0, eps_y = 0.0;

    double h = (b - a) / n;
    double k = (d - c) / m;

    for (size_t j = 0; j <= m; j++) {
        double yj = c + j * k;
        for (size_t i = 0; i <= n; i++) {
            double xi = a + i * h;
            size_t idx = j * (n + 1) + i;
            u[idx] = func_u_test(xi, yj);
            diff[idx] = u[idx] - v[idx];
            if (std::abs(diff[idx]) > eps_1) {
                eps_1 = std::abs(diff[idx]);
                eps_x = xi;
                eps_y = yj;
            }
        }
    }

    // --- Сводка в файл ---
    out << "========================================\n";
    out << "  ТЕСТОВАЯ ЗАДАЧА\n";
    out << "========================================\n";
    out << "Сетка:              n=" << n << ", m=" << m << "\n";
    out << "Метод:              " << (meth == 0 ? "Зейдель" : "МВР (SOR)") << "\n";
    if (meth == 1) out << "  w = " << w << "\n";
    out << "eps_мет:            " << std::scientific << epsn << "\n";
    out << "Nmax:               " << nmax << "\n";
    out << "----------------------------------------\n";
    out << "Итераций N:         " << solution.n << "\n";
    out << "eps(N):             " << std::scientific << solution.eps << "\n";
    out << "||R(0)||:           " << std::scientific << solution.r0_norm << "\n";
    out << "||R(N)||:           " << std::scientific << solution.r_norm << "\n";
    out << "Норма невязки:      max\n";
    out << "Начальное прибл.:   интерполяция по x\n";
    out << "----------------------------------------\n";
    out << "Погрешность eps_1:  " << std::scientific << eps_1 << "\n";
    out << "Макс. отклонение:   x=" << eps_x << ", y=" << eps_y << "\n";
    out << "Время решения:      " << std::fixed << std::setprecision(3) << time_secs << " с\n";

    // --- Таблицы ---
    write_table(out, "v*(x,y) — численное решение", n, m, a, b, c, d, v);
    write_table(out, "u*(x,y) — точное решение", n, m, a, b, c, d, u);
    write_table(out, "u* - v* — погрешность", n, m, a, b, c, d, diff);

    // --- Консоль ---
    std::cout << "[Тестовая] N=" << solution.n
        << "  eps(N)=" << std::scientific << solution.eps
        << "  eps_1=" << eps_1
        << "  t=" << std::fixed << std::setprecision(3) << time_secs << "с\n";
}

// ===================================================================
// Задача 1 — основная (с сеткой половинного шага)
// ===================================================================
void solve_main(const IniMap& cfg, std::ofstream& out) {
    size_t n = get_size(cfg, "n", 10);
    size_t m = get_size(cfg, "m", 10);
    size_t nmax = get_size(cfg, "nmax", 20000);
    double a = get_double(cfg, "a", -1.0);
    double b = get_double(cfg, "b", 1.0);
    double c = get_double(cfg, "c", -1.0);
    double d = get_double(cfg, "d", 1.0);
    double epsn = get_double(cfg, "epsn", 1e-9);
    double eps2n = get_double(cfg, "eps2n", 1e-11);
    double w = get_double(cfg, "w", 1.8);
    double w2 = get_double(cfg, "w2", 1.9);
    int    meth = std::stoi(get_str(cfg, "method", "0"));

    DirichletProblem problem(n, m, a, b, c, d,
        func_f_main,
        func_mu1_main, func_mu2_main,
        func_mu3_main, func_mu4_main);

    DirichletProblem problem2(2 * n, 2 * m, a, b, c, d,
        func_f_main,
        func_mu1_main, func_mu2_main,
        func_mu3_main, func_mu4_main);

    double t1 = 0.0, t2 = 0.0;
    const auto sol1 = run_solver(problem, nmax, epsn, w, meth, t1);
    const auto sol2 = run_solver(problem2, nmax, eps2n, w2, meth, t2);

    const auto& v = sol1.v;
    const auto& v2 = sol2.v;

    std::vector<double> diff(sol1.v.size(), 0.0);
    double eps_1 = 0.0, eps_x = 0.0, eps_y = 0.0;

    double h = (b - a) / n;
    double k = (d - c) / m;

    for (size_t j = 0; j <= m; j++) {
        double yj = c + j * k;
        for (size_t i = 0; i <= n; i++) {
            double xi = a + i * h;
            size_t idx = j * (n + 1) + i;
            size_t idx2 = 2 * j * (2 * n + 1) + 2 * i;
            diff[idx] = v[idx] - v2[idx2];
            if (std::abs(diff[idx]) > eps_1) {
                eps_1 = std::abs(diff[idx]);
                eps_x = xi;
                eps_y = yj;
            }
        }
    }

    // --- Сводка ---
    out << "========================================\n";
    out << "  ОСНОВНАЯ ЗАДАЧА\n";
    out << "========================================\n";
    out << "Сетка:              n=" << n << ", m=" << m << "\n";
    out << "Метод:              " << (meth == 0 ? "Зейдель" : "МВР (SOR)") << "\n";
    if (meth == 1) out << "  w=" << w << ", w2=" << w2 << "\n";
    out << "eps_мет:            " << std::scientific << epsn << "\n";
    out << "eps2_мет:           " << std::scientific << eps2n << "\n";
    out << "Nmax:               " << nmax << "\n";
    out << "----------------------------------------\n";
    out << "  [Основная сетка n=" << n << "]\n";
    out << "Итераций N:         " << sol1.n << "\n";
    out << "eps(N):             " << std::scientific << sol1.eps << "\n";
    out << "||R(0)||:           " << std::scientific << sol1.r0_norm << "\n";
    out << "||R(N)||:           " << std::scientific << sol1.r_norm << "\n";
    out << "Время:              " << std::fixed << std::setprecision(3) << t1 << " с\n";
    out << "----------------------------------------\n";
    out << "  [Сетка половинного шага n=" << 2 * n << "]\n";
    out << "Итераций N2:        " << sol2.n << "\n";
    out << "eps(N2):            " << std::scientific << sol2.eps << "\n";
    out << "||R2(0)||:          " << std::scientific << sol2.r0_norm << "\n";
    out << "||R(N2)||:          " << std::scientific << sol2.r_norm << "\n";
    out << "Время:              " << std::fixed << std::setprecision(3) << t2 << " с\n";
    out << "----------------------------------------\n";
    out << "Точность eps2:      " << std::scientific << eps_1 << "\n";
    out << "Макс. отклонение:   x=" << eps_x << ", y=" << eps_y << "\n";
    out << "Норма невязки:      max\n";
    out << "Начальное прибл.:   интерполяция по x\n";
    out << "Суммарное время:    " << std::fixed << std::setprecision(3) << (t1 + t2) << " с\n";

    // --- Таблицы на основной сетке ---
    write_table(out, "v(x,y)  — основная сетка", n, m, a, b, c, d, v);

    // v2 на основной сетке (каждый 2-й узел)
    std::vector<double> v2_coarse(sol1.v.size());
    for (size_t j = 0; j <= m; j++)
        for (size_t i = 0; i <= n; i++)
            v2_coarse[j * (n + 1) + i] = v2[2 * j * (2 * n + 1) + 2 * i];

    write_table(out, "v2(x,y) — сетка половинного шага (в узлах основной)", n, m, a, b, c, d, v2_coarse);
    write_table(out, "v - v2  — разность", n, m, a, b, c, d, diff);

    // --- Консоль ---
    std::cout << "[Основная] N=" << sol1.n
        << "  eps(N)=" << std::scientific << sol1.eps
        << "  N2=" << sol2.n
        << "  eps2=" << eps_1
        << "  t=" << std::fixed << std::setprecision(3) << (t1 + t2) << "с\n";
}

// ===================================================================
// main
// ===================================================================
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "");
    setlocale(LC_NUMERIC, "C");

    if (argc < 3) {
        std::cerr << "Использование: " << argv[0] << " <input.ini> <output.txt>\n\n"
            << "Пример input.ini:\n"
            << "  problem = 0        # 0 - тестовая, 1 - основная\n"
            << "  a = -1.0\n"
            << "  b =  1.0\n"
            << "  c = -1.0\n"
            << "  d =  1.0\n"
            << "  n = 10\n"
            << "  m = 10\n"
            << "  nmax = 20000\n"
            << "  epsn  = 1e-9\n"
            << "  eps2n = 1e-11\n"
            << "  method = 0         # 0 - Зейдель, 1 - МВР/SOR\n"
            << "  w  = 1.8\n"
            << "  w2 = 1.9\n";
        return 1;
    }

    const std::string input_path = argv[1];
    const std::string output_path = argv[2];

    IniMap cfg;
    try {
        cfg = read_ini(input_path);
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка чтения входного файла: " << e.what() << "\n";
        return 1;
    }

    // Валидация
    double a = get_double(cfg, "a", -1), b = get_double(cfg, "b", 1);
    double c = get_double(cfg, "c", -1), d = get_double(cfg, "d", 1);
    double epsn = get_double(cfg, "epsn", 1e-9);
    double eps2n = get_double(cfg, "eps2n", 1e-11);
    double w = get_double(cfg, "w", 1.8);
    double w2 = get_double(cfg, "w2", 1.9);
    size_t n = get_size(cfg, "n", 10);
    size_t m = get_size(cfg, "m", 10);
    size_t nm = get_size(cfg, "nmax", 20000);
    int meth = std::stoi(get_str(cfg, "method", "0"));
    int prob = std::stoi(get_str(cfg, "problem", "0"));

    if (a >= b || c >= d) { std::cerr << "Ошибка: a<b и c<d обязательны\n"; return 1; }
    if (n == 0 || m == 0 || nm == 0) { std::cerr << "Ошибка: n, m, nmax > 0\n"; return 1; }
    if (epsn <= 0 || eps2n <= 0) { std::cerr << "Ошибка: eps > 0\n"; return 1; }
    if (meth == 1 && (w <= 0 || w >= 2 || w2 <= 0 || w2 >= 2)) {
        std::cerr << "Ошибка: w и w2 должны быть в (0,2) для SOR\n"; return 1;
    }

    std::ofstream out(output_path);
    if (!out.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл для записи: " << output_path << "\n";
        return 1;
    }

    std::cout << "Входной файл:  " << input_path << "\n";
    std::cout << "Выходной файл: " << output_path << "\n";
    std::cout << "Задача: " << (prob == 0 ? "тестовая" : "основная")
        << ", метод: " << (meth == 0 ? "Зейдель" : "SOR") << "\n\n";

    try {
        if (prob == 0)
            solve_test(cfg, out);
        else
            solve_main(cfg, out);
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка вычисления: " << e.what() << "\n";
        return 1;
    }

    out.close();
    std::cout << "\nГотово. Результаты записаны в " << output_path << "\n";
    return 0;
}

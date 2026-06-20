#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
visualize_report.py
====================

Парсит текстовые отчёты, генерируемые CLI.cpp (решатели Зейделя / SOR
для задачи Дирихле), и строит 3D-графики (surface plots) для каждой
найденной в отчёте таблицы вида:

    === Название таблицы ===
             y \\ x       -1.0000       -0.9875  ...
           -1.0000  0.000000e+00  2.484375e-02  ...
           -0.9875  2.484375e-02  4.778201e-02  ...
           ...

Использование:
    python visualize_report.py report1.txt [report2.txt ...] [-o output_dir]
    python visualize_report.py report1.txt --html      # интерактивные .html (plotly)
    python visualize_report.py report1.txt --combine    # все таблицы на одной фигуре

Зависимости:
    numpy, matplotlib (обязательно)
    plotly (опционально, для --html)
"""

import argparse
import os
import re
import sys

import numpy as np


# ===================================================================
# Парсинг отчёта
# ===================================================================

TABLE_HEADER_RE = re.compile(r"^===\s*(.+?)\s*===\s*$")


def parse_report(path):
    """
    Читает текстовый отчёт и извлекает из него все таблицы.

    Возвращает список словарей:
        {
            "title": str,
            "x": np.ndarray (n+1,),
            "y": np.ndarray (m+1,),
            "z": np.ndarray (m+1, n+1),
        }
    """
    with open(path, "r", encoding="utf-8-sig", errors="replace") as f:
        lines = f.readlines()

    tables = []
    i = 0
    n_lines = len(lines)

    while i < n_lines:
        m = TABLE_HEADER_RE.match(lines[i].strip())
        if not m:
            i += 1
            continue

        title = m.group(1)
        i += 1

        # Пропускаем пустые строки перед шапкой
        while i < n_lines and not lines[i].strip():
            i += 1
        if i >= n_lines:
            break

        # Строка шапки: "y \ x   x0   x1   x2 ..."
        header_tokens = lines[i].split()
        # Первые токены — это "y", "\", "x" (или похожее), отбрасываем
        # их и берём всё, что парсится как float, начиная с конца, где
        # начинаются числа.
        x_values = []
        for tok in header_tokens:
            tok_norm = tok.replace(",", ".")
            try:
                x_values.append(float(tok_norm))
            except ValueError:
                continue
        i += 1

        # Строки данных: первое число — y, остальные — значения z
        y_values = []
        rows = []
        while i < n_lines:
            raw = lines[i]
            stripped = raw.strip()
            if not stripped:
                break
            tokens = stripped.split()
            tok_norm = [t.replace(",", ".") for t in tokens]
            try:
                nums = [float(t) for t in tok_norm]
            except ValueError:
                break
            if len(nums) < 2:
                break
            y_values.append(nums[0])
            rows.append(nums[1:])
            i += 1

        if not rows or not x_values:
            continue

        ncols = len(x_values)
        # Подгоняем длину строк (на случай переноса строк в очень
        # широких таблицах) — обрезаем/дополняем NaN при несовпадении.
        z = np.full((len(rows), ncols), np.nan, dtype=float)
        for r_idx, row in enumerate(rows):
            take = min(len(row), ncols)
            z[r_idx, :take] = row[:take]

        tables.append({
            "title": title,
            "x": np.array(x_values, dtype=float),
            "y": np.array(y_values, dtype=float),
            "z": z,
        })

    return tables


def safe_filename(s):
    s = s.strip()
    s = re.sub(r"[^\w\-]+", "_", s, flags=re.UNICODE)
    s = re.sub(r"_+", "_", s).strip("_")
    return s or "table"


# ===================================================================
# Matplotlib backend (статичные PNG)
# ===================================================================

def plot_matplotlib(table, out_path, cmap="viridis", elev=35, azim=-60):
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    from mpl_toolkits.mplot3d import Axes3D  # noqa: F401

    X, Y = np.meshgrid(table["x"], table["y"])
    Z = table["z"]

    fig = plt.figure(figsize=(11, 8))
    ax = fig.add_subplot(111, projection="3d")
    surf = ax.plot_surface(
        X, Y, Z,
        cmap=cmap,
        linewidth=0,
        antialiased=True,
        rstride=max(1, X.shape[0] // 80),
        cstride=max(1, X.shape[1] // 80),
    )
    ax.set_xlabel("x")
    ax.set_ylabel("y")
    ax.set_zlabel("значение")
    ax.set_title(table["title"], fontsize=12)
    ax.view_init(elev=elev, azim=azim)
    fig.colorbar(surf, shrink=0.6, aspect=12, pad=0.08)
    fig.tight_layout()
    fig.savefig(out_path, dpi=150)
    plt.close(fig)


def plot_matplotlib_combined(tables, out_path, cmap="viridis"):
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    from mpl_toolkits.mplot3d import Axes3D  # noqa: F401

    n = len(tables)
    ncols = min(3, n)
    nrows = (n + ncols - 1) // ncols

    fig = plt.figure(figsize=(6 * ncols, 5 * nrows))
    for idx, table in enumerate(tables, start=1):
        ax = fig.add_subplot(nrows, ncols, idx, projection="3d")
        X, Y = np.meshgrid(table["x"], table["y"])
        Z = table["z"]
        surf = ax.plot_surface(
            X, Y, Z,
            cmap=cmap,
            linewidth=0,
            antialiased=True,
            rstride=max(1, X.shape[0] // 60),
            cstride=max(1, X.shape[1] // 60),
        )
        ax.set_xlabel("x")
        ax.set_ylabel("y")
        ax.set_zlabel("значение")
        ax.set_title(table["title"], fontsize=10)
        fig.colorbar(surf, shrink=0.5, aspect=10, pad=0.1)

    fig.tight_layout()
    fig.savefig(out_path, dpi=150)
    plt.close(fig)


# ===================================================================
# Plotly backend (интерактивные HTML)
# ===================================================================

def plot_plotly(table, out_path, colorscale="Viridis"):
    import plotly.graph_objects as go

    fig = go.Figure(data=[go.Surface(
        x=table["x"], y=table["y"], z=table["z"],
        colorscale=colorscale,
        colorbar=dict(title="значение"),
    )])
    fig.update_layout(
        title=table["title"],
        scene=dict(
            xaxis_title="x",
            yaxis_title="y",
            zaxis_title="значение",
        ),
        margin=dict(l=10, r=10, t=50, b=10),
    )
    fig.write_html(out_path, include_plotlyjs="cdn")


# ===================================================================
# main
# ===================================================================

def main():
    parser = argparse.ArgumentParser(
        description="Визуализация таблиц из отчётов CLI.cpp в виде 3D-графиков."
    )
    parser.add_argument("reports", nargs="+", help="Путь(и) к текстовому отчёту (.txt)")
    parser.add_argument("-o", "--outdir", default="plots", help="Папка для сохранения графиков (по умолчанию: plots)")
    parser.add_argument("--html", action="store_true", help="Сохранять интерактивные .html графики (через plotly) вместо .png")
    parser.add_argument("--combine", action="store_true", help="Собрать все таблицы одного отчёта в одну фигуру (только для PNG)")
    parser.add_argument("--cmap", default="viridis", help="Цветовая карта matplotlib (по умолчанию viridis)")
    args = parser.parse_args()

    os.makedirs(args.outdir, exist_ok=True)

    for report_path in args.reports:
        if not os.path.isfile(report_path):
            print(f"[!] Файл не найден: {report_path}", file=sys.stderr)
            continue

        tables = parse_report(report_path)
        if not tables:
            print(f"[!] В файле {report_path} не найдено ни одной таблицы.", file=sys.stderr)
            continue

        base_name = os.path.splitext(os.path.basename(report_path))[0]
        print(f"[{report_path}] найдено таблиц: {len(tables)}")

        if args.html:
            for table in tables:
                fname = f"{base_name}__{safe_filename(table['title'])}.html"
                out_path = os.path.join(args.outdir, fname)
                plot_plotly(table, out_path)
                print(f"    -> {out_path}")
        elif args.combine:
            out_path = os.path.join(args.outdir, f"{base_name}__combined.png")
            plot_matplotlib_combined(tables, out_path, cmap=args.cmap)
            print(f"    -> {out_path}")
        else:
            for table in tables:
                fname = f"{base_name}__{safe_filename(table['title'])}.png"
                out_path = os.path.join(args.outdir, fname)
                plot_matplotlib(table, out_path, cmap=args.cmap)
                print(f"    -> {out_path}")

    print("Готово.")


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
trim_report_tables.py
======================

Берёт текстовые отчёты, генерируемые CLI.cpp (формат с таблицами вида
"=== Название ===" + шапка "y \\ x ..." + строки данных), и обрезает
каждую таблицу: оставляет только края (по 10 элементов слева/справа
и сверху/снизу), а вырезанную середину заменяет на одно "...".

Обрезаются:
  - шапка таблицы (строка x-значений)   -> 10 слева + ... + 10 справа
  - строки данных (по y)                -> 10 сверху + ... + 10 снизу
  - в каждой оставшейся строке данных    -> 10 слева + ... + 10 справа

Если элементов (столбцов или строк) <= 20, обрезка не производится —
строка/столбец остаётся как есть.

Всё остальное содержимое отчёта (сводки, заголовки, текст до и между
таблицами) копируется без изменений.

Использование:
    python trim_report_tables.py report1.txt [report2.txt ...] [-o output_dir]
    python trim_report_tables.py report1.txt -o trimmed --edge 10
    python trim_report_tables.py report1.txt --suffix _trimmed   # пишет report1_trimmed.txt рядом

По умолчанию обрезанные файлы сохраняются в папку "trimmed/" с тем же именем.
"""

import argparse
import os
import re
import sys


TABLE_HEADER_RE = re.compile(r"^===\s*(.+?)\s*===\s*$")
ELLIPSIS = "..."


def is_number_token(tok):
    tok = tok.replace(",", ".")
    try:
        float(tok)
        return True
    except ValueError:
        return False


def trim_tokens(tokens, edge):
    """
    Обрезает список строковых токенов (чисел), оставляя по `edge` штук
    с каждой стороны и заменяя середину на один ELLIPSIS, если токенов
    больше 2*edge. Иначе возвращает токены без изменений.
    """
    n = len(tokens)
    if n <= 2 * edge:
        return tokens
    return tokens[:edge] + [ELLIPSIS] + tokens[-edge:]


def trim_header_line(line, edge):
    """
    Обрезает шапку таблицы: "   y \\ x   x0   x1   x2 ... xn".
    Сохраняет ведущую часть до начала числовых токенов нетронутой,
    обрезает только последовательность x-значений.
    """
    tokens = line.split()

    # Находим индекс первого токена, который парсится как число —
    # с этого момента начинаются x-значения.
    first_num_idx = None
    for i, tok in enumerate(tokens):
        if is_number_token(tok):
            first_num_idx = i
            break

    if first_num_idx is None:
        # Не похоже на шапку с числами — оставляем как есть.
        return line

    prefix_tokens = tokens[:first_num_idx]
    x_tokens = tokens[first_num_idx:]
    trimmed_x = trim_tokens(x_tokens, edge)

    return " ".join(prefix_tokens + trimmed_x) + "\n"


def trim_data_line(line, edge):
    """
    Обрезает строку данных: "   y_j   v0   v1   v2 ... vn".
    Первый токен (y_j) сохраняется, оставшиеся значения обрезаются.
    """
    tokens = line.split()
    if not tokens:
        return line

    y_token = tokens[0]
    value_tokens = tokens[1:]
    trimmed_values = trim_tokens(value_tokens, edge)

    return " ".join([y_token] + trimmed_values) + "\n"


def trim_report(path, edge=10):
    """
    Читает отчёт из `path`, обрезает все найденные таблицы и
    возвращает итоговый текст файла целиком (список строк).
    """
    with open(path, "r", encoding="utf-8-sig", errors="replace") as f:
        lines = f.readlines()

    out_lines = []
    i = 0
    n_lines = len(lines)

    while i < n_lines:
        line = lines[i]
        out_lines.append(line)

        header_match = TABLE_HEADER_RE.match(line.strip())
        if not header_match:
            i += 1
            continue

        i += 1

        # Копируем пустые строки между заголовком таблицы и шапкой как есть
        while i < n_lines and not lines[i].strip():
            out_lines.append(lines[i])
            i += 1
        if i >= n_lines:
            break

        # Шапка таблицы (строка x-значений)
        out_lines.append(trim_header_line(lines[i], edge))
        i += 1

        # Строки данных
        data_rows = []
        data_start = i
        while i < n_lines:
            stripped = lines[i].strip()
            if not stripped:
                break
            tokens = stripped.split()
            # Проверяем, что первый токен - число (y-значение) и что
            # дальше есть хотя бы одно числовое значение -> это строка таблицы
            if not tokens or not is_number_token(tokens[0]):
                break
            data_rows.append(lines[i])
            i += 1
        data_end = i  # [data_start, data_end)

        n_rows = len(data_rows)
        if n_rows <= 2 * edge:
            kept_rows = data_rows
        else:
            top_rows = data_rows[:edge]
            bottom_rows = data_rows[-edge:]
            kept_rows = top_rows + ["__ROW_ELLIPSIS__"] + bottom_rows

        for row in kept_rows:
            if row == "__ROW_ELLIPSIS__":
                out_lines.append(ELLIPSIS + "\n")
            else:
                out_lines.append(trim_data_line(row, edge))

    return out_lines


def main():
    parser = argparse.ArgumentParser(
        description="Обрезка краёв таблиц в текстовых отчётах CLI.cpp "
                    "(оставляет по N элементов с каждой стороны, середина -> ...)."
    )
    parser.add_argument("reports", nargs="+", help="Путь(и) к текстовому отчёту (.txt)")
    parser.add_argument("-o", "--outdir", default="trimmed",
                        help="Папка для сохранения обрезанных отчётов (по умолчанию: trimmed)")
    parser.add_argument("--edge", type=int, default=10,
                        help="Сколько элементов оставлять с каждой стороны (по умолчанию: 10)")
    parser.add_argument("--suffix", default=None,
                        help="Если указан, файлы сохраняются рядом с исходными "
                             "с этим суффиксом перед расширением (например, _trimmed), "
                             "а не в --outdir")
    args = parser.parse_args()

    if args.suffix is None:
        os.makedirs(args.outdir, exist_ok=True)

    for report_path in args.reports:
        if not os.path.isfile(report_path):
            print(f"[!] Файл не найден: {report_path}", file=sys.stderr)
            continue

        trimmed_lines = trim_report(report_path, edge=args.edge)

        if args.suffix is not None:
            base, ext = os.path.splitext(report_path)
            out_path = f"{base}{args.suffix}{ext}"
        else:
            base_name = os.path.basename(report_path)
            out_path = os.path.join(args.outdir, base_name)

        with open(out_path, "w", encoding="utf-8") as f:
            f.writelines(trimmed_lines)

        print(f"[{report_path}] -> {out_path}")

    print("Готово.")


if __name__ == "__main__":
    main()

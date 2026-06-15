# Use Under WSL
g++ ./CLI/CLI.cpp ./CMLib/Functions.cpp ./CMLib/SeidelSolver.cpp ./CMLib/SORSolver.cpp -I./CMLib/ -std=c++20 -O2 -march=native -fopenmp

#include "Solver.hpp"
#include "SolverFactory.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <tuple>

int main() {
    SolverTraits::FunctionType f = [&](double x) { return -x * exp(-x) - 2; };

    SolverTraits::FunctionType df = [&](double x) { return -exp(-x) + x * exp(-x); };

    SolverTraits::VariableType x0 = -1, xf = 2;
    const unsigned int max_it = 100;
    SolverTraits::VariableType h = 0.02;

    auto Nsolver = make_solver(SolverType::Newton_solver, f, x0, xf, max_it, df, h);
    if (Nsolver)
        Nsolver->solve();
    else
        std::cout<< "NULL POINTER!!!"<<std::endl;


    auto QNsolver = make_solver(SolverType::QuasiNewton_solver, f, x0, xf, max_it, h);
    if (QNsolver)
        QNsolver->solve();
    else
        std::cout<< "NULL POINTER!!!"<<std::endl;

    return 0;
}
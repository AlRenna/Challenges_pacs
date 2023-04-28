#include "Solver.hpp"
#include "SolverFactory.hpp"

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <numbers>



int main(){
    const auto f = [](const ST::VariableType &x) {
        // return 0.5 - exp(std::numbers::pi * x);
        return 0.5 - exp(2. * x);
    };

    ST::VariableType x0 = 0.;
    ST::VariableType xf = 1.;

    const std::string name = "Bisection";
    auto BiSolver = make_solver(name,f,x0,xf);
    BiSolver->solve();
}
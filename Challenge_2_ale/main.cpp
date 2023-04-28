#include "Solver.hpp"
#include "SolverFactory.hpp"

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <numbers>



int main(){
    const auto f = [](const ST::VariableType &x) {
        return 0.5 - exp(std::numbers::pi * x);
        // return 0.5 - x;
    };

    const ST::VariableType x0 = -1.;
    const ST::VariableType xf = 3.;
    const unsigned int max_iter = 1e2;
    const ST::ReturnType toll_res = std::numeric_limits<double>::epsilon()*1000;

    const ST::VariableType h = 0.03;
    const ST::VariableType toll_incr = std::numeric_limits<double>::epsilon()*1000;

    std::string name = "QuasiNewton";
    auto QNSolver = make_solver(name,f,x0,xf,max_iter,toll_res, h, toll_incr);
    std::cout << "\nUsing QuasiNewton method" << std::endl;
    std::cout << "Zero found: " << QNSolver->solve() << std::endl;

    name = "Bisection";
    auto BiSolver = make_solver(name,f,x0,xf,max_iter,toll_res, h, toll_incr);
    std::cout << "\nUsing Bisection method" << std::endl;
    std::cout << "Zero found: " << BiSolver->solve() << std::endl;

    name = "Secant";
    auto SeSolver = make_solver(name,f,x0,xf,max_iter,toll_res, h, toll_incr);
    std::cout << "\nUsing Secant method" << std::endl;
    std::cout << "Zero found: " << SeSolver->solve() << std::endl;

}
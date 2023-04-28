#include "Solver.hpp"
#include "SolverFactory.hpp"

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <numbers>



int main(){

    // DATA //

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

    // METHODS //

    std::string name = "QuasiNewton";
    auto QNSolver = make_solver(name,f,x0,xf,max_iter,toll_res, h, toll_incr);
    auto result_QN = QNSolver->solve();

    name = "Bisection";
    auto BiSolver = make_solver(name,f,x0,xf,max_iter,toll_res, h, toll_incr);
    auto result_Bi = BiSolver->solve();

    name = "Secant";
    auto SeSolver = make_solver(name,f,x0,xf,max_iter,toll_res, h, toll_incr);
    auto result_Se = SeSolver->solve();


    // OUTPUT TO TEXT FILE
    std::fstream out_result{"./result.txt", std::ios::out};
    if (!out_result){
        std::cerr << " File open error " << std::endl;
        return 1;           // exit the main
    } else {                // write to the output file
        out_result << "Using QuasiNewton method\n" << "Zero found: " << result_QN;
        out_result << "\n\nUsing Bisection method\n" << "Zero found: " << result_Bi;
        out_result << "\n\nUsing Secant method\n" << "Zero found: " << result_Se;
    }
    out_result.close();
}
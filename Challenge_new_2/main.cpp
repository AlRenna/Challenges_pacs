#include "Solver.hpp"
#include "SolverFactory.hpp"

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

int main(){

    T::FunctionType f = [&](double x){
        return -x*exp(-x) -2;    
    };
    
    T::FunctionType df = [&](double x){
        return -exp(-x) + x*exp(-x) ;
    };
    
    T::VariableType x0 = -1, xf = 2;
    const unsigned int max_it = 100;
    T::VariableType h=0.02;


    /// Derived Solvers
    BaseSolver Bsolver;


    //auto NNsolver = make_solver_simple(SolverType::Newton_solver);

    auto Nsolver = make_solver(SolverType::Newton_solver,f,x0,xf,max_it,df,h);
    Nsolver->solve();

    auto QNsolver = make_solver(SolverType::QuasiNewton_solver,f,x0,xf,max_it,h);
    QNsolver->solve();


   /*  auto BiSolver = make_solver<BisectionSolver,SolverType::BisectionSolver>(f,x0,xf,max_iter);
    BiSolver->solve(); */

    // std::cout<< result << std::endl;

    return 0;
}
#include "Solver.hpp"
#include "SolverFactory.hpp"

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

int main(){

    auto f = [&](double x){
        return -x*exp(-x) -2;    
    };
    
    auto df = [&](double x){
        return -exp(-x) + x*exp(-x) ;
    };
    
    T::VariableType x0 = -1, xf = 2;

    /* /// Newton Solver (imported)
    std::string id ="Newton";
    BaseSolver Bsolver(f,x0,xf);
    auto Nsolver = make_solver<QuasiNewtonSolver>(id,Bsolver);

    /// Derived Solvers
    // BaseSolver Bsolver(f,x0,xf);
    id ="QuasiNewton";
    auto QNsolver = make_solver<QuasiNewtonSolver>(id,Bsolver);
    QNsolver.solve();
    std::cout<< QNsolver.GetZero()<< std::endl; */

    /// Newton Solver (imported)
    BaseSolver Bsolver(f,x0,xf);
    auto Nsolver = make_solver<SolverType::QuasiNewtonSolver>(Bsolver);

    /// Derived Solvers
    // BaseSolver Bsolver(f,x0,xf);
    // id ="QuasiNewton";
    auto QNsolver = make_solver<SolverType::QuasiNewtonSolver>(Bsolver);
    
    // QNsolver.solve();
    // std::cout<< QNsolver.GetZero()<< std::endl;





    // std::cout<< result << std::endl;
    

    /*
    // OUTPUT TO TEXT FILE
    std::fstream out_result{"./result.txt", std::ios::out};
    if (!out_result){
        std::cerr << " File open error " << std::endl;
        return 1;           // exit the main
    } else {                // write to the output file
        out_result << std::setw(10) << std::left << "t,y_t\n"; //Don't touch!!
        for(size_t i{0}; i < result.at(0).size(); i++){
            out_result << result.at(0).at(i) << "," << result.at(1).at(i) << "\n";
        }
    }
    out_result.close();
*/
    return 0;
}
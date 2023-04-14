#ifndef SOLVERFACTORY_HPP
#define SOLVERFACTORY_HPP

#include "Solver.hpp"
#include<iostream>
#include <memory>


enum class SolverType
{
  Newton = 0,
  QuasiNewton = 1,
  Bisection = 2,
  Secant = 3
};

template<class... Args>
std::unique_ptr<BaseSolver> make_solver(std::string id , Args&&... args) {
    
    if(id== "Newton") return std::make_unique<NewtonSolver>(std::forward<Args>(args)... ); //return std::make_unique<NewtonSolver>(std::forward<Args>(args);
    else if(id== "QuasiNewton") return std::make_unique<QuasiNewtonSolver>(std::forward<Args>(args)... );
    //else if(id== "Bisection") return std::make_unique<BisectionSolver>(std::forward<Args>(args)... );
    //else if(id== "QuasiNewton")  return std::make_unique<SecantSolver>(std::forward<Args>(args)... );
    else  return std::make_unique<BaseSolver>(std::forward<Args>(args)... );// TODO: return nullptr
}

#endif /* SOLVERFACTORY_HPP */
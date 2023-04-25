#ifndef SOLVERFACTORY_HPP
#define SOLVERFACTORY_HPP

#include "Solver.hpp"
#include<iostream>
#include <memory>


enum class SolverType : unsigned int
{
  NewtonSolver = 0,
  QuasiNewtonSolver = 1,
  BisectionSolver = 2,
  SecantSolver = 3
};

// TODO: problema nella conversione tra i puntatori
// template<class... Args>
// std::unique_ptr<BaseSolver> make_solver(std::string id , Args&&... args) {
    
//     if(id== "Newton") return std::make_unique<NewtonSolver>(std::forward<Args>(args)... ); //return std::make_unique<NewtonSolver>(std::forward<Args>(args);
//     else if(id== "QuasiNewton") return std::make_unique<QuasiNewtonSolver>(std::forward<Args>(args)... );
//     //else if(id== "Bisection") return std::make_unique<BisectionSolver>(std::forward<Args>(args)... );
//     //else if(id== "QuasiNewton")  return std::make_unique<SecantSolver>(std::forward<Args>(args)... );
//     else  return std::make_unique<BaseSolver>(std::forward<Args>(args)... );// TODO: return nullptr
// }


template <SolverType SolType, class... Args>
std::unique_ptr<BaseSolver>
make_solver(Args &&... args)
{
  // static_assert(SolType == SolverType::NewtonSolver ||
  //                 SolType == SolverType::QuasiNewtonSolver ||
  //                 SolType == BaseSolver,
  //               "Error in SolverType: Solver not yet implemented");

  if constexpr (SolType == SolverType::NewtonSolver)
    return std::make_unique<NewtonSolver>(std::forward<Args>(args)...);
  else if constexpr (SolType == SolverType::QuasiNewtonSolver)
    return std::make_unique<QuasiNewtonSolver>(std::forward<Args>(args)...);
  else 
    return std::make_unique<BaseSolver>(std::forward<Args>(args)...);
}

#endif /* SOLVERFACTORY_HPP */
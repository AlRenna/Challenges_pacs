#ifndef SOLVERFACTORY_HPP
#define SOLVERFACTORY_HPP

#include "Solver.hpp"
#include<iostream>
#include <memory>


enum class SolverType
{
  Newton_solver,
  QuasiNewton_solver,
  Bisection_solver,
  Secant_solver,
  Base_solver
};

inline
std::unique_ptr<BaseSolver>
make_solver_simple(SolverType s)
{
  switch(s)
    {
    case SolverType::Newton_solver:{
        std::cout<<"Made pointer to newtonsolver!!!"<<std::endl;
      return std::make_unique<NewtonSolver>();}
    case SolverType::QuasiNewton_solver:
      return std::make_unique<QuasiNewtonSolver>();
    case SolverType::Bisection_solver:
      return std::make_unique<BisectionSolver>();
    case SolverType::Secant_solver:
      return std::make_unique<SecantSolver>();
    default:
      return nullptr;
    }
} 


template <class... Args>
std::unique_ptr<BaseSolver>
make_solver(SolverType s, Args &&... args)
{
  switch(s)
    {
    /* case SolverType::Newton_solver:
      return std::make_unique<NewtonSolver>(std::forward<Args>(args)...); */
    case SolverType::QuasiNewton_solver:
      return std::make_unique<QuasiNewtonSolver>(std::forward<Args>(args)...);
    /* case SolverType::Bisection_solver:
      return std::make_unique<BisectionSolver>(std::forward<Args>(args)...);
    case SolverType::Secant_solver:
      return std::make_unique<SecantSolver>(std::forward<Args>(args)...); */
    default:
      return nullptr;
    }
}

#endif /* SOLVERFACTORY_HPP */
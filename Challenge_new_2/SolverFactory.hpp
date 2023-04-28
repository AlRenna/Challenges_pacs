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


std::unique_ptr<BaseSolver> make_Newton_solver(
        const T::FunctionType &f_, 
        const T::VariableType &x0_, 
        const T::VariableType &xf_, 
        const unsigned int &max_it, 
        const T::FunctionType &df_,
        const T::VariableType &h_)
                {return std::make_unique<NewtonSolver>(f_,x0_,xf_,max_it,df_,h_);}

std::unique_ptr<BaseSolver> make_QuasiNewton_solver(
        const T::FunctionType &f_, 
        const T::VariableType &x0_, 
        const T::VariableType &xf_, 
        const unsigned int &max_it, 
        const T::VariableType &h_)
                {return std::make_unique<QuasiNewtonSolver>(f_,x0_,xf_,max_it,h_);}

/* std::unique_ptr<BaseSolver> make_Bisection_solver(double tol, int max_iter)
{
  return std::make_unique<BisectionSolver>(tol, max_iter);
}

std::unique_ptr<BaseSolver> make_Secant_solver(double tol, int max_iter)
{
  return std::make_unique<SecantSolver>(tol, max_iter);
} */

template <class... Args>
std::unique_ptr<BaseSolver> make_solver(SolverType s, Args &&... args)
{
  switch(s)
    {
    case SolverType::Newton_solver:
      return make_Newton_solver(std::forward<Args>(args)...);
    case SolverType::QuasiNewton_solver:
      return make_QuasiNewton_solver(std::forward<Args>(args)...);
    /* case SolverType::Bisection_solver:
      return make_Bisection_solver(std::forward<Args>(args)...);
    case SolverType::Secant_solver:
      return make_Secant_solver(std::forward<Args>(args)...); */
    default:
      return nullptr;
    }
}

#endif /* SOLVERFACTORY_HPP */
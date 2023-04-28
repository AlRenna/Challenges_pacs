#ifndef SOLVERFACTORY_HPP
#define SOLVERFACTORY_HPP

#include "Solver.hpp"
#include <memory>

template<class ...Args>
std::unique_ptr<BaseSolver>
make_solver(std::string const &name, Args &&...args)
{
  if(name == "QuasiNewton")
    return std::make_unique<QuasiNewtonSolver>(std::forward<Args>(args)...);
  if(name == "Bisection")
    return std::make_unique<BisectionSolver>(std::forward<Args>(args)...);
//   if(name == "Secant")
//     return std::make_unique<SecantSolver>(std::forward<Args>(args)...);
  // this way I can easily check if I try to construct a non existent Polygon
  return std::unique_ptr<BaseSolver>(nullptr);
}


#endif /* SOLVERFACTORY_HPP */
#ifndef SOLVERFACTORY_HPP
#define SOLVERFACTORY_HPP

#include "Solver.hpp"

enum class SolverType
{
  Discrete = 0,
  Full     = 1
};

template<class... Args>
unique_ptr<BaseSolver> SolverFactory(string id , Args&&... args) {
    switch(id)
    case ”Newton”: return make unique<NewtonSolve>(std::forward<Args>(args);
    case ”QuasiNewton” : return make unique<QuasiNewtonSolver>(std::forward<Args>(args );
    case ”Bisection”: return make unique<BisectionSolver>(std::forward<Args>(args);
    case ”Secant”: return make unique<SecantSolver>(std::forward<Args>(args);
    default : return unique ptr<BaseSolver>();// return nullptr
}

#endif /* SOLVERFACTORY_HPP */
#ifndef SOLVERFACTORY_HPP
#define SOLVERFACTORY_HPP

#include "Solver.hpp"
#include<iostream>
#include <memory>



namespace Zeros
{

class SolverFactory{
  public:
    loadSolverFactory() = default;
    //! Constructor that loads libraries
    loadSolverFactory(std::string s) { this->load(s); }
    //! loads load library names (plugins) from file
    bool load(std::string pluginFile);
    //! close libraries
    void close();

  private:
    std::vector<void *> loadedLibs;
};

template<class... Args>
std::unique_ptr<BaseSolver> make_solver(std::string id , Args&&... args) {
    
    if(id== "Newton") return std::make_unique<NewtonSolver>(std::forward<Args>(args)... ); //return std::make_unique<NewtonSolver>(std::forward<Args>(args);
    else if(id== "QuasiNewton") return std::make_unique<QuasiNewtonSolver>(std::forward<Args>(args)... );
    //else if(id== "Bisection") return std::make_unique<BisectionSolver>(std::forward<Args>(args)... );
    //else if(id== "QuasiNewton")  return std::make_unique<SecantSolver>(std::forward<Args>(args)... );
    else  return std::make_unique<BaseSolver>(std::forward<Args>(args)... );// TODO: return nullptr
}

} // namespace Zeros

#endif /* SOLVERFACTORY_HPP */
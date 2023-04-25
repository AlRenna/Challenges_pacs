#ifndef LOADSOLVERFACTORY_HPP
#define LOADSOLVERFACTORY_HPP

#include "Solver.hpp"
#include <dlfcn.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>



namespace Zeros
{

class loadSolverFactory{
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



} // namespace Zeros

#endif /* LOADSOLVERFACTORY_HPP */
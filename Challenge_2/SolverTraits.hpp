#ifndef SOLVERTRAITS_HPP
#define SOLVERTRAITS_HPP

#include <functional>
#include <limits>



/// Class defining common types for homogeneity.
class SolverTraits
{
public: //TODO: USEFUL VARIABLE TYPES
  
  using ReturnType = double;
  using VariableType = double;
  using FunctionType = std::function<ReturnType(VariableType)>;
  //constexpr double  Tolerance = std::numeric_limits<double>::epsilon()*1000;


};

#endif /* SOLVERTRAITS_HPP */
#ifndef SOLVERTRAITS_HPP
#define SOLVERTRAITS_HPP

#include <functional>
#include <Eigen/Dense>

/// Class defining common types for homogeneity.
class SolverTraits
{
public: //TODO: USEFUL VARIABLE TYPES
  
  using ReturnType = double;

///////////////////////////////////////////////////

  /// Type used to store the Jacobian.
  using JacobianMatrixType = Eigen::MatrixXd;

  /// The type for the non-linear system.
  using NonLinearSystemType = std::function<VariableType(const VariableType &)>;

  /// Type for evaluating the Jacobian.
  using JacobianFunctionType =
    std::function<JacobianMatrixType(const VariableType &)>;
////////////////////////////////////////////////////

};

#endif /* SOLVERTRAITS_HPP */
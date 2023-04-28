#ifndef SOLVERFACTORY_HPP
#define SOLVERFACTORY_HPP

#include "Solver.hpp"
#include <memory>
#include <tuple>
#include <utility>

enum class SolverType {
  Newton_solver,
  QuasiNewton_solver,
  Bisection_solver,
  Secant_solver
};

template <typename T, typename... Args>
std::unique_ptr<T> make_solver_helper(SolverType solver_type, std::tuple<Args...>&& args) {
  if constexpr (std::is_constructible_v<T, Args...>) {
    if (solver_type == SolverType::Newton_solver) {
      return std::make_unique<NewtonSolver>(std::forward<Args>(std::get<Args>(args))...);
    } else if (solver_type == SolverType::QuasiNewton_solver) {
      return std::make_unique<QuasiNewtonSolver>(std::forward<Args>(std::get<Args>(args))...);
    } else if (solver_type == SolverType::Bisection_solver) {
      return std::make_unique<BisectionSolver>(std::forward<Args>(std::get<Args>(args))...);
    } else if (solver_type == SolverType::Secant_solver) {
      return std::make_unique<SecantSolver>(std::forward<Args>(std::get<Args>(args))...);
    }
  }
  return nullptr;
}

template <typename... Args>
std::unique_ptr<BaseSolver> make_solver(SolverType type, Args&&... args) {
  auto t = std::make_tuple(std::forward<Args>(args)...);
  return make_solver_helper<BaseSolver>(type, std::move(t));
}

#endif /* SOLVERFACTORY_HPP */

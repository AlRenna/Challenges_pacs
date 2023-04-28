# include "Solver.hpp"

/// BASE CLASS ///

BaseSolver::BaseSolver(
        const ST::FunctionType &f,
        const ST::VariableType &x0,
        const ST::VariableType &xf):
        m_f(f),
        m_x0(x0),
        m_xf(xf) {};



/// QUASINEWTON METHOD ///

QuasiNewtonSolver::QuasiNewtonSolver(
        const ST::FunctionType &f,
        const ST::VariableType &x0,
        const ST::VariableType &xf):
        BaseSolver(f,x0,xf) {};

ST::ReturnType QuasiNewtonSolver::solve() {
    std::cout << "using QuasiNewton" << std::endl;
    return m_zero;
};


/// BISECTION METHOD ///

BisectionSolver::BisectionSolver(
        const ST::FunctionType &f,
        const ST::VariableType &x0,
        const ST::VariableType &xf):
        BaseSolver(f,x0,xf) {};

ST::ReturnType BisectionSolver::solve() {
    std::cout << "using Bisection" << std::endl;
    return m_zero;
};

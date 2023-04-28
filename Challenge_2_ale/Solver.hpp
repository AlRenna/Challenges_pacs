#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "SolverTraits.hpp"
#include <functional>
#include <limits>
#include <iostream>

using ST = SolverTraits;

//// BASE SOLVER (ABSTRACT CLASS) ////

class BaseSolver 
{
    public:
    
    // BaseSolver() = default;
    //! virtual destructor
    virtual ~BaseSolver() = default;

    BaseSolver(
        const ST::FunctionType &f,
        const ST::VariableType &x0,
        const ST::VariableType &xf);

    virtual ST::ReturnType solve() { return m_zero;};

    protected:

    const ST::FunctionType m_f;
    const ST::VariableType m_x0;
    const ST::VariableType m_xf;
    const ST::ReturnType m_zero = 0.;

};


//// DERIVED SOLVERS ////

class QuasiNewtonSolver final : public BaseSolver
{   
    public:
    // using BaseSolver::BaseSolver;
    QuasiNewtonSolver(
        const ST::FunctionType &f,
        const ST::VariableType &x0,
        const ST::VariableType &xf);

    ~QuasiNewtonSolver() {};

    ST::ReturnType solve() override;
};


class BisectionSolver final : public BaseSolver
{
    public:
    // using BaseSolver::BaseSolver;
    BisectionSolver(
        const ST::FunctionType &f,
        const ST::VariableType &x0,
        const ST::VariableType &xf);

    ~BisectionSolver() {};

    ST::ReturnType solve() override;
};





#endif /* SOLVER_HPP */
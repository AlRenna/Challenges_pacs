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
        const ST::VariableType &xf,
        const unsigned int &max_iter,
        const ST::ReturnType &toll_res,
        const ST::VariableType &h,
        const ST::VariableType &toll_incr);

    virtual ST::ReturnType solve() { return m_zero;};

    protected:

    const ST::FunctionType m_f;
    const ST::VariableType m_x0;
    const ST::VariableType m_xf;
    const unsigned int m_max_iter = 1e3;
    const ST::ReturnType m_toll_res = std::numeric_limits<double>::epsilon()*1000;
    const ST::VariableType m_h;
    const ST::VariableType m_toll_incr = std::numeric_limits<ST::VariableType>::epsilon()*1000;
    
    ST::ReturnType m_zero = 0.;
    

};


//// DERIVED SOLVERS ////

class QuasiNewtonSolver final : public BaseSolver
{   
    public:
    // using BaseSolver::BaseSolver;

    QuasiNewtonSolver(
        const ST::FunctionType &f,
        const ST::VariableType &x0,
        const ST::VariableType &xf,        
        const unsigned int &max_iter,
        const ST::ReturnType &toll_res,
        const ST::VariableType &h,
        const ST::VariableType &toll_incr);

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
        const ST::VariableType &xf,        
        const unsigned int &max_iter,
        const ST::ReturnType &toll_res,
        const ST::VariableType &h,
        const ST::VariableType &toll_incr);

    ~BisectionSolver() {};

    ST::ReturnType solve() override;
};


class SecantSolver final : public BaseSolver
{
    public:
    // using BaseSolver::BaseSolver;
    SecantSolver(
        const ST::FunctionType &f,
        const ST::VariableType &x0,
        const ST::VariableType &xf,        
        const unsigned int &max_iter,
        const ST::ReturnType &toll_res,
        const ST::VariableType &h,
        const ST::VariableType &toll_incr);

    ~SecantSolver() {};

    ST::ReturnType solve() override;
};




#endif /* SOLVER_HPP */
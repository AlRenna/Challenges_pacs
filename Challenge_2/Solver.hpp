#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "SolverTraits.hpp"
#include "newton.hpp"
#include <functional>
#include <limits>
#include <iostream>


using T = SolverTraits;

class BaseSolver{

    public:
    BaseSolver() = default;

    BaseSolver(
        const T::FunctionType &f ,
        const T::VariableType &x0, 
        const T::VariableType &xf,
        const unsigned int m_iter = 1000);

    virtual void solve(); // {T::ReturnType x=0; return x;};

    //~BaseSolver() = default;

    /// New Methods
    T::VariableType GetZero() {return m_x;}

    protected:
    const T::FunctionType m_f;
    const T::VariableType m_x0;
    const T::VariableType m_xf;
    const unsigned int m_max_it;
    T::VariableType m_x;
    const T::ReturnType m_toll_res = std::numeric_limits<double>::epsilon()*1000;
    
    

};


class QuasiNewtonSolver final: public BaseSolver{

    public:

    QuasiNewtonSolver() = default;

    QuasiNewtonSolver(
        const T::FunctionType &f,
        const T::VariableType &x0,
        const T::VariableType &xf,
        const unsigned int max_it = 100,
        double h = 0.05,
        double toll_incr = std::numeric_limits<double>::epsilon()*1000     // default value
        );

    // QuasiNewtonSolver(
    //     const BaseSolver &solver,
    //     double h = 0.05,
    //     double toll_res = std::numeric_limits<double>::epsilon()*1000,      // default value
    //     double toll_incr = std::numeric_limits<double>::epsilon()*1000,     // default value
    //     unsigned int max_it = 100);


    void solve() override;


    //~QuasiNewtonSolver() = default;

    private:
    /// new members
    const T::VariableType m_h = 0.05;
    const T::VariableType m_toll_incr = std::numeric_limits<double>::epsilon()*1000;
    
    // current values, members that change depending on the iteration:
    T::ReturnType m_df_x;  // current value of df/dx (x)
    T::VariableType m_dx;    // current increment
    T::ReturnType m_res;   // current residual
    unsigned int m_iter;  // current iteration

};

class BisectionSolver final: public BaseSolver{
    
    public:
    
    BisectionSolver(
        const T::FunctionType &f,
        const T::VariableType &x0,
        const T::VariableType &xf,
        const unsigned int max_it);
    
    void solve()  override;  

};

class SecantSolver final: public BaseSolver{

    public:

    SecantSolver(
        const T::FunctionType &f,
        const T::VariableType &x0,
        const T::VariableType &xf,
        const unsigned int max_it);

    void solve()  override;


};

#endif /* SOLVER_HPP */
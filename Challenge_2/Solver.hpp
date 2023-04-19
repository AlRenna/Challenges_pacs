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
    BaseSolver(
        const T::FunctionType &f ,
        const T::VariableType &x0, 
        const T::VariableType &xf,
        const unsigned int max_it=100,
        const double toll_res = std::numeric_limits<double>::epsilon()*1000): 
            m_x((xf+x0)/2),
            m_f(f),
            m_x0(x0),
            m_xf(xf),
            m_max_it(max_it),
            m_toll_res(toll_res){};  // current guess for the zero (middle of the domain)

    virtual void solve() {};

    T::ReturnType GetZero() {return m_x;};

    protected:
    double m_x;     // current guess for the zero
    const T::FunctionType m_f;
    const T::VariableType m_x0; //left boundary
    const T::VariableType m_xf; //right boundary
    const unsigned int m_max_it; // maximum number of iterations
    const double m_toll_res;    // tollerance for solvers



};


class QuasiNewtonSolver final: public BaseSolver{

    public:

    QuasiNewtonSolver(
        const T::FunctionType &f,
        const T::VariableType &x0,
        const T::VariableType &xf,
        double h = 0.05,                                                     // default value
        double toll_incr = std::numeric_limits<double>::epsilon()*1000);     // default value
        

    QuasiNewtonSolver(
        const BaseSolver &solver,
        double h = 0.05,
        double toll_incr = std::numeric_limits<double>::epsilon()*1000);     // default value


    void solve()  override;


    private:
    const double m_h = 0.05;
    const double m_toll_incr;

    // current values, members that change depending on the iteration:
    double m_df_x;  // current value of df/dx (x)
    double m_dx;    // current increment
    double m_res;   // current residual
    double m_iter;  // current iteration

};

class BisectionSolver final: public BaseSolver{

    public:
    void solve()  override;  

    private:
    const double m_toll_incr;
    // current values, members that change depending on the iteration:
    double m_df_x;  // current value of df/dx (x)
    double m_dx;    // current increment
    double m_res;   // current residual
    double m_iter;  // current iteration

};

class SecantSolver final: public BaseSolver{

    public:
    void solve()  override;


};

#endif /* SOLVER_HPP */
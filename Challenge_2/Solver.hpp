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
        const T::VariableType &xf): 
            m_f(f),
            m_x0(x0),
            m_xf(xf) {};

    virtual void solve(); // {T::ReturnType x=0; return x;};

    //~BaseSolver() = default;

    protected:
    const T::FunctionType m_f;
    const T::VariableType m_x0;
    const T::VariableType m_xf;

    
    

};


///TODO: maybe we can also import the previous work we did for the newton solver and put it in the Examples/include folder
/*class NewtonSolver{

    public:
    ReturnType solve() override;

    protected:

    const T::FunctionType &f,



};*/

class QuasiNewtonSolver final: public BaseSolver{

    public:

    QuasiNewtonSolver() = default;

    QuasiNewtonSolver(
        const T::FunctionType &f,
        const T::VariableType &x0,
        const T::VariableType &xf,
        double h = 0.05,
        double toll_res = std::numeric_limits<double>::epsilon()*1000,      // default value
        double toll_incr = std::numeric_limits<double>::epsilon()*1000,     // default value
        unsigned int max_it = 100);

    QuasiNewtonSolver(
        const BaseSolver &solver,
        double h = 0.05,
        double toll_res = std::numeric_limits<double>::epsilon()*1000,      // default value
        double toll_incr = std::numeric_limits<double>::epsilon()*1000,     // default value
        unsigned int max_it = 100);


    void solve() override;


    /// New Methods
    T::VariableType GetZero() {return m_x;}

    //~QuasiNewtonSolver() = default;

    private:
    /// new members
    const double m_h = 0.05;
    const double m_toll_res = std::numeric_limits<double>::epsilon()*1000;
    const double m_toll_incr = std::numeric_limits<double>::epsilon()*1000;
    const unsigned int m_max_it = 100;
    // current values, members that change depending on the iteration:
    double m_x;     // current guess for the zero
    double m_df_x;  // current value of df/dx (x)
    double m_dx;    // current increment
    double m_res;   // current residual
    double m_iter;  // current iteration

};

class BisectionSolver final: public BaseSolver{

    public:
    void solve()  override;  

};

class SecantSolver final: public BaseSolver{

    public:
    void solve()  override;


};

#endif /* SOLVER_HPP */
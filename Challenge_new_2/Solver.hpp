#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "SolverTraits.hpp"
#include <functional>
#include <cmath>
#include <limits>
#include <iostream>
#include <type_traits>



using T = SolverTraits;

class BaseSolver{

    public:
    BaseSolver() {};
    //il constructor cosi definito non funziona nel cpp file, riprovare, il problema sorge quanto immetti la std::function
    BaseSolver(const T::FunctionType &f_, const T::VariableType &x0_, const T::VariableType &xf_, const unsigned int &max_it): 
        m_f(f_),
        m_x0(x0_),
        m_xf(xf_),
        m_max_it(max_it) {};

    virtual void solve() {};

    //inline T::ReturnType GetZero() {return m_x;};

    //~BaseSolver() = default;

    T::VariableType GetZero() {return m_x;}

    protected:
    //Initializable const variables 
    const T::FunctionType m_f = nullptr;
    const T::VariableType m_x0 = 0.0;
    const T::VariableType m_xf = 1.0;
    const unsigned int m_max_it = 1000;

    //Non-initializable const variables
    const T::ReturnType m_toll_res = std::numeric_limits<double>::epsilon()*1000;
    const T::VariableType m_toll_incr = std::numeric_limits<double>::epsilon()*1000;

    //other variables
    T::VariableType m_x = NULL;  // current estimate of the zero
    T::ReturnType m_res = 0.;   // current residual
    unsigned int m_iter = 0;  // current iteration
    
};

class NewtonSolver final: public BaseSolver{

    public:

    NewtonSolver() = default;

    NewtonSolver(
        const T::FunctionType &f_, 
        const T::VariableType &x0_, 
        const T::VariableType &xf_, 
        const unsigned int &max_it, 
        const T::FunctionType &df_,
        const T::VariableType &h_ ):
            BaseSolver(f_,x0_,xf_,max_it),
            m_df(df_),
            m_h(h_) {}; 

    void solve() override ;

    //~NewtonSolver() = default;

    private:
    const T::FunctionType m_df = nullptr;
    const T::VariableType m_h = 0.01;

};


class QuasiNewtonSolver final: public BaseSolver{

    public:

    QuasiNewtonSolver() = default;

    QuasiNewtonSolver(
        const T::FunctionType &f_,
        const T::VariableType &x0_,
        const T::VariableType &xf_,
        const unsigned int &max_it,
        const T::VariableType &h_) :
            BaseSolver(f_,x0_, xf_, max_it),
            m_h(h_) {};           

    void solve() override;

    //~QuasiNewtonSolver() = default;

    private:
    const T::VariableType m_h = 0.01;


};

class BisectionSolver final: public BaseSolver{
    
    public:
    
    BisectionSolver() = default;
    
    void solve()  override {};  

    //~BisectionSolver() = default;

};

class SecantSolver final: public BaseSolver{

    public:

    SecantSolver();

    void solve()  override {};

    //~SecantSolver() = default;


}; 

#endif /* SOLVER_HPP */
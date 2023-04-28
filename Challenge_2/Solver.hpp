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
    
    virtual void read_data(){};
    virtual void solve() {};

    T::VariableType GetZero() {return m_x;}

    //~BaseSolver() = default;    

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



class QuasiNewtonSolver final: public BaseSolver{

    public:

    QuasiNewtonSolver() {read_data()};

      
    void read_data() override {};
    void solve() override {};

    //~QuasiNewtonSolver() = default;

    private:
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
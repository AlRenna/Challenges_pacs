#include "Solver.hpp"
#include <type_traits>
#include <iostream>


using T = SolverTraits;
/////////////////////////////////// BASE CLASS /////////////////////////////////

/* BaseSolver::BaseSolver(const func_t &f_, const T::VariableType &x0_, const T::VariableType &xf_, const unsigned int &max_it) 
        : 
        m_f{f_} ,
        m_x0{x0_},
        m_xf{xf_},
        m_max_it{max_it} {} */



/////////////////////////////////// NEWTON /////////////////////////////////////


/* void NewtonSolver::solve() {
    m_x = m_x0;                                 // first guess
    T::ReturnType df_x = m_df(m_x);             //  derivative at current timestep
    T::VariableType dx = m_res / df_x;          // space step

    for (m_iter = 0; m_iter < m_max_it; ++m_iter){
        m_res = m_f(m_x);                       // function evaluated in the current point
        if (std::abs(m_res) < m_toll_res)
            break;
        df_x = m_df(m_x);
        dx = m_res / df_x;
        m_x -= dx;                              // m_dx = m_x(k) - m_x(k+1)
        if (std::abs(dx) < m_toll_incr)         // if the step is smaller then our toll_incr
            break;
    }
    std::cout<< "Finished Newton Solver loop with estimate at:\t"<< m_x <<"\tWith "<< m_iter << " iterations."<<std::endl;
} */


/////////////////////////////////// QUASINEWTON /////////////////////////////////

void QuasiNewtonSolver::solve()  {
    std::cout<< "Solving Quasinewton"<<std::endl;
    m_x = m_x0;
    T::ReturnType df_x = (m_f(m_x+m_h)-m_f(m_x-m_h))/(2*m_h);  // approx of the derivative
    T::VariableType dx = m_res / df_x;                         // space step


    for (unsigned int m_iter = 0; m_iter < m_max_it; ++m_iter){
    std::cout<<"\tWith "<< m_iter << " iterations."<<std::endl;  
        m_res = m_f(m_x);                                      // function evaluated in the current point
        if (std::abs(m_res) < m_toll_res)
            break;
        df_x = (m_f(m_x+m_h)-m_f(m_x-m_h))/(2*m_h);  
        dx = m_res / df_x;
        m_x -= dx;                // m_dx = m_x(k) - m_x(k+1)
        if (std::abs(dx) < m_toll_incr)       // if the step is smaller then our toll_incr
            break;
    }

    std::cout<< "Finished QuasiNewton Solver loop with estimate at:\t"<< m_x <<"\tWith "<< m_iter << " iterations."<<std::endl;  
}



/////////////////////////////////// BISECTION /////////////////////////////////


//BisectionSolver::BisectionSolver();

/* void BisectionSolver::solve() {
    std::cout<< "Solving Bisection"<<std::endl;
    T::ReturnType fa = m_f(m_x0), fb = m_f(m_xf);
    T::VariableType a = m_x0, b = m_xf;
    if (fa * fb < 0){
        for (unsigned int m_iter = 0; m_iter < m_max_it; ++m_iter){
            fa = m_f(a);
            fb = m_f(b);
            m_x = (b+a)/2;

            if (std::abs(m_f(m_x)) < m_toll_res)
                break;
            if (m_f(m_x) * fa < 0)
                b = m_x;
            else 
                a = m_x;
            
        }
    }
    else 
        std::cout << "f has the same sign on the boundary points.\n It's not possible to apply the bisectione method" << std::endl;

    // std::cout<< "Max iterations done"<<std::endl;
} */


/////////////////////////////////// SECANT /////////////////////////////////

//SecantSolver::SecantSolver();


/* void SecantSolver::solve() {
    std::cout<< "Solving Secant"<<std::endl;
    T::VariableType x0 = m_x0, x1 = m_xf;
    for (unsigned int m_iter = 0; m_iter < m_max_it; ++m_iter){
        m_x = x1 - m_f(x1) * (x1-x0) / (m_f(x1) - m_f(x0));

        if (std::abs(m_f(m_x)) < m_toll_res)
            if (m_x < m_x0 || m_x > m_xf)
                std::cout << "Zero found outside the given domain" << std::endl;
            break;

        x0 = x1;
        x1 = m_x;        
    }
} */
#include "Solver.hpp"

/////////////////////////////////// BASE CLASS /////////////////////////////////

BaseSolver::BaseSolver(
    const T::FunctionType &f ,
    const T::VariableType &x0, 
    const T::VariableType &xf,
    const unsigned int max_it): 
        m_f(f),
        m_x0(x0),
        m_xf(xf),
        m_max_it(max_it),
        m_x(x0) {};



/////////////////////////////////// QUASINEWTON /////////////////////////////////



QuasiNewtonSolver::QuasiNewtonSolver(
    const T::FunctionType &f,
    const T::VariableType &x0,
    const T::VariableType &xf,
    const unsigned int max_it,
    double h,
    double toll_incr
    ) :
        BaseSolver(f,x0, xf, max_it),
        m_h(h),
        m_toll_incr(toll_incr),
        m_res(m_toll_res +1),
        m_df_x(0),          // dfdx evaluated in the current result
        m_dx(0){};            // current increment
        




void QuasiNewtonSolver::solve()  {
    std::cout<< "Solving Quasinewton"<<std::endl;
    for (unsigned int m_iter = 0; m_iter < m_max_it; ++m_iter){
        m_x = (m_x0 + m_xf) / 2;
        m_res = m_f(m_x);       // function evaluated in the current point
        std::cout<< m_x<< "----------" << m_res <<std::endl;
        if (std::abs(m_res) < m_toll_res)
            break;
        m_df_x = (m_f(m_x+m_h)-m_f(m_x-m_h))/(2*m_h);  // approx of the derivative
        m_dx = m_res / m_df_x;
        m_x -= m_dx;                // m_dx = m_x(k) - m_x(k+1)
        if (std::abs(m_dx) < m_toll_incr)       // if the step is smaller then our toll_incr
            break;
    }

    // std::cout<< "Max iterations done"<<std::endl;
    

}


/////////////////////////////////// BISECTION /////////////////////////////////


BisectionSolver::BisectionSolver(
    const T::FunctionType &f,
    const T::VariableType &x0,
    const T::VariableType &xf,
    const unsigned int max_it) :
        BaseSolver(f,x0,xf,max_it) {};

void BisectionSolver::solve() {
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
}


/////////////////////////////////// SECANT /////////////////////////////////

SecantSolver::SecantSolver(
    const T::FunctionType &f,
    const T::VariableType &x0,
    const T::VariableType &xf,
    const unsigned int max_it) :
        BaseSolver(f,x0,xf,max_it) {};


void SecantSolver::solve() {
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
}
# include "Solver.hpp"

/// BASE CLASS ///

BaseSolver::BaseSolver(
        const ST::FunctionType &f,
        const ST::VariableType &x0,
        const ST::VariableType &xf,        
        const unsigned int &max_iter,
        const ST::ReturnType &toll_res,
        const ST::VariableType &h,
        const ST::VariableType &toll_incr):
        m_f(f),
        m_x0(x0),
        m_xf(xf),
        m_max_iter(max_iter),
        m_toll_res(toll_res),
        m_h(h),
        m_toll_incr(toll_incr) {};



/// QUASINEWTON METHOD ///

QuasiNewtonSolver::QuasiNewtonSolver(
        const ST::FunctionType &f,
        const ST::VariableType &x0,
        const ST::VariableType &xf,        
        const unsigned int &max_iter,
        const ST::ReturnType &toll_res,
        const ST::VariableType &h,
        const ST::VariableType &toll_incr):
        BaseSolver(f,x0,xf,max_iter,toll_res,h,toll_incr) {};


ST::ReturnType QuasiNewtonSolver::solve() {
    // current values, members that change depending on the iteration:
    ST::ReturnType m_df_x = 0.;  // current value of df/dx (x)
    ST::VariableType m_dx = 0.;    // current increment
    ST::ReturnType m_res;   // current residual

    m_zero = (m_x0 + m_xf) / 2;
    for (unsigned int m_iter = 0; m_iter < m_max_iter; ++m_iter){
        m_res = m_f(m_zero);       // function evaluated in the current point
        // std::cout<< "Zero:" << m_zero<< "---- Residual:" << m_res <<std::endl;
        if (std::abs(m_res) < m_toll_res)
            break;
        m_df_x = (m_f(m_zero+m_h)-m_f(m_zero-m_h))/(2*m_h);  // approx of the derivative
        m_dx = m_res / m_df_x;
        m_zero -= m_dx;                // m_dx = m_x(k) - m_x(k+1)
        if (std::abs(m_dx) < m_toll_incr)       // if the step is smaller then our toll_incr
            break;
    }   

    return m_zero;
};


/// BISECTION METHOD ///

BisectionSolver::BisectionSolver(
        const ST::FunctionType &f,
        const ST::VariableType &x0,
        const ST::VariableType &xf,        
        const unsigned int &max_iter,
        const ST::ReturnType &toll_res,
        const ST::VariableType &h,
        const ST::VariableType &toll_incr):
        BaseSolver(f,x0,xf,max_iter,toll_res,h,toll_incr) {};


ST::ReturnType BisectionSolver::solve() {
    ST::ReturnType fa = m_f(m_x0), fb = m_f(m_xf);
    ST::VariableType a = m_x0, b = m_xf;
    ST::ReturnType m_res;   // current residual

    if (fa * fb < 0){
        for (unsigned int m_iter = 0; m_iter < m_max_iter; ++m_iter){
            fa = m_f(a);
            fb = m_f(b);
            m_zero = (b + a)/2;
            m_res = m_f(m_zero);       // function evaluated in the current point
            // std::cout<< "Zero:" << m_zero<< "---- Residual:" << m_res <<std::endl;

            if (std::abs(m_res) < m_toll_res)
                break;
            if (m_f(m_zero) * fa < 0)
                b = m_zero;
            else 
                a = m_zero;
        }
    }
    else 
        std::cout << "f has the same sign on the boundary points."
        << "\nIt's not possible to apply the bisectione method" << std::endl;

    return m_zero;
};


/// SECANT METHOD ///

SecantSolver::SecantSolver(
        const ST::FunctionType &f,
        const ST::VariableType &x0,
        const ST::VariableType &xf,        
        const unsigned int &max_iter,
        const ST::ReturnType &toll_res,
        const ST::VariableType &h,
        const ST::VariableType &toll_incr):
        BaseSolver(f,x0,xf,max_iter,toll_res,h,toll_incr) {};


ST::ReturnType SecantSolver::solve() {
    ST::VariableType x0 = m_x0, x1 = m_xf;
    ST::ReturnType m_res;   // current residual

    for (unsigned int m_iter = 0; m_iter < m_max_iter; ++m_iter){
        m_zero = x1 - m_f(x1) * (x1-x0) / (m_f(x1) - m_f(x0));

        m_res = m_f(m_zero);       // function evaluated in the current point
        // std::cout<< "Zero:" << m_zero<< "---- Residual:" << m_res <<std::endl;

        if (std::abs(m_res) < m_toll_res){
            if (m_zero < m_x0 || m_zero > m_xf){
                std::cout << "Zero found outside the given domain" << std::endl;
            }
            break;
        }

        x0 = x1;
        x1 = m_zero;        
    }
    return m_zero;
};
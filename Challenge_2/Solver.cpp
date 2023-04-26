#include "Solver.hpp"

/////////////////////////////////// BASE CLASS /////////////////////////////////





/////////////////////////////////// QUASINEWTON /////////////////////////////////




QuasiNewtonSolver::QuasiNewtonSolver(
    const T::FunctionType &f,
    const T::VariableType &x0,
    const T::VariableType &xf,
    double h,
    double toll_res,//std::numeric_limits<double>::epsilon()*1000,      // default value
    double toll_incr,//std::numeric_limits<double>::epsilon()*1000,     // default value
    unsigned int max_it) :   // initialization list, constructing the solver passing our parameters (d,df,tollres,tollincr,maxit)
        BaseSolver(f,x0,xf),
        m_h(h),
        m_toll_res(toll_res),
        m_toll_incr(toll_incr),
        m_max_it(max_it),

        m_res(toll_res +1),
        m_x((m_xf+m_x0)/2),             // current guess for the result (middle of the domain)
        m_df_x(0),          // dfdx evaluated in the current result
        m_dx(0),            // current increment
        m_iter(0) {};    // start from it = 0

QuasiNewtonSolver::QuasiNewtonSolver(
    const BaseSolver &solver,
    double h,
    double toll_res,//std::numeric_limits<double>::epsilon()*1000,      // default value
    double toll_incr,//std::numeric_limits<double>::epsilon()*1000,     // default value
    unsigned int max_it) :   // initialization list, constructing the solver passing our parameters (d,df,tollres,tollincr,maxit)
        BaseSolver(solver),
        m_h(h),
        m_toll_res(toll_res),
        m_toll_incr(toll_incr),
        m_max_it(max_it),

        m_res(toll_res +1),
        m_x((m_xf+m_x0)/2),             // current guess for the result (middle of the domain)
        m_df_x(0),          // dfdx evaluated in the current result
        m_dx(0),            // current increment
        m_iter(0) {};    // start from it = 0




void QuasiNewtonSolver::solve()  {
    std::cout<< "Solving Quasinewton"<<std::endl;
    for (unsigned int m_iter = 0; m_iter < m_max_it; ++m_iter){
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

    std::cout<< "Max iterations done"<<std::endl;
    

}
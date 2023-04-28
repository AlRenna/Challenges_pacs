#ifndef NEWTON_HPP
#define NEWTON_HPP

#include <functional>
#include <cmath>
#include <iostream>
#include <limits>

class NewtonSolver{
public:
    // constructor: all initialized to 0
    NewtonSolver(
        const std::function<double(const double &)> &f,
        const std::function<double(const double &)> &df,
        const double x0,
        const double xf,
        double toll_res = std::numeric_limits<double>::epsilon()*1000,      // default value
        double toll_incr = std::numeric_limits<double>::epsilon()*1000,     // default value
        unsigned int max_it = 100
    )
    :   // initialization list, constructing the solver passing our parameters (d,df,tollres,tollincr,maxit)
    m_f(f),
    m_df(df),
    m_toll_res(toll_res),
    m_toll_incr(toll_incr),
    m_max_it(max_it),
    m_x0(x0),
    m_xf(xf),

    m_x((x0+xf)/2),             // current guess for the result
    m_df_x(0),          // dfdx evaluated in the current result
    m_dx(0),            // current increment
    m_iter(0) {}        // start from it = 0

    double get_result() const { return m_x; }           // returns current evaluation for the result (zero of f)
    unsigned int get_iter() const { return m_iter; }
    double get_residual() const { return m_res; }

    void solve(double x0){  // netwon solver implementation
        m_x = x0;           // first guess
        for (m_iter = 0; m_iter < m_max_it; ++m_iter){
            m_res = m_f(m_x);       // function evaluated in the current point
            if (std::abs(m_res) < m_toll_res)
                break;
            m_df_x = m_df(m_dx);
            m_dx = m_res / m_df_x;
            m_x -= m_dx;                // m_dx = m_x(k) - m_x(k+1)
            if (std::abs(m_dx) < m_toll_incr)       // if the step is smaller then our toll_incr
                break;
        }
    }

private:
    // m_ stands for "member of the class", see the constructor
    const std::function<double(double)> m_f;
    const std::function<double(double)> m_df;
    const double m_toll_res;
    const double m_toll_incr;
    const unsigned int m_max_it;
    const double m_x0;
    const double m_xf;
    // current values, members that change depending on the iteration:
    double m_x;     // current guess for the zero
    double m_df_x;  // current value of df/dx (x)
    double m_dx;    // current increment
    double m_res;   // current residual
    double m_iter;  // current iteration

    
};



#endif  // NEWTON_HPP~~~~~~~~~~~~~~~~~~
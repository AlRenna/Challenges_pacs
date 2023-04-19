#ifndef NEWTON_HPP
#define NEWTON_HPP

#include <functional>
#include <limits>
#include <memory>
#include "Solver.hpp"
#include "FactoryTraits.hpp"

using T=SolverTraits;

namespace Zeros
{
class NewtonSolver final: public BaseSolver
{
    public:
        // constructor: all initialized to 0
        NewtonSolver(
            const T::FunctionType &f,
            const T::FunctionType &df,
            double toll_res = std::numeric_limits<double>::epsilon()*1000, //T::Tolerance,      // default value
            double toll_incr = std::numeric_limits<double>::epsilon()*1000,     // default value
            unsigned int max_it = 1000
        )
        :   // initialization list, constructing the solver passing our parameters (d,df,tollres,tollincr,maxit)
        m_f(f),
        m_df(df),
        m_toll_res(toll_res),
        m_toll_incr(toll_incr),
        m_max_it(max_it) {};        

        double get_result() const { return m_x; }           // returns current evaluation for the result (zero of f)
        unsigned int get_iter() const { return m_iter; }
        double get_residual() const { return m_res; }

        void solve() override; // netwon solver implementation
            
        

    private:
        // m_ stands for "member of the class", see the constructor
        const std::function<double(double)> m_f;
        const std::function<double(double)> m_df;
        const double m_toll_res;
        const double m_toll_incr;
        const unsigned int m_max_it;
        // current values, members that change depending on the iteration:
        double m_x = 0;     // current guess for the zero
        double m_df_x = 0;  // current value of df/dx (x)
        double m_dx = 0;    // current increment
        double m_res = 0;   // current residual
        double m_iter = 0;  // current iteration
};

} // namespace Zeros


#endif  // NEWTON_HPP~~~~~~~~~~~~~~~~~~
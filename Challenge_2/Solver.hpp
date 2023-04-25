#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "SolverTraits.hpp"
#include <functional>
#include <memory>
#include <limits>
#include <iostream>


using T = SolverTraits;

namespace Zeros
{

    class BaseSolver{

        public:
            BaseSolver(); //TODO: make the default constructor

            BaseSolver(
                const T::FunctionType &f ,
                const T::VariableType &x0, 
                const T::VariableType &xf): 
                    m_f(f),
                    m_x0(x0),
                    m_xf(xf) {};

            virtual void solve();

            virtual ~BaseSolver();

        protected:
            const T::FunctionType m_f = [&] (T::ReturnType x) {return x - 2;}; 
            const T::VariableType m_x0 = 0;
            const T::VariableType m_xf = 1;

    };

/*
    class QuasiNewtonSolver final: public BaseSolver{

        public:
            QuasiNewtonSolver();

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


            void solve()  override;

            T::VariableType GetZero() {return m_x;};

        private:
            const double m_h = 0.05;
            const double m_toll_res  = std::numeric_limits<double>::epsilon()*1000;
            const double m_toll_incr  = std::numeric_limits<double>::epsilon()*1000;
            const unsigned int m_max_it = 1000;
            // current values, members that change depending on the iteration:
            double m_x = 0;     // current guess for the zero
            double m_df_x = 0;  // current value of df/dx (x)
            double m_dx = 0;    // current increment
            double m_res = 0;   // current residual
            unsigned int m_iter = 0;  // current iteration

    };

    class BisectionSolver final: public BaseSolver{

        public:
            void solve()  override;  

    };

    class SecantSolver final: public BaseSolver{

        public:
            void solve()  override;


    };
*/

} // namespace Zeros

#endif /* SOLVER_HPP */
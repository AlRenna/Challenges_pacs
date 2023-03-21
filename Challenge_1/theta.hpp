#ifndef THETA_METHOD
#define THETA_METHOD

#include "newton.hpp"
#include <array>
#include <vector>

class ThetaMethod{
private:
    const std::function<double(double, double)> m_f;    // function (member function)
    const std::function<double(double, double)> m_dfdx; // dfdx (member function)
    double m_t0;                                        // initial time step
    double m_tn;                                        // current time step
    double m_tf;                                        // final time step
    int m_N;                                            // number of time steps
    double m_y0;                                        // initial datum
    double m_yn;                                        // current solution
    std::array<std::vector<double>, 2> result;
public:
    ThetaMethod(  // constructor
        const std::function<double(double, double)> &f,         // function f
        const std::function<double(double, double)> &dfdx,      // dfdx
        double t0,                                      // initial time step, // SET DEFAULT 0!!!!!!!!!
        double tf,                                      // final time step
        int N,                                          // number of steps
        double y0                                       // initial datum
    )
    :             // initialization list
    m_f{f},
    m_dfdx{dfdx},
    m_t0{t0},
    m_tf{tf},
    m_N{N},
    m_y0{y0} {}

    std::array<std::vector<double>, 2> solve(double theta){
        std::array<std::vector<double>, 2> result;  // by def all init to 0
        // Initialize my vectors (time step, solution)
        result.at(0).emplace_back(m_t0);
        result.at(1).emplace_back(m_y0);
        m_yn = m_y0;
        m_tn = m_t0;
        // COMPUTE y(n+1) FOR EACH TIME STEP (x is the new y(n+1) ;) )
        for (int i = 1; i <= m_N; i++){
            double tnn {m_tn + m_tf/m_N};           // tnn := t(n+1) = t(n) + dt
            auto F = [&](double x){                 // by reference (catch 'em all! -cit.) 
                return x - m_tf/m_N*( theta*m_f(tnn,x) + (1 - theta)*m_f(m_tn,m_yn) ) - m_yn;
            };
            auto dF = [&](double x){                // by reference (catch 'em all! -cit. ) 
                return 1 - m_tf/m_N*( theta*m_dfdx(tnn,x) );
            };
            // NOW I NEED TO COMPUTE THE ZEROS OF F == y(n+1)
            const double toll_res = 1e-8;
            const double toll_incr = 1e-8;
            const unsigned int max_iter = 100;
            NewtonSolver Nsolver(F, dF, toll_res, toll_incr, max_iter);
            Nsolver.solve(m_yn);                        // as first guess i choose the previous m_yn
                                                        // m_yn will be updated with the new value --> m_yn+1
            m_yn = Nsolver.get_result();
            result.at(1).emplace_back(m_yn);
            m_tn = tnn;                                 // I update the current time step
            result.at(0).emplace_back(m_tn);
        }
        return result;
    }


};

#endif      // THETA_METHOD
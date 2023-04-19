#include "newton.hpp"

namespace Zeros{
void NewtonSolver::solve(){  // netwon solver implementation
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
namespace
{
  //! This will register the objects in the factory automatically when the
  //! library is loaded
  void __attribute__((constructor)) LoadF()
  {
    // add triangle and square to the factory
    solverFactory["Newton"] = []() { return std::make_unique<NewtonSolver>(); };
  }
} // namespace


} // namespace Zeros
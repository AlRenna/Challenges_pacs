#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "SolverTraits.hpp"

using T = SolverTraits;

class BaseSolver{

    public:
    virtual T::ReturnType solve() const;

    protected:
    const std::function<double(double)> &f;

};


///TODO: maybe we can also import the previous work we did for the newton solver and put it in the Examples/include folder
/*class NewtonSolver{

    public:
    ReturnType solve() override;

    protected:

    const std::function<double(double)> &f,



};*/
class QuasiNewtonSolver final: public BaseSolver{

    public:
    T::ReturnType solve() const override;

};

class BisectionSolver final: public BaseSolver{

    public:
    T::ReturnType solve() const override;  

};

class SecantSolver final: public BaseSolver{

    public:
    T::ReturnType solve() const override;


};

#endif /* SOLVER_HPP */
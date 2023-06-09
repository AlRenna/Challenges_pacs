#ifndef SOLVERTRAITS_HPP
#define SOLVERTRAITS_HPP

#include <functional>

class SolverTraits
{
    public:

    using ReturnType = double;
    using VariableType = double;
    using FunctionType = std::function<ReturnType(VariableType)>;
};


#endif /* SOLVERTRAITS_HPP */
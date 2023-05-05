# Advanced Programming for Scientific Computing
## Challenge 2: Build a hierarchy of solvers for f (x) = 0

### Team members:

Marzotto Mattia mattia.marzotto@mail.polimi.it

Renna Alessandro alessandro1.renna@mail.polimit.it

### Code:

Inside "SolverTraits.hpp", the 3 main used type are defined:
- VariableType;
- ReturnType;
- FunctionType.

In "Solver.hpp" we defined the solver classes, starting from an abstract base class called "BaseSolver".
The method "solve()" which returns a "ReturnType" is overloaded in each derived class and it's used to find the zero of the given function.

Inside "SolverFactory.hpp" a factory is implemented to select which derived class needs to be used.


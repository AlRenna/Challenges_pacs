#include "FactoryTraits.hpp"
#include "Solver.hpp"
#include "SolverFactory.hpp"
#include <dlfcn.h>
#include <iostream>

//
int
main()
{
  using namespace Zeros;
  using namespace std;
  // load the libraries (plugins)
  SolverFactory loadPlugins("plugins.txt");  ///TODO: CHANGE THE NAME OF THE CLASS AND FILE TO loadSolverFactory
  // Try the factory
  while(true)
    {
      string answer;
      cout << "Newton, QuasiNewton, Secant, Bisection or END?" << endl;
      cin >> answer;
      if(answer == "END")
        {
          break;
        }
      auto where = solverFactory.find(answer);
      if(where != solverFactory.end())
        {
          // Second entry of *where is the builder function!
          // I dereference it and I call the () operator: I get a Polygon
          auto theSolver = (where->second)();
          theSolver->solve();
        }
      else
        {
          cout << "ERROR: this solver is not registered!" << endl;
        }
    }
  // I need to clear the factory because otherwise it may be destroyed
  // after loadPolyFactory is closed. But then the object in the factory
  // are not loaded anymore: segmentation fault.
  //  polyFactory.clear();
}

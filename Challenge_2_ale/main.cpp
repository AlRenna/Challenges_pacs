# include "Solver.hpp"
#include "SolverFactory.hpp"

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <numbers>



int main(){
    auto f = [&](double x){
        // return 0.5 - exp(std::numbers::pi * x);
        return 0.5 - exp(2 * x);
    };
}
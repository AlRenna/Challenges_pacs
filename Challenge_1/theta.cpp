#include "theta.hpp"
#include <iostream>
#include <cmath>

int main(){
    auto f = [&](double t, double y){       // f is a function that takes two double t, y and returns a double
        return -t*exp(-y);    
        // return [](double t, std::function<double(double)> y){return -t*exp(-y(t));};    // return a f(t,y(t)) --> double
    };
    auto dfdy = [&](double t, double y){
        return t*exp(-y);
    };

    // auto f = [&](double t, double y){       // f is a function that takes two double t, y and returns a double
    //     return 1/(1+t*t) - 2*y*y;    
    //     // return [](double t, std::function<double(double)> y){return -t*exp(-y(t));};    // return a f(t,y(t)) --> double
    // };
    // auto dfdy = [&](double t, double y){
    //     return - 4*y;
    // };

    double t0 = 0, tf = 5, y0 = 0;
    int N = 100;        
    ThetaMethod Tsolver(f,dfdy,t0,tf,N,y0);
    auto result = Tsolver.solve(0.5);
    std::cout << "n\t|\ty(tn)" << std::endl;
    std::cout << "----------------------" << std::endl;
    for(size_t i{0}; i < result.at(0).size(); i++){
        std::cout << result.at(0).at(i) << "\t|\t" << result.at(1).at(i) << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
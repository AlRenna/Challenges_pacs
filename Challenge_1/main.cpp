#include "theta.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

int main(){

    auto f = [&](double t, double y){
        return -t*exp(-y);    
    };
    auto dfdy = [&](double t, double y){
        return t*exp(-y);
    };

    double t0 = 0, tf = 1, y0 = 0, theta = 0.5;
    int N = 100;        
    ThetaMethod Tsolver(f,dfdy,t0,tf,N,y0);
    auto result = Tsolver.solve(theta);
    
    // OUTPUT TO TEXT FILE
    std::fstream out_result{"./result.txt", std::ios::out};
    if (!out_result){
        std::cerr << " File open error " << std::endl;
        return 1;           // exit the main
    } else {                // write to the output file
        out_result << std::setw(10) << std::left << "t,y(t)" << std::endl;
        for(size_t i{0}; i < result.at(0).size(); i++){
            out_result << result.at(0).at(i) << "," << result.at(1).at(i) << "\n";
        }
    }
    out_result.close();

    return 0;
}
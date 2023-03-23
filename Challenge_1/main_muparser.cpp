#include "theta.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

#include "muparser_fun.hpp"
#include <GetPot>




int main(int argc, char **argv){

    GetPot datafile("data.txt");

    const std::string fun_str  = datafile("fun", "-t*exp(-y)");
    const std::string dfun_str = datafile("dfun", "t*exp(-y)");

    MuparserFun fun(fun_str), dfdy(dfun_str);

    const int n_max_it = datafile("n_max_it", 100);
    double       t0  = datafile("t0", 0.0);
    double       tf   = datafile("tf", 1.0);
    double       theta   = datafile("theta", 0.5);
    double       y0   = datafile("y0", 0.0);
    const std::string  filename = datafile("filename", "data.txt");

    ThetaMethod Tsolver(fun,dfdy,t0,tf,n_max_it,y0);
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
/*
 * FactoryTraits.hpp
 *
 *  Created on: Apr 29, 2020
 *      Author: forma
 */

#ifndef FACTORYTRAITS_HPP_
#define FACTORYTRAITS_HPP_
#include "Solver.hpp"
#include <functional>
#include <map>
#include <memory>
#include <string>
namespace Zeros
{
//! The way I build a Solver object
using SolverBuilder = std::function<std::unique_ptr<Zeros::BaseSolver>()>;
//! The identifier used
using SolverId = std::string;
//! The factory, just a map!
using SolverFactory = std::map<SolverId, SolverBuilder>;
//! The object storing the factory. Defined in the source file (must be stored
//! in a shared lib)
extern SolverFactory solverFactory;
} // namespace Zeros

#endif /* FACTORYTRAITS_HPP_ */

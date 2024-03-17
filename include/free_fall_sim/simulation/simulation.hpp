/**
 * Contains the declaration of simulation utilities.
 *
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <free_fall_sim/body/SphericalBody1D.hpp>
#include <free_fall_sim/gravity/GravitationalModel1D.hpp>

#include <limits>

namespace free_fall_sim
{

namespace simulation
{

/**
 * Runs a step of the simulation based on simulation parameters.
 */
template<typename T, typename = std::enable_if_t<std::numeric_limits<T>::is_iec559>>
void
SimulateStep(
  gravity::GravitationalModel1D<T> const & gravitationalModel,
  body::SphericalBody1D<T> & body,
  T fluidDensity,
  T timeStep);

/**
 * Runs a full simulation based on simulation parameters.
 */
template<typename T, typename = std::enable_if_t<std::numeric_limits<T>::is_iec559>>
void
Simulate(
  gravity::GravitationalModel1D<T> gravitationalModel,
  body::SphericalBody1D<T> body,
  T fluidDensity,
  T timeStep,
  T timeFinish);

/**
 * Runs a full simulation based on simulation parameters.
 */
template<typename T, typename G, typename = std::enable_if_t<std::numeric_limits<T>::is_iec559>>
void
Simulate(G gravitationalModel, body::SphericalBody1D<T> body, T fluidDensity, T timeStep, T timeFinish);

}

}

#include "./impl/simulation.inl"

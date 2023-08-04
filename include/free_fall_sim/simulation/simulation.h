/**
 * Contains the declaration of simulation utilities.
 *
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <free_fall_sim/body/SphericalBody1D.h>
#include <free_fall_sim/gravity/GravitationalModel1D.h>

#include <type_traits>

namespace free_fall_sim
{

namespace simulation
{

/**
 * Runs a step of the simulation based on simulation parameters.
 */
template<typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
void
SimulateStep(
  gravity::GravitationalModel1D<T> const & gravitationalModel,
  body::SphericalBody1D<T> & body,
  T fluidDensity,
  T timeStep);

/**
 * Runs a full simulation based on simulation parameters.
 */
template<typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
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
template<typename T, typename G, typename = std::enable_if_t<std::is_floating_point_v<T>>>
void
Simulate(G gravitationalModel, body::SphericalBody1D<T> body, T fluidDensity, T timeStep, T timeFinish);

}

}

#include "./impl/simulation.ipp"

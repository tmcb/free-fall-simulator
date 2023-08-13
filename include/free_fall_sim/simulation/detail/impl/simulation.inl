/**
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <free_fall_sim/simulation/detail/simulation.hpp>

namespace free_fall_sim
{

namespace simulation
{

namespace detail
{

template<typename T, typename>
[[nodiscard]] T
ComputeDragForce(T fluidDensity, T bodyDragCoefficient, T bodyVelocity, T bodyReferenceArea)
{
#ifndef USE_ONE_HALF_FACTOR_ON_DRAG_FORCE_CALCULATION
  // XXX why is it not divided by 2?
  return fluidDensity * bodyDragCoefficient * bodyReferenceArea * bodyVelocity * bodyVelocity;
#else
  return static_cast<T>(0.5) * fluidDensity * bodyDragCoefficient * bodyReferenceArea * bodyVelocity * bodyVelocity;
#endif
}

}

}

}

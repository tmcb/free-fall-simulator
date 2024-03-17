/**
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <limits>

namespace free_fall_sim
{

namespace simulation
{

namespace detail
{

template<typename T, typename = std::enable_if_t<std::numeric_limits<T>::is_iec559>>
[[nodiscard]] T
ComputeDragForce(T fluidDensity, T bodyDragCoefficient, T bodyVelocity, T bodyReferenceArea);

}

}

}

#include "./impl/simulation.inl"

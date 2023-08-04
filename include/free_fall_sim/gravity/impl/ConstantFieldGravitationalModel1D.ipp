/**
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <free_fall_sim/gravity/ConstantFieldGravitationalModel1D.h>

namespace free_fall_sim
{

namespace gravity
{

template<typename T, typename U>
[[nodiscard]] T
ConstantFieldGravitationalModel1D<T, U>::ComputeWeightForce(T bodyMass) const
{
  return m_gravitationalAcceleration * bodyMass;
}

}

}

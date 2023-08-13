/**
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <free_fall_sim/gravity/NewtonianGravitationalModel1D.hpp>

namespace free_fall_sim
{

namespace gravity
{


template<typename T, typename U>
[[nodiscard]] T
NewtonianGravitationalModel1D<T, U>::ComputeWeightForce(T bodyMass, T bodyHeight) const
{
  auto numerator = m_gravitationalConstant * m_planetMass * bodyMass;
  auto denominator = (m_planetRadius + bodyHeight) * (m_planetRadius + bodyHeight);

  return numerator / denominator;
}

}

}

/**
 * Contains the declaration of a gravitational model with constant acceleration.
 *
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <type_traits>

namespace free_fall_sim
{

namespace gravity
{

/**
 * A gravitational model with constant acceleration.
 */
template<typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
class ConstantFieldGravitationalModel1D
{
public:

  explicit
  ConstantFieldGravitationalModel1D(T gravitationalAcceleration)
  : m_gravitationalAcceleration{gravitationalAcceleration}
  {}

  [[nodiscard]] T
  ComputeWeightForce(T bodyMass) const;

private:

  T const m_gravitationalAcceleration;
};

}

}

#include "./impl/ConstantFieldGravitationalModel1D.ipp"

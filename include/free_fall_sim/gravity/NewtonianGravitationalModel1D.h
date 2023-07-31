/**
 * Contains the declaration of a Newtonian gravitational model.
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
 * A Newtonian gravitational model.
 */
template<typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
class NewtonianGravitationalModel1D
{
public:

  explicit
  NewtonianGravitationalModel1D(T gravitationalConstant, T planetMass, T planetRadius)
  : m_gravitationalConstant{gravitationalConstant}
  , m_planetMass{planetMass}
  , m_planetRadius{planetRadius}
  {}

  [[nodiscard]] T
  ComputeWeightForce(T bodyMass, T bodyHeight) const;

private:

  T const m_gravitationalConstant;

  T const m_planetMass;

  T const m_planetRadius;
};

}

}

#include "./impl/NewtonianGravitationalModel1D.ipp"

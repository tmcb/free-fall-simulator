/**
 * Contains the declaration of an one-dimensional spherical body.
 *
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <numbers>
#include <type_traits>

namespace free_fall_sim
{

namespace body
{

/**
 * An one-dimensional spherical body.
 */
template<typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
class SphericalBody1D
{
public:

  explicit
  SphericalBody1D(T radius, T mass, T dragCoefficient, T acceleration, T velocity, T position)
  : m_radius{radius}
  , m_mass{mass}
  , m_dragCoefficient{dragCoefficient}
  , m_acceleration{acceleration}
  , m_velocity{velocity}
  , m_position{position}
  {}

  void
  ApplyForce(T force, T timeDelta);

  [[nodiscard]] T
  GetRadius() const;
  
  [[nodiscard]] T
  GetMass() const;

  [[nodiscard]] T
  GetDragCoefficient() const;

  [[nodiscard]] T
  GetAcceleration() const;

  [[nodiscard]] T
  GetVelocity() const;

  [[nodiscard]] T
  GetPosition() const;

  [[nodiscard]] T
  ComputeReferenceArea() const;

private:

  T const m_radius;

  T const m_mass;

  T m_dragCoefficient;

  T m_acceleration;

  T m_velocity;

  T m_position;
};

}

}

#include "./impl/SphericalBody1D.ipp"

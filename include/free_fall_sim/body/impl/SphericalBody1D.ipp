/**
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <free_fall_sim/body/SphericalBody1D.h>

namespace free_fall_sim
{

namespace body
{

template<typename T, typename U>
inline void
SphericalBody1D<T, U>::ApplyForce(T force, T timeDelta)
{
  m_acceleration = force / m_mass;
  m_velocity += m_acceleration * timeDelta;
  m_position += m_velocity * timeDelta + 0.5 * m_acceleration * timeDelta * timeDelta;

  // XXX no bouncing
  if (m_position <= m_radius)
  {
    m_acceleration = static_cast<T>(0.0);
    m_velocity = static_cast<T>(0.0);
    m_position = static_cast<T>(m_radius);
  }
}

template<typename T, typename U>
[[nodiscard]] inline T
SphericalBody1D<T, U>::GetRadius() const
{
  return m_radius;
}

template<typename T, typename U>
[[nodiscard]] inline T
SphericalBody1D<T, U>::GetMass() const
{
  return m_mass;
}

template<typename T, typename U>
[[nodiscard]] inline T
SphericalBody1D<T, U>::GetDragCoefficient() const
{
  return m_dragCoefficient;
}

template<typename T, typename U>
[[nodiscard]] inline T
SphericalBody1D<T, U>::GetAcceleration() const
{
  return m_acceleration;
}

template<typename T, typename U>
[[nodiscard]] inline T
SphericalBody1D<T, U>::GetVelocity() const
{
  return m_velocity;
}

template<typename T, typename U>
[[nodiscard]] inline T
SphericalBody1D<T, U>::GetPosition() const
{
  return m_position;
}

template<typename T, typename U>
[[nodiscard]] inline T
SphericalBody1D<T, U>::ComputeReferenceArea() const
{
  return std::numbers::pi_v<T> * m_radius * m_radius;
}

}

}

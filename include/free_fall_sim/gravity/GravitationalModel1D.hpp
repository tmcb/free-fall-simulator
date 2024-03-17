/**
 * Contains an alias to a type that holds all supported gravitational models.
 *
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <free_fall_sim/gravity/ConstantFieldGravitationalModel1D.hpp>
#include <free_fall_sim/gravity/NewtonianGravitationalModel1D.hpp>

#include <limits>
#include <variant>

namespace free_fall_sim
{

namespace gravity
{

/**
 * Variant that holds all supported gravitational models.
 */
template<typename T, typename = std::enable_if_t<std::numeric_limits<T>::is_iec559>>
using GravitationalModel1D = std::variant<ConstantFieldGravitationalModel1D<T>, NewtonianGravitationalModel1D<T>>;

}

}

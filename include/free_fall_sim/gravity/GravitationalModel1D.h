/**
 * Contains an alias to a type that holds all supported gravitational models.
 *
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <free_fall_sim/gravity/ConstantFieldGravitationalModel1D.h>
#include <free_fall_sim/gravity/NewtonianGravitationalModel1D.h>

#include <type_traits>
#include <variant>

namespace free_fall_sim
{

namespace gravity
{

/**
 * Variant that holds all supported gravitational models.
 */
template<typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
using GravitationalModel1D = std::variant<ConstantFieldGravitationalModel1D<T>, NewtonianGravitationalModel1D<T>>;

}

}

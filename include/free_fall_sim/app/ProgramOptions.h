/**
 * Contains the definition of the struture that holds the simulation program options.
 *
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <stdexcept>
#include <string>
#include <type_traits>

namespace free_fall_sim
{

namespace app
{

/**
 * Holds the simulation program options.
 */
template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
struct ProgramOptions
{
  T ballDragCoefficient;

  T ballInitialPosition;

  T ballInitialVelocity;

  T ballMass;

  T ballRadius;

  T fluidDensity;

  T gravityAcceleration;

  std::string gravityModel;

  T gravityUniversalConstant;

  T planetMass;

  T planetRadius;

  T timeFinish;

  T timeStep;
};

/**
 * Represents an exception to be thrown in case one or more program options are
 * invalid.
 */
class InvalidProgramOptionError : std::logic_error
{
public:
  using std::logic_error::logic_error;

  using std::logic_error::operator=;

  using std::logic_error::what;
};

/**
 * Validates program options provided in a @ ProgramOptions object.
 */
template<typename T>
void
ValidateProgramOptions(ProgramOptions<T> const & programOptions);

}

}

#include "./impl/ProgramOptions.ipp"

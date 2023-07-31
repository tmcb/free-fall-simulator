/**
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <free_fall_sim/app/ProgramOptions.h>

namespace free_fall_sim
{

namespace app
{

template<typename T>
void
ValidateProgramOptions(ProgramOptions<T> const & programOptions)
{
  if (programOptions.ballDragCoefficient <= static_cast<T>(0.0))
  {
    throw InvalidProgramOptionError{"ball drag coefficient must be > 0"};
  }
  else if (programOptions.ballMass <= static_cast<T>(0.0))
  {
    throw InvalidProgramOptionError{"ball mass must be > 0"};
  }
  else if (programOptions.ballRadius <= static_cast<T>(0.0))
  {
    throw InvalidProgramOptionError{"ball radius must be > 0"};
  }
  else if (programOptions.ballInitialPosition < programOptions.ballRadius)
  {
    throw InvalidProgramOptionError{"ball initial position must be greater than or equal to ball radius"};
  }
  else if (programOptions.fluidDensity <= static_cast<T>(0.0))
  {
    throw InvalidProgramOptionError{"fluid density must be > 0"};
  }
  else if (programOptions.gravityAcceleration <= static_cast<T>(0.0))
  {
    throw InvalidProgramOptionError{"gravity acceleration must be > 0"};
  }
  else if (programOptions.gravityModel != "constant" && programOptions.gravityModel != "newtonian")
  {
    throw InvalidProgramOptionError{"gravity model must be either \"constant\" or \"newtonian\""};
  }
  else if (programOptions.gravityUniversalConstant <= static_cast<T>(0.0))
  {
    throw InvalidProgramOptionError{"gravitational universal constant must be > 0"};
  }
  else if (programOptions.planetMass <= static_cast<T>(0.0))
  {
    throw InvalidProgramOptionError{"planet mass must be > 0"};
  }
  else if (programOptions.planetRadius <= static_cast<T>(0.0))
  {
    throw InvalidProgramOptionError{"planet radius must be > 0"};
  }
  else if (programOptions.timeStep <= static_cast<T>(0.0))
  {
    throw InvalidProgramOptionError{"time step must be > 0"};
  }
  else if (programOptions.timeFinish < programOptions.timeStep)
  {
    throw InvalidProgramOptionError{"finish time must be greater than or equal to time step"};
  }
}

}

}

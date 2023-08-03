/**
 * Contains the declaration of GUI main loop utilities.
 *
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

#include <free_fall_sim/body/SphericalBody1D.h>
#include <free_fall_sim/gravity/GravitationalModel1D.h>

namespace app
{

namespace gui
{

/**
 * Runs a GUI main loop step based on simulation parameters.
 */
int
DoGUIMainLoop(
  free_fall_sim::gravity::GravitationalModel1D<float> const & gravitationalModel,
  free_fall_sim::body::SphericalBody1D<float> & body,
  float & time,
  float timeStep,
  float fluidDensity);

}

}

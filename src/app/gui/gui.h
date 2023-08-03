/**
 * Contains the declaration of GUI utilities.
 *
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#pragma once

namespace free_fall_sim
{

namespace gui
{

/**
 * Draws a ball on the GUI.
 */
void
DrawBall(float radius, int numSlices, int numStacks);

/**
 * Draws a checkered plane on the GUI.
 */
void
DrawCheckeredPlane(float size, int numDivisions);

}

}

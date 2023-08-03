/**
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#include "./gui.h"

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION 1
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <array>
#include <cmath>
#include <numbers>

namespace free_fall_sim
{

namespace gui
{

void
DrawBall(float radius, int numSlices, int numStacks)
{
  for (int i = 0; i < numStacks; i++)
  {
    auto constexpr PI = std::numbers::pi_v<float>;

    GLfloat sphereDiffuse[] = {1.0f, 0.0f, 0.0f, 1.0f};

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sphereDiffuse);

    float stack0 = PI * (-0.5f + static_cast<float>(i) / numStacks);
    float stack1 = PI * (-0.5f + static_cast<float>(i + 1) / numStacks);
    float cosStack0 = std::cos(stack0);
    float sinStack0 = std::sin(stack0);
    float cosStack1 = std::cos(stack1);
    float sinStack1 = std::sin(stack1);

    glBegin(GL_TRIANGLE_STRIP);

    for (int j = 0; j <= numSlices; ++j)
    {
      float phi = 2.0f * PI * static_cast<float>(j) / numSlices;
      float cosPhi = std::cos(phi);
      float sinPhi = std::sin(phi);
      float x0 = cosPhi * cosStack0;
      float y0 = sinPhi * cosStack0;
      float z0 = sinStack0;
      float x1 = cosPhi * cosStack1;
      float y1 = sinPhi * cosStack1;
      float z1 = sinStack1;

      glNormal3f(x0, y0, z0);
      glVertex3f(radius * x0, radius * y0, radius * z0);
      glNormal3f(x1, y1, z1);
      glVertex3f(radius * x1, radius * y1, radius * z1);
    }

    glEnd();
  }
}

void
DrawCheckeredPlane(float size, int numDivisions)
{
  float step = size / static_cast<float>(numDivisions);

  for (int i = -numDivisions / 2; i < numDivisions / 2; ++i)
  {
    for (int j = -numDivisions / 2; j < numDivisions / 2; ++j)
    {
      auto getTileDiffuseColor = [i, j]() -> std::array<GLfloat, 4> {
        if ((i + j) % 2 == 0)
        {
          return {0.8f, 0.8f, 0.8f, 1.0f};
        }
        else
        {
          return {0.2f, 0.2f, 0.2f, 0.2f};
        }
      };

      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, getTileDiffuseColor().data());
      glBegin(GL_QUADS);
      glVertex3f(i * step, 0.0f, j * step);
      glVertex3f(i * step, 0.0f, (j + 1) * step);
      glVertex3f((i + 1) * step, 0.0f, (j + 1) * step);
      glVertex3f((i + 1) * step, 0.0f, j * step);
      glEnd();
    }
  }
}

}

}

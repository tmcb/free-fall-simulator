/**
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#include "./gui_main_loop.hpp"

#include "./gui.hpp"

#include <free_fall_sim/body/SphericalBody1D.hpp>
#include <free_fall_sim/gravity/GravitationalModel1D.hpp>
#include <free_fall_sim/simulation/simulation.hpp>

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION 1
#include <glut.h>
#else
#include <GL/glut.h>
#endif

#include <chrono>
#include <cmath>

namespace app
{

namespace gui
{

int
DoGUIMainLoop(
  free_fall_sim::gravity::GravitationalModel1D<float> const & gravitationalModel,
  free_fall_sim::body::SphericalBody1D<float> & body,
  float & time,
  float timeStep,
  float fluidDensity)
{
  static auto const ballTrueRadius = body.GetRadius();
  static auto const ballTrueInitialHeight = body.GetPosition();
  static auto const scaleFactor = 1000.0f / (ballTrueRadius + ballTrueInitialHeight);
  static auto const ballRadius = ballTrueRadius * scaleFactor;
  static auto const ballInitialHeight = ballTrueInitialHeight * scaleFactor;
  static auto startTime = std::chrono::high_resolution_clock::now();
  static auto lastUpdateDelta = std::chrono::duration<float>{};

  std::clog << "t=" << time << ", ";
  std::clog << "v=" << body.GetVelocity() << ", ";
  std::clog << "x=" << body.GetPosition() << ", ";
  std::clog << "a=" << body.GetAcceleration() << "\n";

  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);  // Enable lighting
  glEnable(GL_LIGHT0);  // Use light source 0

  float ballHeight = body.GetPosition() * scaleFactor;
  GLfloat lightPosition[] = {
    0.0f, 0.5f * (ballInitialHeight + ballRadius), std::sqrt(2.0f) * (ballInitialHeight + 2.0f * ballRadius), 0.0f};

  glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(
    // eye
    0.0f,
    0.5f * (ballInitialHeight + ballRadius),
    std::sqrt(2.0f) * (ballInitialHeight + 2.0f * ballRadius),
    // at
    0.0f,
    0.5f * (ballInitialHeight + ballRadius),
    0.0f,
    // up
    0.0f,
    1.0f,
    0.0f);
  glColor3f(1.0f, 0.0f, 0.0f);  // Set sphere color to red (R, G, B)
  DrawCheckeredPlane(4.0f * ballRadius, 2);
  glPushMatrix();
  glTranslatef(0.0f, ballHeight, 0.0f);
  DrawBall(ballRadius, 64, 64);
  glPopMatrix();

  auto endTime = std::chrono::high_resolution_clock::now();

  lastUpdateDelta += static_cast<decltype(lastUpdateDelta)>(endTime - startTime);

  startTime = std::chrono::high_resolution_clock::now();

  // XXX the simulation will not skip any steps, this might introduce a time drift
  while (lastUpdateDelta.count() >= timeStep)
  {
    free_fall_sim::simulation::SimulateStep(gravitationalModel, body, fluidDensity, timeStep);
    lastUpdateDelta -= std::chrono::duration<float>(timeStep);
    time += timeStep;
  }

  return 0;
}

}

}

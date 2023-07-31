/**
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#include <free_fall_sim/app/ProgramOptions.h>
#include <free_fall_sim/body/SphericalBody1D.h>
#include <free_fall_sim/gravity/GravitationalModel1D.h>
#include <free_fall_sim/gui/gui_main_loop.h>

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION 1
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <boost/program_options.hpp>

#include <cstdlib>
#include <iostream>
#include <type_traits>

using namespace free_fall_sim::app;

using namespace free_fall_sim::body;

using namespace free_fall_sim::gravity;

using namespace free_fall_sim::gui;

void
ResizeFramebufferCb(GLFWwindow* window, int width, int height)
{
  (void)window;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // FIXME far plane is hardcoded
  gluPerspective(45.0f, static_cast<double>(width) / static_cast<double>(height), 1.0f, 5000.0f);
}

template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
boost::program_options::options_description
ConfigureProgramOptions(ProgramOptions<T> & programOptions)
{
  namespace po = ::boost::program_options;

  po::options_description description("Options");

  description.add_options()
    ("help,h", "produce help message")
    ("ball-drag-coefficient",
      po::value<T>(&programOptions.ballDragCoefficient)->default_value(0.47f),
      "set ball drag coefficient (C_D)")
    ("ball-initial-position",
      po::value<T>(&programOptions.ballInitialPosition)->default_value(10.0f),
      "set ball initial position (x_0)")
    ("ball-initial-velocity",
      po::value<T>(&programOptions.ballInitialVelocity)->default_value(0.0f),
      "set ball initial velocity (v_0)")
    ("ball-mass",
      po::value<T>(&programOptions.ballMass)->default_value(1.0f),
      "set ball mass (m)")
    ("ball-radius",
      po::value<T>(&programOptions.ballRadius)->default_value(1.0f),
      "set ball radius (r)")
    ("fluid-density",
      po::value<T>(&programOptions.fluidDensity)->default_value(1.2041f),
      "set fluid density (\\rho)")
    ("gravity-acceleration",
      po::value<T>(&programOptions.gravityAcceleration)->default_value(9.807f),
      "set gravitational acceleration (g)")
    ("gravity-model",
      po::value<std::string>(&programOptions.gravityModel)->default_value("constant"),
      "set gravitational model: constant|newtonian")
    ("gravity-universal-constant",
      po::value<T>(&programOptions.gravityUniversalConstant)->default_value(6.6743e-11f),
      "set gravitational universal constant (G)")
    ("planet-mass",
      po::value<T>(&programOptions.planetMass)->default_value(5.972e+24f),
      "set planet mass (M)")
    ("planet-radius",
      po::value<T>(&programOptions.planetRadius)->default_value(6.371e+6f),
      "set planet radius (R)")
    ("time-finish",
      po::value<T>(&programOptions.timeFinish)->default_value(60.0f),
      "set time finish (T)")
    ("time-step",
      po::value<T>(&programOptions.timeStep)->default_value(0.02f),
      "set time step (\\Delta t)");

  return description;
}

int
main(int argc, char *argv[])
{
  namespace po = ::boost::program_options;

  ProgramOptions<float> programOptions{};
  po::variables_map variablesMap;
  auto optionsDescription = ConfigureProgramOptions(programOptions);

  try
  {
    po::store(po::parse_command_line(argc, argv, optionsDescription), variablesMap);
    po::notify(variablesMap);    
  }
  catch(po::error & e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    std::cerr << std::endl;
    std::cerr << optionsDescription << std::endl;

    std::exit(1);
  }

  if (variablesMap.count("help"))
  {
    std::cerr << optionsDescription << std::endl;

    std::exit(1);
  }

  try
  {
    ValidateProgramOptions(programOptions);
  }
  catch(InvalidProgramOptionError & e)
  {
    std::cerr << "Error: " << e.what() << std::endl;

    std::exit(1);
  }

  if (!glfwInit())
  {
    std::exit(1);
  }

  GLFWwindow* window = glfwCreateWindow(800, 600, "free fall simulator", nullptr, nullptr);

  if (!window)
  {
    glfwTerminate();

    std::exit(1);
  }

  glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
  glfwSetFramebufferSizeCallback(window, ResizeFramebufferCb);
  glfwMakeContextCurrent(window);
  glViewport(0, 0, 800, 600);

  int width, height;

  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // XXX far plane is hardcoded, `DoGUIMainLoop()` does the scaling
  gluPerspective(45.0f, static_cast<float>(width) / static_cast<float>(height), 1.0f, 5000.0);

  auto gravitationalModel = programOptions.gravityModel == "constant" ?
    GravitationalModel1D<float>{ConstantFieldGravitationalModel1D{programOptions.gravityAcceleration}} :
    GravitationalModel1D<float>{NewtonianGravitationalModel1D{
       programOptions.gravityUniversalConstant, programOptions.planetMass, programOptions.planetRadius}};
  auto body = SphericalBody1D{
    programOptions.ballRadius,
    programOptions.ballMass,
    programOptions.ballDragCoefficient,
    0.0f,
    programOptions.ballInitialVelocity,
    programOptions.ballInitialPosition};

  auto time = 0.0f;

  while (!glfwWindowShouldClose(window))
  {
    // FIXME simulation breaks for time steps >= 0.5f
    DoGUIMainLoop(gravitationalModel, body, time, programOptions.timeStep, programOptions.fluidDensity);
    glFlush();
    glfwSwapBuffers(window);
    glfwPollEvents();

    if (time >= programOptions.timeFinish)
    {
      glfwSetWindowShouldClose(window, true);
      break;
    }
  }

  glfwTerminate();

  return 0;
}

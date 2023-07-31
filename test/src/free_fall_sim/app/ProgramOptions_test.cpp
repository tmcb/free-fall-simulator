/**
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#include <free_fall_sim/app/ProgramOptions.h>

#include <gtest/gtest.h>

#include <limits>

using namespace free_fall_sim::app;

static ProgramOptions<double>
CreateCorrectProgramOptions()
{
  ProgramOptions<double> programOptions;

  programOptions.ballDragCoefficient = 0.47;
  programOptions.ballInitialPosition = 10.0;
  programOptions.ballInitialVelocity = 0.0;
  programOptions.ballMass = 1.0;
  programOptions.ballRadius = 1.0;
  programOptions.fluidDensity = 1.2041;
  programOptions.gravityAcceleration = 9.807;
  programOptions.gravityModel = std::string{"constant"};
  programOptions.gravityUniversalConstant = 6.6743e-11;
  programOptions.planetMass = 5.972e+24;
  programOptions.planetRadius = 6.371e+6;
  programOptions.timeFinish = 60.0;
  programOptions.timeStep = 0.02;

  return programOptions;
}

TEST(ProgramOptionsTest, ValidateProgramOptionsTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
}

TEST(ProgramOptionsTest, ValidateProgramOptionsBallDragOKTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.ballDragCoefficient = 1.0;
  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
}

TEST(ProgramOptionsTest, ValidateProgramOptionsBallDragWrongTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.ballDragCoefficient = 0.0;
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
}

TEST(ProgramOptionsTest, ValidateProgramOptionsBallMassOKTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.ballMass = 1.0;
  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
}

TEST(ProgramOptionsTest, ValidateProgramOptionsBallMassWrongTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.ballMass = 0.0;
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
}

TEST(ProgramOptionsTest, ValidateProgramOptionsBallRadiusOKTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.ballRadius = 1.0;
  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
}

TEST(ProgramOptionsTest, ValidateProgramOptionsBallRadiusWrongTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.ballRadius = 0.0;
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
}

TEST(ProgramOptionsTest, ValidateProgramOptionsBallInitialPositionOKTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.ballInitialPosition = programOptions.ballRadius;
  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
}

TEST(ProgramOptionsTest, ValidateProgramOptionsBallInitialPositionWrongTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.ballInitialPosition = programOptions.ballRadius;
  programOptions.ballInitialPosition -= std::numeric_limits<double>::epsilon();
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
}

TEST(ProgramOptionsTest, ValidateProgramOptionsFluidDensityOKTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.fluidDensity = 1.0;
  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
}

TEST(ProgramOptionsTest, ValidateProgramOptionsFluidDensityWrongTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.fluidDensity = 0.0;
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
}

TEST(ProgramOptionsTest, ValidateProgramOptionsGravityAccelerationOKTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.gravityAcceleration = 1.0;
  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
}

TEST(ProgramOptionsTest, ValidateProgramOptionsGravityAccelerationWrongTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.gravityAcceleration = 0.0;
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
}

TEST(ProgramOptionsTest, ValidateProgramOptionsGravityModelOKTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.gravityModel = std::string{"constant"};
  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
  programOptions.gravityModel = std::string{"newtonian"};
  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
}

TEST(ProgramOptionsTest, ValidateProgramOptionsGravityModelWrongTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.gravityModel = std::string{""};
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
  programOptions.gravityModel = std::string{"\n"};
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
  programOptions.gravityModel = std::string{"-"};
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
}

TEST(ProgramOptionsTest, ValidateProgramOptionsGravityUniversalConstantOKTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.gravityUniversalConstant = 1.0;
  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
}

TEST(ProgramOptionsTest, ValidateProgramOptionsGravityUniversalConstantWrongTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.gravityUniversalConstant = 0.0;
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
}

TEST(ProgramOptionsTest, ValidateProgramOptionsPlanetMassOKTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.planetMass = 1.0;
  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
}

TEST(ProgramOptionsTest, ValidateProgramOptionsPlanetMassWrongTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.planetMass = 0.0;
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
}

TEST(ProgramOptionsTest, ValidateProgramOptionsPlanetRadiusOKTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.planetRadius = 1.0;
  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
}

TEST(ProgramOptionsTest, ValidateProgramOptionsPlanetRadiusWrongTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.planetRadius = 0.0;
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
}

TEST(ProgramOptionsTest, ValidateProgramOptionsTimeStepOKTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.timeStep = 1.0;
  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
}

TEST(ProgramOptionsTest, ValidateProgramOptionsTimeStepWrongTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.timeStep = 0.0;
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
}

TEST(ProgramOptionsTest, ValidateProgramOptionsTimeFinishOKTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.timeFinish = programOptions.timeStep;
  EXPECT_NO_THROW(ValidateProgramOptions(programOptions));
}

TEST(ProgramOptionsTest, ValidateProgramOptionsTimeFinishWrongTest)
{
  ProgramOptions programOptions = CreateCorrectProgramOptions();

  programOptions.timeFinish = programOptions.timeStep;
  programOptions.timeFinish -= std::numeric_limits<double>::epsilon();
  EXPECT_THROW(ValidateProgramOptions(programOptions), InvalidProgramOptionError);
}

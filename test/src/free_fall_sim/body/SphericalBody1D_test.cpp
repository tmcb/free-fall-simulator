/**
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#include <free_fall_sim/body/SphericalBody1D.h>

#include <gtest/gtest.h>

#include <numbers>

using namespace free_fall_sim::body;

TEST(SphericalBody1DTest, ConstructorTest)
{
  SphericalBody1D body{0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

}

TEST(SphericalBody1DTest, GetRadiusTest)
{
  SphericalBody1D body{1.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  ASSERT_DOUBLE_EQ(body.GetRadius(), 1.0);
}

TEST(SphericalBody1DTest, GetMassTest)
{
  SphericalBody1D body{0.0, 2.0, 0.0, 0.0, 0.0, 0.0};

  ASSERT_DOUBLE_EQ(body.GetMass(), 2.0);
}

TEST(SphericalBody1DTest, GetDragCoefficientTest)
{
  SphericalBody1D body{0.0, 0.0, 3.0, 0.0, 0.0, 0.0};

  ASSERT_DOUBLE_EQ(body.GetDragCoefficient(), 3.0);
}

TEST(SphericalBody1DTest, GetAccelerationTest)
{
  SphericalBody1D body{0.0, 0.0, 0.0, 4.0, 0.0, 0.0};

  ASSERT_DOUBLE_EQ(body.GetAcceleration(), 4.0);
}

TEST(SphericalBody1DTest, GetVelocityTest)
{
  SphericalBody1D body{0.0, 0.0, 0.0, 0.0, 5.0, 0.0};

  ASSERT_DOUBLE_EQ(body.GetVelocity(), 5.0);
}

TEST(SphericalBody1DTest, GetPositionTest)
{
  SphericalBody1D body{0.0, 0.0, 0.0, 0.0, 0.0, 6.0};

  ASSERT_DOUBLE_EQ(body.GetPosition(), 6.0);
}

TEST(SphericalBody1DTest, ComputeReferenceAreaTest)
{
  SphericalBody1D bodyRadius0{0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  ASSERT_DOUBLE_EQ(bodyRadius0.ComputeReferenceArea(), 0.0);

  SphericalBody1D bodyRadius1{1.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  ASSERT_DOUBLE_EQ(bodyRadius1.ComputeReferenceArea(), std::numbers::pi_v<double>);

  SphericalBody1D bodyRadius2{2.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  ASSERT_DOUBLE_EQ(bodyRadius2.ComputeReferenceArea(), 4.0 * std::numbers::pi_v<double>);
}

// TODO expand test cases
#if 0
TEST(SphericalBody1DTest, ApplyForceTest)
{
  FAIL();
}
#endif

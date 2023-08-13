/**
 * @author Tadeu Bastos
 * @date 2023
 * @copyright GNU General Public License, Version 3 or later
 */

#include <free_fall_sim/gravity/NewtonianGravitationalModel1D.hpp>

#include <gtest/gtest.h>

using namespace free_fall_sim::gravity;

TEST(NewtonianGravitationalModel1DTest, ConstructorTest)
{
  NewtonianGravitationalModel1D{0.0, 0.0, 0.0};
}

// TODO expand test cases
#if 0
TEST(NewtonianGravitationalModel1DTest, ComputeWeightForceTest)
{
  FAIL();
}
#endif

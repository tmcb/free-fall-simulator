#pragma once

#include <free_fall_sim/simulation/simulation.h>

#include <free_fall_sim/simulation/detail/simulation.h>

#include <iostream>

namespace free_fall_sim
{

namespace simulation
{

using namespace body;

using namespace gravity;

template<typename T, typename>
void
SimulateStep(GravitationalModel1D<T> const & gravitationalModel, SphericalBody1D<T> & body, T fluidDensity, T timeStep)
{
  auto weightForceVisitor = [&body = std::as_const(body)](auto const & gravitationalModel)
  {
    using ModelType = std::decay_t<decltype(gravitationalModel)>;

    if constexpr (std::is_same_v<ModelType, ConstantFieldGravitationalModel1D<T>>)
    {
      return gravitationalModel.ComputeWeightForce(body.GetMass());
    }
    else if constexpr (std::is_same_v<ModelType, NewtonianGravitationalModel1D<T>>)
    {
      return gravitationalModel.ComputeWeightForce(body.GetMass(), body.GetPosition());
    }
    else
    {
      static_assert(!sizeof(ModelType *), "non-exhaustive visitor!");
    }
  };
  auto dragForce = detail::ComputeDragForce<T>(
    fluidDensity, body.GetDragCoefficient(), body.GetVelocity(), body.ComputeReferenceArea());
  auto weightForce = std::visit(weightForceVisitor, gravitationalModel);
  auto force = dragForce - weightForce;

  body.ApplyForce(force, timeStep);
}

template<typename T, typename>
inline void
Simulate(GravitationalModel1D<T> gravitationalModel, SphericalBody1D<T> body, T fluidDensity, T timeStep, T timeFinish)
{
  for (auto time = static_cast<T>(0.); time < timeFinish; time += timeStep)
  {
    std::clog << "t=" << time << ", ";
    std::clog << "v=" << body.GetVelocity() << ", ";
    std::clog << "x=" << body.GetPosition() << ", ";
    std::clog << "a=" << body.GetAcceleration() << "\n";

    SimulateStep(gravitationalModel, body, fluidDensity, timeStep);
  }
}

template<typename T, typename G, typename>
inline void
Simulate(G gravitationalModel, SphericalBody1D<T> body, T fluidDensity, T timeStep, T timeFinish)
{
  return Simulate(
    GravitationalModel1D<T>{std::move(gravitationalModel)}, body, fluidDensity, timeStep, timeFinish);
}

}

}

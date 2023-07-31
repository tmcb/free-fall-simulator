#find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(free_fall_sim_test
	src/free_fall_sim/app/ProgramOptions_test.cpp
	src/free_fall_sim/body/SphericalBody1D_test.cpp
	src/free_fall_sim/gravity/ConstantFieldGravitationalModel1D_test.cpp
	src/free_fall_sim/gravity/NewtonianGravitationalModel1D_test.cpp
	src/free_fall_sim/simulation/simulation_test.cpp
)

include_directories(${GTEST_INCLUDE_DIRS})

target_include_directories(free_fall_sim_test PRIVATE
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(free_fall_sim_test
	${CMAKE_CXX_STANDARD_LIBRARIES}
	${GTEST_BOTH_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT}
)

include(GoogleTest)

gtest_discover_tests(free_fall_sim_test)


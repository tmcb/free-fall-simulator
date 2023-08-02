find_package(GTest REQUIRED)

set(TEST_EXECUTABLE_NAME ${EXECUTABLE_NAME}_test)

add_executable(${TEST_EXECUTABLE_NAME}
	src/free_fall_sim/app/ProgramOptions_test.cpp
	src/free_fall_sim/body/SphericalBody1D_test.cpp
	src/free_fall_sim/gravity/ConstantFieldGravitationalModel1D_test.cpp
	src/free_fall_sim/gravity/NewtonianGravitationalModel1D_test.cpp
	src/free_fall_sim/simulation/simulation_test.cpp
)

include_directories(${GTEST_INCLUDE_DIRS})

target_include_directories(${TEST_EXECUTABLE_NAME} PRIVATE
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${TEST_EXECUTABLE_NAME}
	${CMAKE_CXX_STANDARD_LIBRARIES}
	${GTEST_BOTH_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT}
)

include(GoogleTest)

gtest_discover_tests(${TEST_EXECUTABLE_NAME})


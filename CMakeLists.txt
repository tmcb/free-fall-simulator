cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")

project(free_fall_sim)

set(SOURCES
	src/gui/gui.cpp
	src/gui/gui_main_loop.cpp
	src/app/main.cpp
)

add_executable(free_fall_sim ${SOURCES})

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
	set(OpenGL_GL_PREFERENCE "LEGACY")
endif()

find_package(Boost REQUIRED COMPONENTS program_options)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(
	${Boost_INCLUDE_DIR}
	${GLUT_INCLUDE_DIR}
	${OPENGL_INCLUDE_DIR}
)

target_include_directories(free_fall_sim PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(
	free_fall_sim
	${CMAKE_CXX_STANDARD_LIBRARIES}
	${Boost_LIBRARIES}
	${OPENGL_LIBRARIES}
	${GLUT_LIBRARIES}
	glfw  # FIXME cannot successfuly configure package GLFW; assume it is installed
)

enable_testing()

add_subdirectory(test)

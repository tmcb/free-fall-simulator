cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -fno-omit-frame-pointer -fsanitize=address,undefined")
set(CMAKE_CXXFLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

project(free_fall_sim)

set(EXECUTABLE_NAME ${CMAKE_PROJECT_NAME})
set(SOURCES
	src/app/gui/gui.cpp
	src/app/gui/gui_main_loop.cpp
	src/app/main.cpp
)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

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

target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(
	${EXECUTABLE_NAME}
	${CMAKE_CXX_STANDARD_LIBRARIES}
	${Boost_LIBRARIES}
	${OPENGL_LIBRARIES}
	glfw  # FIXME cannot successfuly configure package GLFW; assume it is installed
)

enable_testing()

add_subdirectory(test)

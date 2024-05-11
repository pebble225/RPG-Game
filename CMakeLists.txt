cmake_minimum_required(VERSION 3.22.0)

project(RPG-Game)

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/content.cpp
	src/renderer.cpp
	src/mesh.cpp
	src/ShaderProgram.cpp
	src/heightmap.cpp
	src/RPGmath.cpp
	src/RPGrandom.cpp
	dep/ignore/pebbleimgrenderer.cpp
)

add_subdirectory(dep/glfw)
add_subdirectory(dep/glew-cmake)
add_subdirectory(dep/glm)

add_definitions(-DGLEW_STATIC)
add_definitions(-D_DEBUG)

target_include_directories(${PROJECT_NAME}
	PUBLIC include
	PUBLIC dep/stb
	PUBLIC dep/ignore
	PUBLIC dep/PerlinNoise
)

target_link_libraries(${PROJECT_NAME}
	glfw
	libglew_static
	glm
	m
)
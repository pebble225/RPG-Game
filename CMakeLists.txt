cmake_minimum_required(VERSION 3.22.0)

project(RPG-Game)

find_package(Catch2 3 REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp
	src/content.cpp
	src/renderer.cpp
	src/mesh.cpp
	src/ShaderProgram.cpp
	src/heightmap.cpp
	src/RPGmath.cpp
	src/RPGrandom.cpp
	src/worldGenerator.cpp
	src/fileHandler.cpp
	src/chunkData.cpp
	src/chunkInstanceDB.cpp
	src/RPGcamera.cpp
	src/HorizontalWrappedTransform.cpp
	src/Vec2D.cpp
)

add_executable(tests src/test.cpp)

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

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

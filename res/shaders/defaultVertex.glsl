#version 330 core

layout (location = 0) in vec3 aPos;

uniform mat4 transform, camera, orthographic;

void main()
{
	gl_Position = orthographic * camera * transform * vec4(aPos, 1.0f);
}
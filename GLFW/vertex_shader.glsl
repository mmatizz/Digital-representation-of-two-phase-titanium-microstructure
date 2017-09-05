#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec3 aColor;

uniform float seedSize;

out vec3 fColor;

void main()
{
	vec2 position = { aPos[0]/1000, aPos[1]/1000 };
	gl_PointSize = seedSize;
    gl_Position = vec4(position, 0.0, 1.0);
    fColor = aColor;
}  
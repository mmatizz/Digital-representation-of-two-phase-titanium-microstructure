#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec3 aColor;

out vec3 fColor;

void main()
{
	vec2 position = { aPos[0]/500, aPos[1]/500 };
	gl_PointSize = 96.0;
    gl_Position = vec4(position, 0.0, 1.0);
    fColor = aColor;
}  
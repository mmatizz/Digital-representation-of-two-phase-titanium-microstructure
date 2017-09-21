#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>


#include <iostream>
#include "Shader.h"
#include "Mesh.h"
#include "Dimensions.h"

class MainRun
{
public:
	const static unsigned int SCR_WIDTH = 1000;
	const static unsigned int SCR_HEIGHT = 1000;

	MainRun();
	~MainRun();

	int runOpenGL();
};


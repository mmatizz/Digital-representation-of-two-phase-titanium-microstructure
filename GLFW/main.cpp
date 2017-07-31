#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>


#include <iostream>
#include "Shader.h"
#include "Mesh.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// settings
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

int main()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);


	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// configure global opengl state
	// -----------------------------
	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_DEPTH_TEST);


	// build and compile shaders
	// -------------------------
	Shader shader("vertex_shader.glsl", "fragment_shader.glsl");

	// generate a list of 100 quad locations/translation-vectors
	// ---------------------------------------------------------
	//
	//	// store instance data in an array buffer
	//	// --------------------------------------
	//	unsigned int instanceVBO;
	//	glGenBuffers(1, &instanceVBO);
	//	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	//	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * 10000, &translations[0], GL_STATIC_DRAW);
	//	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//
	//	// set up vertex data (and buffer(s)) and configure vertex attributes
	//	// ------------------------------------------------------------------
	//	float quadVertices[] = {
	//		// positions     // colors
	//		-0.01f,  0.01f,  1.0f, 0.0f, 0.0f,
	//	};
	//
	//	unsigned int quadVAO, quadVBO;
	//	glGenVertexArrays(1, &quadVAO);
	//	glGenBuffers(1, &quadVBO);
	//	glBindVertexArray(quadVAO);
	//	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	//	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
	//
	//	glEnableVertexAttribArray(0);
	//	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	//	glEnableVertexAttribArray(1);
	//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
	//
	//	// also set instance data
	//	glEnableVertexAttribArray(2);
	//	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO); // this attribute comes from a different vertex buffer
	//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	//	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//	glVertexAttribDivisor(2, 1); // tell OpenGL this is an instanced vertex attribute.

	float offset = 0, pos_x = 0, pos_y = 0;
	std::vector<Seed> seeds;
	for (int i = 0; i < 5; i++)
	{
		offset += 0.1f;
		pos_x = -0.1f + offset;
		pos_y = 0.1f;
		seeds.push_back(* new Seed(pos_x, pos_y, 255, 255, 255));
	}

	Mesh* mesh = new Mesh(seeds);


	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// render
		// ------
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// draw 100 instanced quads
		shader.use();
		//		glBindVertexArray(quadVAO);
		//		glDrawArraysInstanced(GL_POINTS, 0, 1, 10000); // 100 triangles of 6 vertices each
		//		glBindVertexArray(0);
		mesh->Draw(shader);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	//	glDeleteVertexArrays(1, &quadVAO);
	//	glDeleteBuffers(1, &quadVBO);

	glfwTerminate();
	return 0;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

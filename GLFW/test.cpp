#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>


#include <iostream>
#include "Shader.h"
#include "Mesh.h"
#include "Dimensions.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// settings
const static unsigned int SCR_WIDTH = 1000;
const static unsigned int SCR_HEIGHT = 1000;

//int main()
//{
//	// glfw: initialize and configure
//	// ------------------------------
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//
//	// glfw window creation
//	// --------------------
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//
//	// glad: load all OpenGL function pointers
//	// ---------------------------------------
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	// configure global opengl state
//	// -----------------------------
//	glEnable(GL_PROGRAM_POINT_SIZE);
//	glEnable(GL_DEPTH_TEST);
//
//
//	// build and compile shaders
//	// -------------------------
//	Shader shader("vertex_shader.glsl", "fragment_shader.glsl");
//
//	int count_x = 500;
//	int count_y = 500;
//
//	Dimensions* dimensions = new Dimensions(count_x, count_y, SCR_WIDTH, SCR_HEIGHT);
//
//
//
//	Mesh* mesh = new Mesh(dimensions, shader);
//
//	// render loop
//	// -----------
//	while (!glfwWindowShouldClose(window))
//	{
//		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		shader.use();
//
//
//		mesh->Draw(shader);
//
//		if (!mesh->IsPopulated()) {
//			mesh->PopulateSeeds();
//			mesh->UpdateMesh();
//			mesh->SetupMesh();
//
//			mesh->Draw(shader);
//
//
//		}
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	//	glDeleteVertexArrays(1, &quadVAO);
//	//	glDeleteBuffers(1, &quadVBO);
//
//	glfwTerminate();
//	return 0;
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that width and 
//	// height will be significantly larger than specified on retina displays.
//	glViewport(0, 0, width, height);
//}


//int runOpenGL()
//{
//	// glfw: initialize and configure
//	// ------------------------------
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//
//	// glfw window creation
//	// --------------------
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//
//	// glad: load all OpenGL function pointers
//	// ---------------------------------------
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	// configure global opengl state
//	// -----------------------------
//	glEnable(GL_PROGRAM_POINT_SIZE);
//	glEnable(GL_DEPTH_TEST);
//
//
//	// build and compile shaders
//	// -------------------------
//	Shader shader("vertex_shader.glsl", "fragment_shader.glsl");
//
//	int count_x = 500;
//	int count_y = 500;
//
//	Dimensions* dimensions = new Dimensions(count_x, count_y, SCR_WIDTH, SCR_HEIGHT);
//
//
//
//	Mesh* mesh = new Mesh(dimensions, shader);
//
//	// render loop
//	// -----------
//	while (!glfwWindowShouldClose(window))
//	{
//		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		shader.use();
//
//
//		mesh->Draw(shader);
//
//		if (!mesh->IsPopulated()) {
//			mesh->PopulateSeeds();
//			mesh->UpdateMesh();
//			mesh->SetupMesh();
//
//			mesh->Draw(shader);
//
//
//		}
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	//	glDeleteVertexArrays(1, &quadVAO);
//	//	glDeleteBuffers(1, &quadVBO);
//
//	glfwTerminate();
//	return 0;
//}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that width and 
//	// height will be significantly larger than specified on retina displays.
//	glViewport(0, 0, width, height);
//}

//int main()
//{
//	return 0;
//}
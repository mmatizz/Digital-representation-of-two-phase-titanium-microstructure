#include "MainRun.h"



MainRun::MainRun()
{
}


MainRun::~MainRun()
{
}

int MainRun::runOpenGL()
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

	int count_x = 500;
	int count_y = 500;

	Dimensions* dimensions = new Dimensions(count_x, count_y, SCR_WIDTH, SCR_HEIGHT);



	Mesh* mesh = new Mesh(dimensions, shader);

	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.use();


		mesh->Draw(shader);

		if (!mesh->IsPopulated()) {
			mesh->PopulateSeeds();
			mesh->UpdateMesh();
			mesh->SetupSeeds();

			mesh->Draw(shader);


		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//	glDeleteVertexArrays(1, &quadVAO);
	//	glDeleteBuffers(1, &quadVBO);

	glfwTerminate();
	return 0;
}

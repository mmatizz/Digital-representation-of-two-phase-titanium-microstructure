#pragma once
#include <glad/glad.h>
#include <vector>
#include "Seed.h"

class Shader;

class Mesh
{
public:
	// DATA
	std::vector<Seed> seeds;
	float *vertex;

	// FUNCTIONS
	Mesh(std::vector<Seed> seeds);
	~Mesh();

	void Draw(Shader shader);

	void BuildMesh(int meshSize);

private:
	// DATA
	GLuint VAO, VBO;

	// FUNCTIONS
	void setupMesh();
};


#pragma once
#include <glad/glad.h>
#include <vector>
#include "Seed.h"
#include "Dimensions.h"

class Shader;

class Mesh
{
public:
	// DATA
	std::vector<Seed> seeds;
	float *vertex;

	Dimensions* dimensions;
	GLfloat seedSize;

//	float seedSize;

	bool meshPopulated;
	GLint seedSizeUniformLocation;


	// FUNCTIONS
	Mesh(Dimensions *dimensions, Shader shader);
	~Mesh();

	void Draw(Shader shader);
	void SetupMesh();
	void ClearMesh();
	void UpdateMesh();
	void PopulateSeeds();
	void GenerateSeeds();
	bool IsPopulated();


private:
	// DATA
	GLuint VAO, VBO;

	// FUNCTIONS

};


#pragma once
#include <glad/glad.h>
#include <vector>
#include "Seed.h"
#include "Dimensions.h"
#include "Ellipse_Titanium.h"


class Shader;

class Mesh
{
public:
	// DATA
	std::vector<Seed> seeds;
	std::vector<Ellipse_Titanium> ellipses;
	float *vertex;
	float *ellipses_vertex;

	Dimensions* dimensions;
	GLfloat seedSize;

//	float seedSize;

	bool meshPopulated;
	GLint seedSizeUniformLocation;


	// FUNCTIONS
	Mesh(Dimensions *dimensions, Shader shader);
	~Mesh();

	void Draw(Shader shader);
	void ClearMesh();
	void UpdateMesh();

	void SetupSeeds();
	void PopulateSeeds();
	void GenerateSeeds();
	
	void SetupEllipses();
	void GenerateEllipses();
	void UpdateEllipses();

	void DrawEllipses(Shader shader);

	bool IsPopulated();


private:
	// DATA
	GLuint VAO, VBO_SEED;
	GLuint VAO_ELLIPSE, VBO_ELLIPSE;

	// FUNCTIONS

};


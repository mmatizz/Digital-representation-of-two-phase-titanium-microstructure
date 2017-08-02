#include "Mesh.h"
#include "Shader.h"


Mesh::Mesh(std::vector<Seed> seeds)
{
	this->seeds = seeds;

	vertex = new float[seeds.size() * 5];
	for(int i=0, j=0; i< seeds.size(); i++)
	{
		vertex[j++] = seeds[i].getPositionX();
		vertex[j++] = seeds[i].getPositionY();

		vertex[j++] = seeds[i].getColorR();
		vertex[j++] = seeds[i].getColorG();
		vertex[j++] = seeds[i].getColorB();

	}



	setupMesh();
}


Mesh::~Mesh()
{
}



void Mesh::setupMesh()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, seeds.size() * 5 * sizeof(float), vertex, GL_STATIC_DRAW);

	// vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5* sizeof(float), (void*)0);
	// vertex normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5* sizeof(float), (void*)(2 * sizeof(float)));

	glBindVertexArray(0);
}

void Mesh::Draw(Shader shader)
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, seeds.size());
}
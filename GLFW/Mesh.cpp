#include "Mesh.h"
#include "Shader.h"


Mesh::Mesh(std::vector<Seed> seeds)
{
	this->seeds = seeds;

	
//	for(int i=0, j=0; i< seeds.size(); i++)
//	{
////		vertex[j++] = seeds[i].getPositionX();
////		vertex[j++] = seeds[i].getPositionY();
////
////		vertex[j++] = seeds[i].getColorR();
////		vertex[j++] = seeds[i].getColorG();
////		vertex[j++] = seeds[i].getColorB();
//
//
//		vertex[j++] = 0 + 0.01*i;
//		vertex[j++] = 0;
//
//		vertex[j++] = 255;
//		vertex[j++] = 255;
//		vertex[j++] = 255;
//	}

	vertex = new float[10];
	vertex[0] = 0.0f;
	vertex[1] = 0.1f;
	vertex[2] = 1.0f;
	vertex[3] = 0.0f;
	vertex[4] = 1.0f;

	vertex[5] = 0.0f;
	vertex[6] = 0.5f;
	vertex[7] = 1.0f;
	vertex[8] = 0.0f;
	vertex[9] = 0.0f;

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
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

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
	glDrawArrays(GL_POINTS, 0, 2);
}
#include "Mesh.h"
#include "Shader.h"
#include "Moore.h"
#include <ctime>
#include <random>


Mesh::Mesh(Dimensions *dimensions, Shader shader)
{
	this->dimensions = dimensions;

	this->meshPopulated = false;

	this->seedSizeUniformLocation = glGetUniformLocation(shader.ID, "seedSize");

	
	ClearMesh();
	GenerateSeeds();
	UpdateMesh();
	SetupSeeds();
}

void Mesh::SetupSeeds()
{
	//SEEDS
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO_SEED);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_SEED);
	glBufferData(GL_ARRAY_BUFFER, seeds.size() * 5 * sizeof(float), vertex, GL_STATIC_DRAW);

	// vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5* sizeof(float), (void*)0);
	// vertex colors
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5* sizeof(float), (void*)(2 * sizeof(float)));

	glBindVertexArray(0);
}

void Mesh::Draw(Shader shader)
{
	glUniform1f(seedSizeUniformLocation, seedSize);
	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, seeds.size());
}

void Mesh::ClearMesh() {

	float seed_width = static_cast<float>(dimensions->scr_width * 2) / dimensions->countSeeds_width;
	float seed_height = static_cast<float>(dimensions->scr_height * 2) / dimensions->countSeeds_height;
	seedSize = (seed_width + seed_height) / 2;
	float pos_x = dimensions->scr_width * (-1.0f);
	float pos_y = dimensions->scr_height - seedSize;
	int id = 0;

	for (int i = 0; i < dimensions->countSeeds_height; i++)
	{
		for (int j = 0; j < dimensions->countSeeds_width; j++) {
			pos_x += seedSize;
			seeds.push_back(*new Seed(id, pos_x, pos_y, 1.0f, 1.0f, 1.0f, Dead));
			id++;
		}

		//return to left side
		pos_x = dimensions->scr_width * (-1.0f);

		//row down
		pos_y -= seedSize;
	}

	this->vertex = new float[seeds.size() * 5];
}

void Mesh::UpdateMesh()
{
	for (int i = 0, j = 0; i < seeds.size(); i++)
	{
		vertex[j++] = seeds[i].getPositionX();
		vertex[j++] = seeds[i].getPositionY();

		vertex[j++] = seeds[i].getOldColorR();
		vertex[j++] = seeds[i].getOldColorG();
		vertex[j++] = seeds[i].getOldColorB();

	}
}

void Mesh::PopulateSeeds()
{
	Neighbourhood* neighbourhood;
	neighbourhood = new Moore();
	neighbourhood->setDimensions(dimensions);



	for (int i = 0; i < dimensions->countSeeds_height; ++i)
	{
		for (int j = 0; j < dimensions->countSeeds_width; ++j)
		{
			neighbourhood->CheckNeighboursColor(seeds, i, j);
		}		
	}

	for (int i = 0; i < seeds.size(); ++i)
	{
		float* color = seeds[i].getNewColor();

		if (color != seeds[i].getOldColor())
			seeds[i].setOldColor(color[0], color[1], color[2]);
	}
}

void Mesh::GenerateSeeds()
{
	int position = 0;
	float r, g, b;

	//generating random positions
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, dimensions->countSeeds_width*dimensions->countSeeds_height - 1);


	for (int i = 0; i < 50; i++)
	{
		position = distribution(generator);
		r = ((double)rand() / (RAND_MAX));
		g = ((double)rand() / (RAND_MAX));
		b = ((double)rand() / (RAND_MAX));

		seeds[position].setOldColor(r, g, b);
		seeds[position].setNewColor(r, g, b);
		seeds[position].setState(Populated);
	}
}



bool Mesh::IsPopulated()
{
	for(int i=0; i<seeds.size(); i++)
	{
		if (seeds[i].getState() == Dead) 
			return false;
	}

	return true;
}


void Mesh::SetupEllipses()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO_ELLIPSE);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_ELLIPSE);
	glBufferData(GL_ARRAY_BUFFER, ellipses.size() * 5 * sizeof(float), ellipses_vertex, GL_STATIC_DRAW);

	// ellipse positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	// ellipse colors
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

	glBindVertexArray(0);
}

void Mesh::GenerateEllipses()
{
	ellipses.push_back(*new Ellipse_Titanium(0, 0, 0.0f, 0.0f));

	this->ellipses_vertex = new float[ellipses.size() * 5];
}

void Mesh::UpdateEllipses()
{
	for (int i = 0, j = 0; i < ellipses.size(); i++)
	{
		ellipses_vertex[j++] = ellipses[i].getPositionX();
		ellipses_vertex[j++] = ellipses[i].getPositionY();

		ellipses_vertex[j++] = ellipses[i].getColorR();
		ellipses_vertex[j++] = ellipses[i].getColorG();
		ellipses_vertex[j++] = ellipses[i].getColorB();

	}
}

void Mesh::DrawEllipses(Shader shader)
{
	glUniform1f(seedSizeUniformLocation, seedSize);
	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, ellipses.size());
}

Mesh::~Mesh()
{
}



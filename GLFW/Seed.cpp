#include "Seed.h"


Seed::Seed(float pos_x, float pos_y, float r, float g, float b)
{
	//Id++;
	Risen = false;
	oldSeed = nullptr;
	position = new float[2];
	color = new float[3];

	position[0] = pos_x; position[1] = pos_y;
	color[0] = r; color[1] = g; color[2] = b;
	
}

Seed::Seed()
{
	//Id++;
	Risen = false;
	position = new float[2];
	color = new float[3];
	oldSeed = nullptr;

	position[0] = 0.0; position[1] = 0.0;
	color[0] = 255; color[1] = 255; color[2] = 255;
	

}


Seed::~Seed()
{
}



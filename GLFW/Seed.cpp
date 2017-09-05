#include "Seed.h"


Seed::Seed(int id, float pos_x, float pos_y, float r, float g, float b, SeedState state)
{
	Id = id;
	newColor1 = new float[3];
	oldColor1 = new float[3];

	this->newColor = { r, g, b };
	this->vertex.Color = { r, g, b };
	this->vertex.Position = { pos_x, pos_y };
	this->state = state;

	newColor1[0] = r; newColor1[1] = g; newColor1[2] = b;
	oldColor1[0] = r; oldColor1[1] = g; oldColor1[2] = b;


}

Seed::Seed()
{
	newColor1 = new float[3];
	oldColor1 = new float[3];

	this->vertex.Color = { 1.0f, 1.0f, 1.0f };
	this->vertex.Position = { 0, 0 };
	this->newColor = { 1.0f, 1.0f, 1.0f };
	this->state = Dead;
	
	newColor1[0] = 1.0f; newColor1[1] = 1.0f; newColor1[2] = 1.0f;
	oldColor1[0] = 1.0f; oldColor1[1] = 1.0f; oldColor1[2] = 1.0f;

}

bool Seed::isWhite()
{
	if (oldColor1[0] == 1.0f && oldColor1[1] == 1.0f && oldColor1[2] == 1.0f)
		return true;

	return false;
}


Seed::~Seed()
{
}



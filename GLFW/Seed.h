#ifndef SEED_H
#define SEED_H

#include <glm/glm/glm.hpp>
#include <glad/glad.h>
#include "Vertex.h"
#include "SeedState.h"


class Seed
{
public:
	int Id;
	Seed(int id, float pos_x, float pos_y, float r, float g, float b, SeedState state);
	Seed();
	~Seed();

	void setOldColor(float r, float g, float b) { oldColor1[0] = r; oldColor1[1] = g; oldColor1[2] = b;}
	void setState(SeedState _state) { state = _state; }
	void setNewColor(float r, float g, float b) { newColor1[0] = r; newColor1[1] = g; newColor1[2] = b; }
	void setPosition(glm::vec2 position) { vertex.Position = position; }

	float getPositionX() { return vertex.Position[0]; }
	float getPositionY() { return vertex.Position[1]; }

	float getOldColorR() { return oldColor1[0]; }
	float getOldColorG() { return oldColor1[1]; }
	float getOldColorB() { return oldColor1[2]; }


	SeedState getState() { return state; }

	float* getNewColor() { return newColor1; }
	float* getOldColor() { return oldColor1; }

	bool isWhite();
private:

	Vertex vertex;
	SeedState state;
	glm::vec3 newColor;

	float *newColor1;
	float *oldColor1;

};

#endif

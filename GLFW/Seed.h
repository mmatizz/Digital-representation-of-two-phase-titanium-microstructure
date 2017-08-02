#ifndef SEED_H
#define SEED_H

#include <glm/glm/glm.hpp>
#include <glad/glad.h>
#include "Vertex.h"


class Seed
{
public:
	//static int Id;
	Seed(float pos_x, float pos_y, float r, float g, float b);
	Seed();
	~Seed();

	void setRisen(bool risen) { Risen = risen; }
	void setColor(float* color) { this->color = color; }
	void setOldSeed(Seed* seed) { oldSeed = seed; }
	void setPosition(float* pos);

	bool isRisen() { return Risen; }
	float* getColor() { return color; }
	Seed* getOldSeed() { return oldSeed; }

	float getPositionX() { return position[0]; }
	float getPositionY() { return position[1]; }

	float getColorR() { return color[0]; }
	float getColorG() { return color[1]; }
	float getColorB() { return color[2]; }


private:

	bool Risen;
	Seed* oldSeed;
	float* position;
	float* color;

};

#endif

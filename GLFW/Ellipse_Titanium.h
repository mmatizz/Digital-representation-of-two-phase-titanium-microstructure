#pragma once
#ifndef ELLIPSE_TITANIUM_H
#define ELLIPSE_TITANIUM_H

#include <cmath>

class Ellipse_Titanium
{
public:
	Ellipse_Titanium();
	Ellipse_Titanium(float _radiusX, float _radiusY, float _positionX, float _positionY);

	~Ellipse_Titanium();

	float getPositionX() { return positionX; }
	float getPositionY() { return positionY; }

	float getRadiusX() { return radiusX; }
	float getRadiusY() { return radiusY; }

	float getColorR() { return colorR; }
	float getColorG() { return colorG; }
	float getColorB() { return colorB; }



private:
	int id;

	float radiusX;
	float radiusY;

	float positionX;
	float positionY;

	float colorR;
	float colorG;
	float colorB;

	double deg2rad(double degrees) { return degrees * 4.0 * atan(1.0) / 180.0; }


};

#endif

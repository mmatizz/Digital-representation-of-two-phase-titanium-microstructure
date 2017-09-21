#include "Ellipse_Titanium.h"



Ellipse_Titanium::Ellipse_Titanium()
{
}

Ellipse_Titanium::Ellipse_Titanium(float _radiusX, float _radiusY, float _positionX, float _positionY)
{
	this->radiusX = _radiusX;
	this->radiusY = _radiusY;
	this->positionX = _positionX;
	this->positionY = _positionY;

	this->colorR = 1.0f;
	this->colorG = 1.0f;
	this->colorB = 0.0f;
}


Ellipse_Titanium::~Ellipse_Titanium()
{
}

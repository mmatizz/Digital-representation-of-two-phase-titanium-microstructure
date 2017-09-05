#pragma once
#include "Seed.h"
#include <vector>
#include "Dimensions.h"

class Neighbourhood
{
public:

	bool periodic = false;
	Dimensions* dimensions;

	virtual void CheckNeighboursColor(std::vector<Seed> &seeds, int i, int j) = 0;
	static bool isInside(int i, int row, int middle_position, Dimensions *dimensions);

	void setDimensions(Dimensions *dimensions) { this->dimensions = dimensions; }
	

};

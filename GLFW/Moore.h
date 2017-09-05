#pragma once

#ifndef MOORE_H
#define MOORE_H

#include "Neighbourhood.h"

class Dimensions;

class Moore: public Neighbourhood
{
public:
	Moore();
	~Moore();

	void CheckNeighboursColor(std::vector<Seed> &seeds, int i, int j) override;
};

#endif

#pragma once

#ifndef DIMENSIONS_H
#define DIMENSIONS_H

class Dimensions
{
public:
	int countSeeds_width;
	int countSeeds_height;
	int scr_width;
	int scr_height;

	Dimensions(int countSeeds_width, int countSeeds_height, int scr_width, int scr_height);
};

#endif
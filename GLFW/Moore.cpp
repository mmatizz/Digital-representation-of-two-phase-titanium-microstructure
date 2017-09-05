#include "Moore.h"
#include "Dimensions.h"


Moore::Moore()
{
}


Moore::~Moore()
{
}

void Moore::CheckNeighboursColor(std::vector<Seed> &seeds, int i, int j)
{
	int position = dimensions->countSeeds_height * i + j;
	std::vector<Seed> populated_seeds;


	if (seeds[position].getState() == Dead)
	{
		for (int y = position - dimensions->countSeeds_width - 1, countY = 0; countY < 3; y += dimensions->countSeeds_width , countY++)
		{
			for (int x = y, countX = 0; countX < 3; x++ , countX++)
			{
				if (!isInside(x, i, position, dimensions))
					continue;

				if (seeds[x].getState() == Populated && !seeds[x].isWhite())
				{
					seeds[position].setNewColor(seeds[x].getOldColorR(), seeds[x].getOldColorG(), seeds[x].getOldColorB());
					seeds[position].setState(Populated);
					return;
				}
			}
		}
	}
}

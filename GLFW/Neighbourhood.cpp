#include "Neighbourhood.h"
#include "Mesh.h"


bool Neighbourhood::isInside(int i, int row, int middle_position, Dimensions *dimensions)
{
	if (i < 0 || i > dimensions->countSeeds_width*dimensions->countSeeds_height) 
	{
		return false;
	} else 
	{
		//check if first in a row
		if (middle_position == dimensions->countSeeds_width*row)
		{
			if (i < dimensions->countSeeds_width*(row - 1) || i == dimensions->countSeeds_width*row - 1 || i == dimensions->countSeeds_width*(row + 1) - 1)
				return false;
		}
		//check if last in row
		else if (middle_position == dimensions->countSeeds_width*(row + 1) - 1)
		{
			if ((i == dimensions->countSeeds_width*row - 1) || i == dimensions->countSeeds_width*(row + 1) || i == dimensions->countSeeds_width*(row + 2))
				return false;
		}
	}

	return true;
}

#include "pch.h"
#include "Vertex.h"
/*Authors: Elliot Gong and Michael Xie
* Purpose: Update the Vertex's class 2 constructors.
* Restrictions: Must account for Vertex objects having different weights/costs.
* Date: 4/25/2022*/

/// <summary>
/// The parameterized constructor of the Vertex class.
/// </summary>
/// <param name="x">The vertex's x coordinate.</param>
/// <param name="y">The vertex's y coordinate.</param>
/// <param name="weightCost">The vertex's path cost/weight</param>
Vertex::Vertex(int x, int y, int weightCost)
{
	//Set the x and y coordinates, and give all the other members a default value.
	xPos = x;
	yPos = y;
	hCost = 0;
	gCost = 0;
	fCost = 0;
	weight = weightCost;
	parent = nullptr;
}
/// <summary>
/// The Vertex Class's default constructor.
/// </summary>
Vertex::Vertex()
{
	//Set all members to their default values.
	xPos = 0;
	yPos = 0;
	hCost = 0;
	gCost = 0;
	fCost = 0;
	weight = 1;
	parent = nullptr;
}
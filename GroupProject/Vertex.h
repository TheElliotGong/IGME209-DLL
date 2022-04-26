#pragma once
/*Authors: Elliot Gong and Michael Xie
* Purpose: Update the Vertex class to include a movement cost/weight variable.
* Restrictions: Must account for maze paths having different weights/costs.
* Date: 4/25/2022*/
class Vertex
{
	//All members and constructors are public.
	public:
		//Necessary members, like the coordinates, weight, heuristic-related costs, and 
		//a vertex's "parent" vertex.
		int xPos;
		int yPos;
		int hCost;
		int fCost;
		int gCost;
		int weight;
		Vertex* parent;
		//Default constructor
		Vertex();
		//Parameterized Constructor
		Vertex(int x, int y, int weightCost);
};


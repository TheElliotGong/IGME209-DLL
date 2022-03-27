#pragma once
/*Authors: Elliot Gong and Michael Xie
* Purpose: Declare a Vertex class that will represent a "spot" within a maze/Graph.
* Restrictions: Must have necessary members and methods in order for the vertex to 
* be used for A* pathfinding and storage in a graph/maze.
* Date: 3/25/2022*/
class Vertex
{
	//ALl members and constructors are public.
	public:
		//Necessary members, like the coordinates, heuristic-related costs, and 
		//a vertex's "parent" vertex.
		int xPos;
		int yPos;
		int hCost;
		int fCost;
		int gCost;
		Vertex* parent;
		//Default constructor
		Vertex();
		//Parameterized Constructor
		Vertex(int x, int y);
};


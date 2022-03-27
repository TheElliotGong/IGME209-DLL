#pragma once
class Vertex
{
	public:
		int xPos;
		int yPos;
		int hCost;
		int fCost;
		int gCost;
		Vertex* parent;

		Vertex();
		//Parameterized Constructor
		Vertex(int x, int y);
};


#pragma once
class Vertex
{
	public:
		int xPos;
		int yPos;
		int hCost;
		int fCost;
		int gCost;
		bool visited;
		Vertex();
		//Parameterized Constructor
		Vertex(int xPos, int yPos);
};


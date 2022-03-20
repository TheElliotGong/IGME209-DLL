#pragma once
class Vertex
{
	public:
		int xPos;
		int yPos;
		int heuristic;
		int lowestCost;
		bool visited;

		//Parameterized Constructor
		Vertex(int xPos, int yPos);
};


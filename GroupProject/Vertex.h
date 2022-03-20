#pragma once
class Vertex
{
	public:
		//Parameterized Constructor
		Vertex(int xPos, int yPos, int heuristic, int lowestCost, bool visited);
		int xPos;
		int yPos;
		int heuristic;
		int lowestCost;
		bool visited;

};


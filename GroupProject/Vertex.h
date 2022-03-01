#pragma once
class Vertex
{
	public:
		//Default constructor
		Vertex();
		//Parameterized Constructor
		Vertex(int xPos, int yPos, int heuristic, int lowestCost, bool visited);
		int xPos;
		int yPos;
		int heuristic;
		int lowestCost;
		bool visited;
};


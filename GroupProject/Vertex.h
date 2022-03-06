#pragma once
class Vertex
{
	public:
		//Default constructor
		Vertex();
		//Parameterized Constructor
		Vertex(int xPos, int yPos, int heuristic, int lowestCost, bool visited);
	private:
		//Member variables
		int xPos;
		int yPos;
		int heuristic;
		int lowestCost;
		bool visited;
};


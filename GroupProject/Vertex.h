#pragma once
class Vertex
{
	public:
		//Default constructor
		Vertex();
		//Parameterized Constructor
		Vertex(int xPos, int yPos, int heuristic, int lowestCost, bool visited);
		int GetX() { return xPos; }
		int GetY() {return yPos; }
		int GetHeuristic() { return heuristic; }
		int GetLowestCost() { return lowestCost; }
		bool GetVisited() { return visited; }
	private:
		//Member variables
		int xPos;
		int yPos;
		int heuristic;
		int lowestCost;
		bool visited;
};


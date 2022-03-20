#include "pch.h"
#include "Vertex.h"

Vertex::Vertex(int xPos, int yPos, int heuristic, int lowestCost, bool visited)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->heuristic = heuristic;
	this->lowestCost = lowestCost;
	this->visited = visited;
}
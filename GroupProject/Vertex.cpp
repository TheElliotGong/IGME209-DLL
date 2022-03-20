#include "pch.h"
#include "Vertex.h"

Vertex::Vertex()
{
	this->xPos = 0;
	this->yPos = 0;
	this->heuristic = 5;
	this->lowestCost = 0;
	this->visited = false;

}
Vertex::Vertex(int xPos, int yPos, int heuristic, int lowestCost, bool visited)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->heuristic = heuristic;
	this->lowestCost = lowestCost;
	this->visited = visited;
}
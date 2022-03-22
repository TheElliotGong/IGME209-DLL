#include "pch.h"
#include "Vertex.h"

Vertex::Vertex(int x, int y)
{
	xPos = x;
	yPos = y;
	heuristic = 0;
	lowestCost = 0;
	visited = false;
}

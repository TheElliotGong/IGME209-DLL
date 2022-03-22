#include "pch.h"
#include "Vertex.h"

Vertex::Vertex(int x, int y)
{
	xPos = x;
	yPos = y;
	hCost = 0;
	gCost = 0;
	fCost = 0;
	visited = false;
}
Vertex::Vertex()
{
	xPos = 0;
	yPos = 0;
	hCost = 0;
	gCost = 0;
	fCost = 0;
	visited = false;
}
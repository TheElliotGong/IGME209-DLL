#include "pch.h"
#include "Graph.h"

Graph::Graph(int width, int height, vector<vector<Vertex>> adjList, int** adjMatrix)
{
	this->width = width;
	this->height = height;
	this->adjList = adjList;
	this->adjMatrix = adjMatrix;
}

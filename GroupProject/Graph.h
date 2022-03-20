#pragma once
#include <vector>
#include <queue>
#include "Vertex.h"
using namespace std;

class Graph
{
	public:
		//Instantiate the adjacency list
		vector<vector<Vertex>> adjList;
		vector<Vertex> vertices;

		Graph(int width, int height, int** mazeData);
};


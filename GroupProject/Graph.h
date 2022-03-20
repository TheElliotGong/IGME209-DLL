#pragma once
#include <vector>
#include <queue>
#include "Vertex.h"
using namespace std;

class Graph
{
	public:
		Graph(int width, int height, vector<vector<Vertex>> adjList, int** adjMatrix);
		int width; 
		int height;
		//Instantiate the adjacency list
		vector<vector<Vertex>> adjList;
		//Instantiate the 2d matrix
		int** adjMatrix;
		
		
};


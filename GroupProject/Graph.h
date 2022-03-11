#pragma once
#include <vector>
#include "Vertex.h"
using namespace std;

class Graph
{
	public:
		Graph();
		Graph(int width, int height, vector<vector<Vertex*>> adjList,  );
    private:
		int width; 
		int height;
		//Instantiate the adjacency list
		vector<vector<Vertex*>> adjList;
		//Instantiate the 2d matrix
		int adjMatrix[];
		
};


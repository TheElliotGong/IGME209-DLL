#pragma once
#include <vector>
#include <queue>
#include "Vertex.h"
using namespace std;

class Graph
{
	public:
		//Instantiate the adjacency list
		vector<vector<Vertex*>> adjList;
		vector<Vertex*> vertices;
		priority_queue<Vertex*> openList;
		vector<Vertex*> closedList;
		Vertex* start;
		Vertex* current;
		Vertex* end;
		void AStar();
		
		Graph(int width, int height, int** mazeData);

};


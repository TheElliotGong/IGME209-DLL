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
		vector<Vertex*> openList;
		vector<Vertex*> closedList;
		Vertex* start;
		Vertex* current;
		Vertex* end;
		vector<Vertex*> AStar();
		bool FindVertex(vector<Vertex*> list, Vertex* vertex, int &index);
		Graph(int width, int height, int** mazeData);

};


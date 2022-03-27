#pragma once
#include <vector>
#include <queue>
#include "Vertex.h"
using namespace std;
/*Authors: Elliot Gong and Michael Xie
* Purpose: Declare a Graph class that will hold Vertex objects and perform A* pathfinding.
* Restrictions: Must have necessary members and methods in order to store vertices
* and perform A* pathfinding.
* Date: 3/25/2022
*/
class Graph
{
	//ALl members and constructors are public.
	public:
		//Create a normal vector to store all vertices, an adjacency list to store the 
		//vertices' neighbors.
		vector<vector<Vertex*>> adjList;
		vector<Vertex*> vertices;
		//Create an open list, closed, list, start, current, and end vertex for A* pathfinding.
		vector<Vertex*> openList;
		vector<Vertex*> closedList;
		Vertex* start;
		Vertex* current;
		Vertex* end;
		//Methods for pathfinding.
		vector<Vertex*> AStar();
		bool FindVertex(vector<Vertex*> list, Vertex* vertex, int &index);
		//Parameterized constructor
		Graph(int width, int height, int** mazeData);

};


#include "pch.h"
#include "Graph.h"
#include "Vertex.h"
Graph::Graph(int width, int height, int** mazeData)
{
	//Go through the 2D array that represents a maze, where '0's represent
	//path elements and '1's represent walls. So for every element containing 
	//the value '0', create a "Vertex" and add it to the vector that will hold 
	//all the available path spots in a maze.
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (mazeData[i][j] == 0)
			{
				Vertex* vertex = new Vertex(i, j);
				vertices.push_back(vertex);
			}
		}
	}
	//Then, take each vertex in the general vector, and give each of them their own 
	//vector, which holds all the potential neighbor vectors of that particular vertex.
	for (int p = 0; p < vertices.size(); p++)
	{
		adjList[p] = vector<Vertex*>();
	}
	//Loop through the 2D array/maze and validate the positions of possible neighbors
	//of each vertex in the general vector. Then add the neighbors to the corresponding 
	//vector associated with each vertex via the adjacency list.
	for (int k = 0; k < adjList.size(); k++)
	{
		for (int l = 0; l < vertices.size(); l++)
		{
			if ((vertices[l]->xPos == (vertices[k]->xPos - 1)) && (vertices[l]->yPos = vertices[k]->yPos))
			{
				adjList[k].push_back(vertices[k]);
			}
			else if ((vertices[l]->xPos == (vertices[k]->xPos + 1)) && (vertices[l]->yPos = vertices[k]->yPos))
			{
				adjList[k].push_back(vertices[k]);
			}
			else if ((vertices[l]->xPos == vertices[k]->xPos) && (vertices[l]->yPos = (vertices[k]->yPos - 1)))
			{
				adjList[k].push_back(vertices[k]);
			}
			else if ((vertices[l]->xPos == vertices[k]->xPos) && (vertices[l]->yPos = (vertices[k]->yPos + 1)))
			{
				adjList[k].push_back(vertices[k]);
			}
		}
	}
	start = nullptr;
	end = nullptr;
	current = nullptr;
	
}

void Graph::AStar()
{
	

	//First, add the current vertex to the closed list.
	//Note, at the beginning, the current vertex is also the start vertex.
	openList.push(start);
	current = start;
	//Set the current vertex's fcost.
	
	int pointer = 0;
	//Then, calculate the shortest path from start vertex to end vertex.
	while (openList.size() > 0)
	{
		for (Vertex* vertex : openList)
		{
			if (vertex->fCost < current->fCost)
			{
				current = vertex;
				
			}
		}
	}
}


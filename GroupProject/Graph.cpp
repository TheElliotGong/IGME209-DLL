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
				Vertex vertex = Vertex(i, j);
				vertices.push_back(vertex);
			}
		}
	}
	//Then, take each vertex in the general vector, and give each of them their own 
	//vector, which holds all the potential neighbor vectors of that particular vertex.
	for (int p = 0; p < vertices.size(); p++)
	{
		adjList[p] = vector<Vertex>();
	}
	//Loop through the 2D array/maze and validate the positions of possible neighbors
	//of each vertex in the general vector.
	for (int k = 0; k < adjList.size(); k++)
	{
		for (int l = 0; l < vertices.size(); l++)
		{
			if ((vertices[l].xPos == (vertices[k].xPos - 1)) && (vertices[l].yPos = vertices[k].yPos))
			{
				adjList[k].push_back(vertices[k]);
			}
			else if ((vertices[l].xPos == (vertices[k].xPos + 1)) && (vertices[l].yPos = vertices[k].yPos))
			{
				adjList[k].push_back(vertices[k]);
			}
			else if ((vertices[l].xPos == vertices[k].xPos) && (vertices[l].yPos = (vertices[k].yPos - 1)))
			{
				adjList[k].push_back(vertices[k]);
			}
			else if ((vertices[l].xPos == vertices[k].xPos) && (vertices[l].yPos = (vertices[k].yPos + 1)))
			{
				adjList[k].push_back(vertices[k]);
			}
		}
	}

	
}

void Graph::AStar()
{

}
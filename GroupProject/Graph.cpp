#include "pch.h"
#include "Graph.h"

Graph::Graph(int width, int height, int** mazeData)
{
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

	for (int p = 0; p < vertices.size(); p++)
	{
		adjList[p] = vector<Vertex>();
	}

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
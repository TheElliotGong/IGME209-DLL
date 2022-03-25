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
	//of each vertex in the general vector.
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

	
}

void Graph::AStar()
{
	//First, add the start vertex to the open list.
	for (int i = 0; i < vertices.size(); i++)
	{
		if ((vertices[i]->xPos == start->xPos) && (vertices[i]->yPos == start->yPos))
		{
			closedList.push_back(vertices[i]);
		}
	}

	current->fCost = 1000;
	int pointer = 0;
	//Then, calculate the shortest path from start vertex to end vertex.
	do
	{
		//Loop through the open list, which contains the current vertice's neighbors, 
		//and find the neighbor with the lowest score.
		for (int i = (openList.size() - 1); i > -1; i--)
		{
			//Make the neighbor with the lowest score the new current vertex.
			if (openList[i]->fCost < current->fCost)
			{
				current = openList[i];
				pointer = i;
			}
		}
		//Add current vertex to closed list and empty out the open list.
		closedList.push_back(current);
		openList.erase(openList.begin() + pointer);
		//Check if the end vertex has been reached in the closed list.
		for (int i = 0; i < closedList.size(); i++)
		{
			if ((closedList[i]->xPos == end->xPos) && (closedList[i]->yPos == end->yPos))
			{
				break;
			}
		}

		for (int i = 0; i < vertices.size(); i++)
		{
			if ((vertices[i]->xPos == current->xPos) && (vertices[i]->yPos == current->yPos))
			{
				for (int j = 0; j < adjList[i].size(); j++)
				{
					for (int k = (closedList.size() - 1); k > -1; k--)
					{
						//Check if neighbor is in closed list nad 
						if ((adjList[i][j]->xPos == closedList[k]->xPos) && (adjList[i][j]->yPos == closedList[k]->yPos))
						{
							if (closedList[k]->gCost > (current->gCost + 1))
							{
								closedList.erase(closedList.begin() + k);
							}
						}
						else
						{
							for (int p = 0; p < openList.size(); p++)
							{
								//Check if 
								if ((adjList[i][j]->xPos == openList[p]->xPos) && (adjList[i][j]->yPos == openList[p]->yPos))
								{
									if (openList[p]->gCost > (current->gCost + 1))
									{
										openList[p]->gCost = (current->gCost + 1);
										openList[p]->fCost = openList[p]->gCost + openList[p]->hCost;
									}
								}
								else
								{
									adjList[i][j]->hCost = abs(adjList[i][j]->xPos - end->xPos) + abs(adjList[i][j]->yPos - end->yPos);
									adjList[i][j]->gCost = (current->gCost + 1);
									adjList[i][j]->fCost = adjList[i][j]->gCost + adjList[i][j]->hCost;

									openList.push_back(adjList[i][j]);
								}
							}
						}
					}
				}
			}
		}

	} while (openList.size() != 0);
}
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
				vertices.push_back(new Vertex(i, j));
			}
		}
	}
	//Then, take each vertex in the general vector, and give each of them their own 
	//vector, which holds all the potential neighbor vectors of that particular vertex.
	for (int p = 0; p < vertices.size(); p++)
	{
		adjList.push_back(vector<Vertex*>());
	}
	//Loop through the 2D array/maze and validate the positions of possible neighbors
	//of each vertex in the general vector. Then add the neighbors to the corresponding 
	//vector associated with each vertex via the adjacency list.
	for (int k = 0; k < adjList.size(); k++)
	{
		for (int l = 0; l < vertices.size(); l++)
		{
			if ((vertices[l]->xPos == (vertices[k]->xPos - 1)) && (vertices[l]->yPos == vertices[k]->yPos))
			{
				adjList[k].push_back(vertices[l]);
			}
			else if ((vertices[l]->xPos == (vertices[k]->xPos + 1)) && (vertices[l]->yPos == vertices[k]->yPos))
			{
				adjList[k].push_back(vertices[l]);
			}
			else if ((vertices[l]->xPos == vertices[k]->xPos) && (vertices[l]->yPos == (vertices[k]->yPos - 1)))
			{
				adjList[k].push_back(vertices[l]);
			}
			else if ((vertices[l]->xPos == vertices[k]->xPos) && (vertices[l]->yPos == (vertices[k]->yPos + 1)))
			{
				adjList[k].push_back(vertices[l]);
			}
		}
	}
	start = nullptr;
	end = nullptr;
	current = nullptr;
	
}

vector<Vertex*> Graph::AStar()
{
	//First, add the current vertex to the closed list.
	//Note, at the beginning, the current vertex is also the start vertex.
	openList.push_back(start);
	start->gCost = 0;
	start->fCost = start->gCost + start->hCost;
	current = start;

	//Set the current vertex's fcost.
	int pointer = 0;
	int i = 0;

	//Then, calculate the shortest path from start vertex to end vertex.
	while (openList.empty() == false)
	{
		current = openList[0];
		i = 0;

		for (Vertex* vertex : openList)
		{
			if (vertex->fCost <= current->fCost)
			{
				current = vertex;
				pointer = i;
			}
			i++;
		}

		openList.erase(openList.begin() + pointer);
		closedList.push_back(current);

		if (closedList[closedList.size() - 1]->xPos == end->xPos && closedList[closedList.size() - 1]->yPos == end->yPos)
		{
			break;
		}

		for (int j = 0; j < vertices.size(); j++)
		{
			if (vertices[j]->xPos == current->xPos && vertices[j]->yPos == current->yPos)
			{
				for (Vertex* neighbor : adjList[j])
				{
					int cost = current->gCost + 1;

					if (FindVertex(openList, neighbor, pointer) == true && neighbor->gCost > cost)
					{
						openList.erase(openList.begin() + pointer);
					}
					else if (FindVertex(closedList, neighbor, pointer) == true && neighbor->gCost > cost)
					{
						closedList.erase(openList.begin() + pointer);
					}
					else if(FindVertex(openList, neighbor, pointer) == false && FindVertex(closedList, neighbor, pointer) == false)
					{
						neighbor->gCost = cost;
						neighbor->fCost = neighbor->gCost + neighbor->hCost;
						neighbor->parent = current;
						openList.push_back(neighbor);
					}
				}
			}
		}
	}

	if (FindVertex(closedList, end, pointer) == false)
	{
		closedList.clear();
		closedList.push_back(start);
	}

	vector<Vertex*> path;

	path.push_back(closedList[closedList.size() - 1]);

	while (path[path.size() - 1] != start)
	{
		path.push_back(path[path.size() - 1]->parent);
	}

	return path;
}

bool Graph::FindVertex(vector<Vertex*> list, Vertex* vertex, int &index)
{
	int i = 0;
	for (Vertex* node : list)
	{
		if (node->xPos == vertex->xPos && node->yPos == vertex->yPos)
		{
			index = i;
			return true;
		}
		i++;
	}
	return false;
}




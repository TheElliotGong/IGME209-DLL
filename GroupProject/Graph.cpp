#include "pch.h"
#include "Graph.h"
#include "Vertex.h"
/*Authors: Elliot Gong and Michael Xie
* Purpose: Initialize the Graph class that will store vertices and perform A* pathfinding.
* Restrictions: Must incorporate A* star pathfinding to find the shortest distance 
* between a 'start' and 'end' vertex.
* Date: 3/25/2022
*/

/// <summary>
/// This is the parameterized constructor for the Graph Class, which will represent a 2D maze.
/// </summary>
/// <param name="width">The width of the maze.</param>
/// <param name="height">The height of the maze.</param>
/// <param name="mazeData">The 2D array/double pointer holding the numeric representations of 
/// open positions and walls.</param>
Graph::Graph(int width, int height, int** mazeData)
{
	//Go through the 2D array that represents a maze, where '0's represent
	//walls and nonzeroes represent path elements. Each value corresponds to a 
	//path element's cost. So for every element that contains a nonzero value, 
	//create a "Vertex" and add it to the vector that will hold 
	//all the available path spots in a maze.
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (mazeData[i][j] != 0)
			{
				vertices.push_back(new Vertex(i, j, mazeData[i][j]));
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
	//Set start, end, and current vertices to nullptr.
	start = nullptr;
	end = nullptr;
	current = nullptr;
	
}
/// <summary>
/// This function performs A* pathfinding to determine the shortest path between 
/// the start and end vertex within a graph/maze.
/// </summary>
/// <returns>Returns a vector of Vertices that forms a "path" from start to end.</returns>
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
		//Set current to the lowest distance vector in open.
		for (Vertex* vertex : openList)
		{
			if (vertex->fCost <= current->fCost)
			{
				current = vertex;
				pointer = i;
			}
			i++;
		}
		//Remove the lowest distance/current vector from the open list, and 
		//add it to the closed list. 
		openList.erase(openList.begin() + pointer);
		closedList.push_back(current);
		//Check if the most recent vector in the closed list is the end vertex.
		//If so, then end the loop.
		if (closedList[closedList.size() - 1]->xPos == end->xPos && closedList[closedList.size() - 1]->yPos == end->yPos)
		{
			break;
		}
		//Loop through each of the current vertex's neighbors to see what to do with them.
		for (int j = 0; j < vertices.size(); j++)
		{
			if (vertices[j]->xPos == current->xPos && vertices[j]->yPos == current->yPos)
			{
				for (Vertex* neighbor : adjList[j])
				{
					//Calculate the cost from the start to one of the current vertex's neighbor.
					int cost = current->gCost + neighbor->weight;
					//If the neighbor is already in the open list and its distance from start is 
					//greater than the cost, remove it from the open list.
					if (FindVertex(openList, neighbor, pointer) == true && neighbor->gCost > cost)
					{
						openList.erase(openList.begin() + pointer);
					}
					//If the neighbor is already in the closed list and its distance from start is 
					//greater than the cost, remove it from the closed list.
					else if (FindVertex(closedList, neighbor, pointer) == true && neighbor->gCost > cost)
					{
						closedList.erase(openList.begin() + pointer);
					}
					//Otherwise, set the neighbor's g cost to the cost from the start to the current vertex.
					//Then, calculate the neighbor's f cost.
					//Set the neighbor's parent vertex to the current vertex, then make the neighbor the 
					//new current vertex.
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
	//See if the end vertex is in the closed list.
	if (FindVertex(closedList, end, pointer) == false)
	{
		//If it's not we clear closedlist and push start to indicate no path.
		closedList.clear();
		closedList.push_back(start);
	}
	//Create a vector that will hold the correct path from the start to the end.
	vector<Vertex*> path;

	//Push the end vertex into the path.
	path.push_back(closedList[closedList.size() - 1]);

	//While the path does not contain start.
	while (path[path.size() - 1] != start)
	{
		//Keep pushing the parent of the current vertex.
		path.push_back(path[path.size() - 1]->parent);
	}

	//Return vector of the path.
	return path;
}
/// <summary>
/// This method goes through a maze and finds the index of the desired vertex.
/// That index will coincide with the vertex's index in the adjacency list.
/// </summary>
/// <param name="list">The vector of vertices to check through.</param>
/// <param name="vertex">The desired vertex to find.</param>
/// <param name="index">The int variable that will hold the vertex's index within the adjacency list.</param>
/// <returns>returns a bool checking if the desired vertex is found.</returns>
bool Graph::FindVertex(vector<Vertex*> list, Vertex* vertex, int &index)
{
	int i = 0;
	//Loop through the vector and see if any of the vertices within that list
	//has the same coordinates as the vertex parameter.
	for (Vertex* node : list)
	{
		//If the vertex is within the vector, set the index parameter to the value of i and return true.
		if (node->xPos == vertex->xPos && node->yPos == vertex->yPos)
		{
			index = i;
			return true;
		}
		i++;
	}
	//Otherwise, return false.
	return false;
}




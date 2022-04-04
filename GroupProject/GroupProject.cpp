// GroupProject.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "GroupProject.h"
#include <vector>

/*Authors: Elliot Gong and Michael Xie
* Purpose: Instantiate functions and use the variables declared in the header.
* Restrictions: Must have functions store and tweak data for the maze.
* Date: 3/25/2022
*/

// This is an example of an exported variable
GROUPPROJECT_API int nGroupProject=0;

// This is an example of an exported function.
GROUPPROJECT_API int fnGroupProject(void)
{
    return 0;
}
//The const char pointer holding our names.
const char* names = "Elliot Gong & Michael Xie";

Graph* maze = nullptr;
int index = 0;

/// <summary>
/// This method returns our group name.
/// </summary>
/// <returns>The string holding our team name.</returns>
extern "C" char* GetTeam()
{
    return (char*)names;
}
/// <summary>
/// This function creates a maze using the desired width, height, and 2D int array.
/// </summary>
/// <param name="data">The 2D int array holding the numerical represenation of a maze.
/// 0s are valid locations while 1s are maze walls.</param>
/// <param name="width">The maze's desired width.</param>
/// <param name="height">The maze's desired height.</param>
/// <returns>Returns a bool based on the success of the setting of the maze data.</returns>
extern "C" bool SetMaze(const int** data, int width, int height)
{
    //Return false if if parameters are invalid.
    if (width <= 0 || height <= 0 || data == nullptr)
    {
        return false;
    }
    //Otherwise, save the parameters into variables in the dll.
    else
    {
        //Set values of the width/height fields.
        mazeHeight = height;
        mazeWidth = width;
        //Instantiate the custom data type used for the maze.
        mazeData = new int* [width];
        for (int i = 0; i < width; i++)
        {
            mazeData[i] = new int[height];
        }
        //Copy the data from the original maze data into the new 2D array.
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                mazeData[i][j] = data[i][j];
            }
        }
        //Save the dimensions of the 2D maze/array.
        int correct = width * height;
        //Check if the DLL maze data and the parameter maze data are identical.
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                if (mazeData[i][j] == data[i][j])
                {
                    correct--;
                }
            }
        }
        //Create the graph/maze and return true if maze data in DLL is valid.
        //Otherwise return false.
        if (correct == 0)
        {
            maze = new Graph(width, height, mazeData);

            return true;
        }
        else
        {
            return false;
        }
    }
    
}
/// <summary>
/// This function returns the maze data stored in the dll.
/// </summary>
/// <param name="width">The reference variable to hold the maze width.</param>
/// <param name="height">The reference variable to hold the maze height.</param>
/// <returns>Returns the double pointer/2D pointer array of maze values. </returns>
extern "C" int** GetMaze(int& width, int& height)
{
    //Check if maze data hasn't been set yet.
    if (mazeData == nullptr || mazeHeight == 0 || mazeWidth == 0)
    {
        return nullptr;
    }
    //Otherwise, return it and set the reference parameters' values.
    else
    {
        width = mazeWidth;
        height = mazeHeight;
        return mazeData;
    }
}
    
/// <summary>
/// This function returns a position for the current vertex to move to. The next location
/// will be on a path that will leads to the end vertex. 
/// </summary>
/// <param name="xpos">The variable that will hold the next location's x coordinate.</param>
/// <param name="ypos">The variable that will hold the next location's y coordinate.</param>
/// <returns>Returns true or false depending whether there is a valid next position or not.</returns>
extern "C" bool GetNextPosition(int& xpos, int& ypos)
{
    //Create a vector to hold the path of vertices that go from start to end.
    if (nextSteps.empty() == true)
    {
        nextSteps = maze->AStar();
    }

    //Check to see if the current vertex has any neighbors.
    if (nextSteps.empty() == false)
    {
        //If the first element is indeed the start, clear the vector and set the reference
        //variables to the start vertex's coordinates.
        if (nextSteps[0] == maze->start)
        {
            nextSteps.clear();
            xpos = maze->start->xPos;
            ypos = maze->start->yPos;
        }
        //Otherwise, set the reference variables to the values of a vertex's coordinates.
        //This vertex is accessed from the vector that contains the "path" from start to finish.
        else
        {
            xpos = nextSteps[nextSteps.size() - (index + 1)]->xPos;
            ypos = nextSteps[nextSteps.size() - (index + 1)]->yPos;
        }
        //Increment the index so that we could access a different vertex each time this function
        //is called.
        index++;
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// This function sets the location of the start vertex within a graph/maze.
/// </summary>
/// <param name="xpos">The x coordinate of the start vertex.</param>
/// <param name="ypos">The y coordinate of the start vertex.</param>
/// <returns>Returns true or false depending if the parameters are valid and if 
/// the start vertex was indeed saved.</returns>
extern "C" bool SetStart(int xpos, int ypos)
{
    //Check if the parameters are valid.
    if (xpos < 0 || ypos < 0 || xpos >= mazeWidth || ypos >= mazeHeight)
    {
        return false;
    }
    else
    {
        //Instantiate the Start and Current vertices.
        //Find the end vertex within the graph.
        for (Vertex* element : maze->vertices)
        {
            if (element->xPos == xpos && element->yPos == ypos)
            {
                maze->start = element;
            }
        }
        //Check if the start vertex is valid.
        if (maze->start->xPos == xpos && maze->start->yPos == ypos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
}
/// <summary>
/// Save the start vertex's positions into reference variables.
/// </summary>
/// <param name="xpos">The variable that will hold the start vertex's x coordinate.</param>
/// <param name="ypos">The variable that will hold the start vertex's x coordinate.</param>
/// <returns>Returns true of false seeing if the start vertex is valid and saved.</returns>
extern "C" bool GetStart(int& xpos, int& ypos)
{
    //Check if positions are within maze bounds and aren't null.
    if (maze->start->xPos < 0 || maze->start->yPos < 0 || maze->start->xPos >= mazeWidth || maze->start->yPos >= mazeHeight )
    {
        return false;
    }
    //Otherwise, set reference variable values equal to those of the 
    //stored end position variables in the dll.
    else
    {
        xpos = maze->start->xPos;
        ypos = maze->start->yPos;
        return true;
    }
}
/// <summary>
/// This function sets the location of the end vertex within a graph/maze.
/// </summary>
/// <param name="xpos">The x coordinate of the end vertex.</param>
/// <param name="ypos">The y coordinate of the end vertex.</param>
/// <returns>Returns true or false depending if the parameters are valid and if 
/// the end vertex was indeed saved.</returns>
extern "C" bool SetEnd(int xpos, int ypos)
{
    //Check if the parameters are valid.
    if (xpos < 0 || ypos < 0 || xpos >= mazeWidth || ypos >= mazeHeight)
    {
        return false;
    }
    else
    {
        //Locate the vertex within the maze that matches the desired 
        //end coordinate positions.
        for (Vertex* element : maze->vertices)
        {
            if (element->xPos == xpos && element->yPos == ypos)
            {
                maze->end = element;
            }
        }
        //Calculate the h costs of all vertices in the maze.
        //h cost is distance between a vertex and the end vertex.
        for (Vertex* node : maze->vertices)
        {
            node->hCost = abs(maze->end->xPos - node->xPos) + abs(maze->end->yPos - node->yPos);
        }
        //See if the end vertex is valid.
        if (maze->end->xPos == xpos && maze->end->yPos == ypos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
}
/// <summary>
/// Save the end vertex's positions into reference variables.
/// </summary>
/// <param name="xpos">The variable that will hold the end vertex's x coordinate.</param>
/// <param name="ypos">The variable that will hold the end vertex's x coordinate.</param>
/// <returns>Returns true of false seeing if the end vertex is valid and saved.</returns>
extern "C" bool GetEnd(int& xpos, int& ypos)
{
    //Check if positions are within maze bounds and aren't null.
    if (maze->end->xPos < 0 || maze->end->yPos < 0 || maze->end->xPos >= mazeWidth || maze->end->yPos >= mazeHeight)
    {
        //Set reference variable values to =1.
        return false;
    }
    //Otherwise, set reference variable values equal to those of the 
    //stored end position variables in the dll.
    else
    {
        xpos = maze->end->xPos;
        ypos = maze->end->yPos;
        return true;
    }
}
/// <summary>
/// This function moves the current vertex back to the start and clears the graph's 
/// open and closed lists to set it up for another round of pathfinding.
/// </summary>
/// <returns>Returns true or false depending if the current position is within the maze.</returns>
extern "C" bool Restart()
{
    index = 0;
    //Check to see if the first vertex of the path vector is the start vertex.
    if (nextSteps[nextSteps.size() - (index + 1)]->xPos == maze->start->xPos && nextSteps[nextSteps.size() - (index + 1)]->yPos == maze->start->yPos)
    {
        //If yes, return true
        return true;
    }
    else
    {
        //Otherwise, return false
        return false;
    }
}

// This is the constructor of a class that has been exported.
CGroupProject::CGroupProject()
{
    return;
}

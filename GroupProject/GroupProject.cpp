// GroupProject.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "GroupProject.h"
#include <vector>

/*Authors: Elliot Gong and Michael Xie
* Purpose: Instantiate functions and use the variables declared in the header.
* Restrictions: Must have functions store and tweak data for the maze.
* Date: 2/17/2022
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
vector<Vertex*> nextSteps;

/// <summary>
/// This method returns our group name.
/// </summary>
/// <returns>The string holding our team name.</returns>
char* GetTeam()
{
    return (char*)names;
}
/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
/// <param name="width"></param>
/// <param name="height"></param>
/// <returns>Returns a bool based on the success of the setting of the maze data.</returns>
bool SetMaze(const int** data, int width, int height)
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
        //Return true if maze data in DLL is valid, otherwise return false.
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
int** GetMaze(int& width, int& height)
{
    //Check if maze data hasn't been set yet.
    if (mazeData == nullptr || mazeHeight == 0 || mazeWidth == 0)
    {
        return nullptr;
    }
    //Otherwise, return it.
    else
    {
        width = mazeWidth;
        height = mazeHeight;
        return mazeData;
    }
}
    
/// <summary>
/// This function sets the next positon to move to.
/// </summary>
/// <param name="xpos">The reference variable to hold the destination x position.</param>
/// <param name="ypos">The reference variable to hold the destination y position.</param>
bool GetNextPosition(int& xpos, int& ypos)
{
    //Create a vector to hold the neighbor vertices of the current vertex.
    if (nextSteps.empty() == true)
    {
        nextSteps = maze->AStar();
    }

    //Check to see if the current vertex has any neighbors.s
    if (nextSteps.empty() == false)
    {
        xpos = nextSteps[index]->xPos;
        ypos = nextSteps[index]->yPos;
        index++;
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// This method sets the starting location of the maze.
/// </summary>
/// <param name="xpos">The value used to set the x position.</param>
bool SetStart(int xpos, int ypos)
{
    if (xpos < 0 || ypos < 0 || xpos >= mazeWidth || ypos >= mazeHeight)
    {
        return false;
    }
    else
    {
        //Instantiate the Start and Current vertices.
        //Find end vertex within graph's vector.
        for (Vertex* element : maze->vertices)
        {
            if (element->xPos == xpos && element->yPos == ypos)
            {
                maze->start = element;
            }
        }
        //Check if the 2 vertices are the same at the beginning.
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
/// Access the start positions and place their values into the reference parameters.
/// </summary>
/// <param name="xpos">The reference variable that will hold the x position.</param>
/// <param name="ypos">The reference variable that will hold the y position.</param>
bool GetStart(int& xpos, int& ypos)
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
/// Save the end position to the dll file.
/// </summary>
/// <param name="xpos">The new x position of the end location.</param>
/// <param name="ypos">The new y positoin of the end location.</param>
bool SetEnd(int xpos, int ypos)
{
    if (xpos < 0 || ypos < 0 || xpos >= mazeWidth || ypos >= mazeHeight)
    {
        return false;
    }
    else
    {
        //Find end vertex within graph's vector.
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
/// Access the end positions and place their values into the reference parameters.
/// </summary>
/// <param name="xpos">The reference variable that will hold the x position.</param>
/// <param name="ypos">The reference variable that will hold the y position.</param>
bool GetEnd(int& xpos, int& ypos)
{
    //Check if positions are within maze bounds and aren't null.
    if (maze->start->xPos < 0 || maze->start->yPos < 0 || maze->end->xPos >= mazeWidth || maze->end->yPos >= mazeHeight)
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

bool Restart()
{
    //Reassign the current locations to the start location.
    maze->current->xPos = maze->start->xPos;
    maze->current->yPos = maze->start->yPos;
    maze->openList.clear();
    maze->closedList.clear();
    index = 0;

    if (maze->current->xPos < 0 || maze->current->yPos < 0 || maze->current->yPos >= mazeWidth || maze->current->yPos >= mazeHeight)
    {
        //Set reference variable values to =1.
        return false;
    }
    else
    {
        return true;
    }
}

// This is the constructor of a class that has been exported.
CGroupProject::CGroupProject()
{
    return;
}

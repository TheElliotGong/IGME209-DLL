// GroupProject.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "GroupProject.h"


// This is an example of an exported variable
GROUPPROJECT_API int nGroupProject=0;

// This is an example of an exported function.
GROUPPROJECT_API int fnGroupProject(void)
{
    return 0;
}
const char* names = "Elliot Gong & Michael Xie";

//arrays to keep track of possible x and y coordinates.
int xLocations[11] = {4, 2, 1, 3, 6, 0, 11, 9, 7, 5};
int yLocations[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int incr = -1;

char* GetTeam()
{
    return (char*)names;
}
/// <summary>
/// This function saves the maze data created from maze program into dll.
/// </summary>
/// <param name="data">This refers to the double pointer used to hold the original maze data.</param>
/// <param name="width">This is the maze width.</param>
/// <param name="height">This is the maze height.</param>
void SetMaze(const int** data, int width, int height)
{
    //Assign parameter values to private variables.
    mazeHeight = height;
    mazeWidth = width;
    //Instantiate the custom data type used for the maze.
    mazeData = new int* [height];
    for (int i = 0; i < height; i++)
    {
        mazeData[i] = new int[width];
    }
    //Copy the data from the original maze data into the new 2D array.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mazeData[i][j] = data[i][j];
        }
    }
}

int** GetMaze(int& width, int& height)
{
    width = mazeWidth;
    height = mazeHeight;
    return mazeData;
}

void GetNextPosition(int& xpos, int& ypos)
{
    incr++;
    xpos = xLocations[incr];
    ypos = yLocations[incr];
    currentX = xpos;
    currentY = ypos;

    if (incr > 9)
    {
        incr = -1;
    }
}

void SetStart(int xpos, int ypos)
{
    startX = xpos;
    startY = ypos;
    currentX = xpos;
    currentY = ypos;
}

void GetStart(int& xpos, int& ypos)
{
    if (startX < 0 || startY < 0 || startX >= mazeWidth || startY >= mazeHeight || startX == NULL || startY == NULL)
    {
        xpos = -1;
        ypos = -1;
    }
    else
    {
        xpos = startX;
        ypos = startY;
    }
}
/// <summary>
/// Save the end position to the dll file.
/// </summary>
/// <param name="xpos">The new x position of the end location.</param>
/// <param name="ypos">The new y positoin of the end location.</param>
void SetEnd(int xpos, int ypos)
{
    endX = xpos;
    endY = ypos;
}

void GetEnd(int& xpos, int& ypos)
{
    if (endX < 0 || endY < 0 || endX >= mazeWidth || endY >= mazeHeight || endX == NULL || endY == NULL)
    {
        xpos = -1;
        ypos = -1;
    }
    else
    {
        xpos = endX;
        ypos = endY;
    }
}

// This is the constructor of a class that has been exported.
CGroupProject::CGroupProject()
{
    return;
}

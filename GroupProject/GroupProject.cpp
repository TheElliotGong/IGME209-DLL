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

typedef int* maze;

maze* mazeData;
int mazeWidth;
int mazeHeight;
int startX;
int startY;
int endX;
int endY;

char* GetTeam()
{
    return (char*)names;
}

void SetMaze(const int** data, int width, int height)
{
    mazeHeight = height;
    mazeWidth = width;

    mazeData = new maze[height];
    for (int i = 0; i < height; i++)
    {
        mazeData[i] = new int[width];
    }

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

}

void SetStart(int xpos, int ypos)
{
    startX = xpos;
    startY = ypos;
}

void GetStart(int& xpos, int& ypos)
{
    if (startX < 0 || startY < 0 || startX >= mazeWidth || startY >= mazeHeight)
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

void SetEnd(int xpos, int ypos)
{
    endX = xpos;
    endY = ypos;
}

void GetEnd(int& xpos, int& ypos)
{
    if (endX < 0 || endY < 0 || endX >= mazeWidth || endY >= mazeHeight)
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

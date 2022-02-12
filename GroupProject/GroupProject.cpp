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

char* GetTeam()
{
    return (char*)names;
}

void SetMaze(const int** data, int width, int height)
{
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
    return mazeData;
}

// This is the constructor of a class that has been exported.
CGroupProject::CGroupProject()
{
    return;
}

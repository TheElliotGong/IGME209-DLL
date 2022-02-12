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
//Instantiate GetTeam function.
const char* names = "Elliot Gong & Michael Xie";

int mazeWidth;
int mazeHeight;
char* GetTeam()
{
    return (char*)names;
}

void SetMaze(const int** data, int width, int height)
{
    mazeWidth = width;
    mazeHeight = height;
}

// This is the constructor of a class that has been exported.
CGroupProject::CGroupProject()
{
    return;
}

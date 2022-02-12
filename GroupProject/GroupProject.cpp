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


}

//int& width = 8 - WRong;
//int& width = widthVar - Right;
int** GetMaze(int& width, int& height)
{
   
}

// This is the constructor of a class that has been exported.
CGroupProject::CGroupProject()
{
    return;
}

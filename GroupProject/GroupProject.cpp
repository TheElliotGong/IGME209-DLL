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

// This is the constructor of a class that has been exported.
CGroupProject::CGroupProject()
{
    return;
}

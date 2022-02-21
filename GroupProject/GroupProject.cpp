// GroupProject.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "GroupProject.h"
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

//Variables to hold possible x and y coordinates as well as the index variable
//used to access said coordinates.
int xLocations[11] = {4, 2, 1, 3, 6, 0, 11, 9, 7, 5};
int yLocations[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int incr = -1;
/// <summary>
/// This method returns our group name.
/// </summary>
/// <returns>The string holding our team name.</returns>
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
}
/// <summary>
/// Return the 2d pointer array that holds the maze data. Also take the width and height
/// variables stored in the dll, and store their values in the reference parameters.
/// </summary>
/// <param name="width">The variable that'll hold the width value.</param>
/// <param name="height">The variable that'll hold the height value.</param>
/// <returns></returns>
int** GetMaze(int& width, int& height)
{
    width = mazeWidth;
    height = mazeHeight;
    return mazeData;
}
/// <summary>
/// This function sets the next positon to move to.
/// </summary>
/// <param name="xpos">The reference variable to hold the destination x position.</param>
/// <param name="ypos">The reference variable to hold the destination y position.</param>
void GetNextPosition(int& xpos, int& ypos)
{
    //Randomly choose a new x and y coordinate to set as the new position.
    incr++;
    xpos = xLocations[incr];
    ypos = yLocations[incr];
    //Set the value for the new current position.
    currentX = xpos;
    currentY = ypos;
    //Reset the increment variable for the next function call.
    if (incr > 9)
    {
        incr = -1;
    }
}
/// <summary>
/// This method sets the starting location of the maze.
/// </summary>
/// <param name="xpos">The value used to set the x position.</param>
/// <param name="ypos">The value used to set the y posiiton.</param>
void SetStart(int xpos, int ypos)
{
    startX = xpos;
    startY = ypos;
    //Also set the current position, since we all start at the beginning
    //location.
    currentX = xpos;
    currentY = ypos;
}
/// <summary>
/// Access the start positions and place their values into the reference parameters.
/// </summary>
/// <param name="xpos">The reference variable that will hold the x position.</param>
/// <param name="ypos">The reference variable that will hold the y position.</param>
void GetStart(int& xpos, int& ypos)
{
    //Check if positions are within maze bounds and aren't null.
    if (startX < 0 || startY < 0 || startX >= mazeWidth || startY >= mazeHeight || startX == NULL || startY == NULL)
    {
        //Set reference variable values to =1.
        xpos = -1;
        ypos = -1;
    }
    //Otherwise, set reference variable values equal to those of the 
    //stored end position variables in the dll.
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
/// <summary>
/// Access the end positions and place their values into the reference parameters.
/// </summary>
/// <param name="xpos">The reference variable that will hold the x position.</param>
/// <param name="ypos">The reference variable that will hold the y position.</param>
void GetEnd(int& xpos, int& ypos)
{
    //Check if positions are within maze bounds and aren't null.
    if (endX < 0 || endY < 0 || endX >= mazeWidth || endY >= mazeHeight || endX == NULL || endY == NULL)
    {
        //Set reference variable values to =1.
        xpos = -1;
        ypos = -1;
    }
    //Otherwise, set reference variable values equal to those of the 
    //stored end position variables in the dll.
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

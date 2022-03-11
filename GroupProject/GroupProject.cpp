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

        int correct = width * height;

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

        if (correct == 0)
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
        return false;
    }
    else
    {
        return true;
    }
}
/// <summary>
/// This method sets the starting location of the maze.
/// </summary>
/// <param name="xpos">The value used to set the x position.</param>
bool SetStart(int xpos, int ypos)
{
    if (xpos < 0 || ypos < 0 || xpos >= mazeWidth || ypos >= mazeHeight || xpos == NULL || ypos == NULL)
    {
        return false;
    }
    else
    {
        startX = xpos;
        startY = ypos;
        //Also set the current position, since we all start at the beginning
        //location.
        currentX = xpos;
        currentY = ypos;
        return true;
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
    if (startX < 0 || startY < 0 || startX >= mazeWidth || startY >= mazeHeight || startX == NULL || startY == NULL)
    {
        return false;
    }
    //Otherwise, set reference variable values equal to those of the 
    //stored end position variables in the dll.
    else
    {
        xpos = startX;
        ypos = startY;
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
    if (xpos < 0 || ypos < 0 || xpos >= mazeWidth || ypos >= mazeHeight || xpos == NULL || ypos == NULL)
    {
        return false;
    }
    else
    {
        endX = xpos;
        endY = ypos;
        return true;
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
    if (endX < 0 || endY < 0 || endX >= mazeWidth || endY >= mazeHeight || endX == NULL || endY == NULL)
    {
        //Set reference variable values to =1.
        return false;
    }
    //Otherwise, set reference variable values equal to those of the 
    //stored end position variables in the dll.
    else
    {
        xpos = endX;
        ypos = endY;
        return true;
    }
}

bool Restart()
{
    //Reassign the current locations to the start location.
    currentX = startX;
    currentY = startY;

    if (currentX < 0 || currentY < 0 || currentX >= mazeWidth || currentY >= mazeHeight || currentX == NULL || currentY == NULL)
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

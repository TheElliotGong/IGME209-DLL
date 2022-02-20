#include "pch.h"
#include "CppUnitTest.h"
#include "GroupProject.h"
#include <cstring>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
/*Authors: Elliot Gong and Michael Xie
* Purpose: Test the DLL functions in a unit test project.
* Restrictions: Must create cases that'll succeed when functions are called.
* Date: 2/17/2022
*/
namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		/// <summary>
		/// Test the Get Next Position method.
		/// </summary>
		TEST_METHOD(GetNextPositionTest)
		{
			int x = 0;
			int y = 0;
			//Call the get next position method 
			GetNextPosition(x, y);

			Assert::AreEqual(4, x);
			Assert::AreEqual(1, y);
		}

		/// <summary>
		/// Test the Get Team method.
		/// </summary>
		TEST_METHOD(GetTeamTest)
		{
			char* test = GetTeam();
			char* ret = "Elliot Gong & Michael Xie";
			Assert::AreEqual(strcmp(test,ret), 0);
		}

		/// <summary>
		/// Test the Set Maze method.
		/// </summary>
		TEST_METHOD(SetMazeTest)
		{
			//Create a multidimensional array of pointers.
			int** test = new int*[3];
			for (int i = 0; i < 3; i++)
			{
				test[i] = new int[3];
			}
			//Set the values for the local 2d array's elements.
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					test[i][j] = 1;
				}
			}
			//Pass in the 2d array into the set maze function.
			SetMaze((const int**)test, 3, 3);
			//Declare some variables to check to see if the local 2d array and the 2d array
			//stored in the dll are equal.
			bool notEqual = true;
			int correct = 0;
			//Loop through the local 2d array and the dll array variable and 
			//check if they're equal.
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (mazeData[i][j] == test[i][j])
					{
						correct++;
					}
				}
			}
			//If all elements in both arrays are equal, set the local bool variable to false.
			if (correct == 9)
			{
				notEqual = false;
			}
			//Check if the set maze function worked.
			Assert::AreEqual(notEqual, false);
		}
		/// <summary>
		/// Test the GetMaze function.
		/// </summary>
		TEST_METHOD(GetMazeTest)
		{
			//Create a multidimensional array of pointers.
			int** test = new int* [3];
			for (int i = 0; i < 3; i++)
			{
				test[i] = new int[3];
			}
			//Set the element values for the local 2d array.
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					test[i][j] = 1;
				}
			}
			//Pass in the 2d array into the set maze function.
			SetMaze((const int**)test, 3, 3);
			//These variables will be used to store the values produced
			//by the get maze function.
			int width;
			int height;
			int** maze = GetMaze(width, height);

			//Declare some variables to check to see if the local 2d array and the 2d array
			//stored in the dll are equal.
			bool notEqual = true;
			int correct = 0;
			//Loop through the local 2d array and the dll array variable and 
			//check if they're equal.
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (mazeData[i][j] == maze[i][j])
					{
						correct++;
					}
				}
			}
			//If all elements in both arrays are equal, set the local bool variable to false.
			if (correct == 9)
			{
				notEqual = false;
			}
			//Check if the set maze function worked.
			Assert::AreEqual(notEqual, false);
		}

		/// <summary>
		/// Test if the SetStart function worked.
		/// </summary>
		TEST_METHOD(SetStartTest)
		{
			//Create some local variables to use for the SetStart function and see
			//if those values are passed into the dll counterparts.
			int X = 2;
			int Y = 3;
			SetStart(X, Y);
			Assert::AreEqual(startX, X);
			Assert::AreEqual(startY, Y);
		}

		/// <summary>
		/// Test if the SetEnd function worked.
		/// </summary>
		TEST_METHOD(SetEndTest)
		{
			//Create some local variables to use for the SetEnd function and see
			//if those values are passed into the dll counterparts.
			int X = 2;
			int Y = 3;
			SetEnd(X, Y);
			Assert::AreEqual(endX, X);
			Assert::AreEqual(endY, Y);
		}

		/// <summary>
		/// Test the GetStart function.
		/// </summary>
		TEST_METHOD(GetStartTest)
		{
			//Set the dll width/height variables.
			mazeWidth = 3;
			mazeHeight = 3;
			//Create some local variables to store width and height values.
			int x;
			int y;
			//Set the start positions and then call several assert tests to see
            //if the variables in the unit test and dll are equal.
			SetStart(4, 4);
			GetStart(x, y);

			Assert::AreNotEqual(4, x);
			Assert::AreNotEqual(4, y);
		}

		/// <summary>
		/// Test the GetEnd function.
		/// </summary>
		TEST_METHOD(GetEndTest)
		{
			
			//Set the dll width/height variables.
			mazeWidth = 3;
			mazeHeight = 3;
			//Create some local variables to store width and height values.
			int x;
			int y;
			//Set the end positions and then call several assert tests to see
			//if the variables in the unit test and dll are equal.
			SetEnd(2, 2);
			GetEnd(x, y);

			Assert::AreEqual(2, x);
			Assert::AreEqual(2, y);
		}
	};
}

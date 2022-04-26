#include "pch.h"
#include "CppUnitTest.h"
#include "GroupProject.h"
#include <cstring>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
/*Authors: Elliot Gong and Michael Xie
* Purpose: Test the DLL functions in a unit test project.
* Restrictions: Must rework the current unit test methods and add a new one for 
* the Restart function.
* Date: 4/25/2022
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
			int** test = new int* [3];
			for (int i = 0; i < 3; i++)
			{
				test[i] = new int[4];
			}
			//Set the values for the local 2d array's elements.
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					test[i][j] = 0;
				}
			}
			//Pass in the 2d array into the set maze function.
			bool createdMaze = SetMaze((const int**)test, 3, 4);
			bool createdStart = SetStart(0, 2);
			bool createdEnd = SetEnd(2, 1);
			
			int x = 0;
			int y = 0;
			//Call the get next position method 
			bool worked = GetNextPosition(x, y);

			Assert::AreEqual(true, worked);
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
				test[i] = new int[4];
			}
			//Set the values for the local 2d array's elements.
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					test[i][j] = 1;
				}
			}
			//Pass in the 2d array into the set maze function.
			bool correct = SetMaze((const int**)test, 3, 4);

			//Check if the set maze function worked.
			Assert::AreEqual(correct, true);
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
				test[i] = new int[4];
			}
			//Set the element values for the local 2d array.
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					test[i][j] = 1;
				}
			}
			//Pass in the 2d array into the set maze function.
			SetMaze((const int**)test, 3, 4);
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
				for (int j = 0; j < 4; j++)
				{
					if (mazeData[i][j] == maze[i][j])
					{
						correct++;
					}
				}
			}
			//If all elements in both arrays are equal, set the local bool variable to false.
			if (correct == 12)
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
			//Create a multidimensional array of pointers.
			int** test = new int* [3];
			for (int i = 0; i < 3; i++)
			{
				test[i] = new int[4];
			}
			//Set the element values for the local 2d array.
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					test[i][j] = 0;
				}
			}
			//Pass in the 2d array into the set maze function.
			bool createdMaze = SetMaze((const int**)test, 3, 4);

			//Call the SetStart function.
			bool correct = SetStart(2, 3);

			Assert::AreEqual(correct, createdMaze);
		}

		/// <summary>
		/// Test if the SetEnd function worked.
		/// </summary>
		TEST_METHOD(SetEndTest)
		{
			//Create a multidimensional array of pointers.
			int** test = new int* [3];
			for (int i = 0; i < 3; i++)
			{
				test[i] = new int[4];
			}
			//Set the element values for the local 2d array.
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					test[i][j] = 0;
				}
			}
			//Pass in the 2d array into the set maze function.
			bool createdMaze = SetMaze((const int**)test, 3, 4);

			//Call the SetEnd function
			bool correct = SetEnd(0, 2);

			Assert::AreEqual(correct, createdMaze);
		}

		/// <summary>
		/// Test the GetStart function.
		/// </summary>
		TEST_METHOD(GetStartTest)
		{
			//Set the dll width/height variables.
			mazeWidth = 3;
			mazeHeight = 4;
			int** test = new int* [mazeWidth];
			for (int i = 0; i < mazeWidth; i++)
			{
				test[i] = new int[mazeHeight];
			}
			for (int i = 0; i < mazeWidth; i++)
			{
				for (int j = 0; j < mazeHeight; j++)
				{
					test[i][j] = 0;
				}
			}
			bool createdMaze = SetMaze((const int**)test, mazeWidth, mazeHeight);
			//Create some local variables to store width and height values.
			int x;
			int y;
			//Set the start positions and then call several assert tests to see
            //if the variables in the unit test and dll are equal.
			bool createdStart = SetStart(2, 2);
			bool correct = GetStart(x, y);

			Assert::AreEqual(x, 2);
			Assert::AreEqual(y, 2);
		}

		/// <summary>
		/// Test the GetEnd function.
		/// </summary>
		TEST_METHOD(GetEndTest)
		{
			
			//Set the dll width/height variables.
			mazeWidth = 3;
			mazeHeight = 4;
			int** test = new int* [mazeWidth];
			for (int i = 0; i < mazeWidth; i++)
			{
				test[i] = new int[mazeHeight];
			}
			for (int i = 0; i < mazeWidth; i++)
			{
				for (int j = 0; j < mazeHeight; j++)
				{
					test[i][j] = 0;
				}
			}
			bool createdMaze = SetMaze((const int**)test, mazeWidth, mazeHeight);
			//Create some local variables to store width and height values.
			int x;
			int y;
			//Set the end positions and then call several assert tests to see
			//if the variables in the unit test and dll are equal.
			bool createdEnd = SetEnd(2, 2);
			bool correct = GetEnd(x, y);

			Assert::AreEqual(x, 2);
			Assert::AreEqual(y, 2);
		}

		TEST_METHOD(RestartTest)
		{
			int** test = new int* [3];
			for (int i = 0; i < 3; i++)
			{
				test[i] = new int[4];
			}
			//Set the values for the local 2d array's elements.
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					test[i][j] = 0;
				}
			}
			//Pass in the 2d array into the set maze function.
			bool createdMaze = SetMaze((const int**)test, 3, 4);
			bool createdStart = SetStart(0, 2);
			bool createdEnd = SetEnd(2, 1);
			//Declare some int variables to be used for the getnextposition function.
			int x = 0;
			int y = 0;
			//Call the get next position method to perform a star pathfinding.
			bool worked = GetNextPosition(x, y);
			worked = GetNextPosition(x, y);
			worked = GetNextPosition(x, y);
			//Call the restart function.
			bool restarted = Restart();

			Assert::AreEqual(restarted, true);
		}

	};
}

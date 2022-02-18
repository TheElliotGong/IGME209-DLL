#include "pch.h"
#include "CppUnitTest.h"
#include "GroupProject.h"
#include <cstring>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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

		TEST_METHOD(GetMazeTest)
		{
			//Create a multidimensional array of pointers.
			int** test = new int* [3];
			for (int i = 0; i < 3; i++)
			{
				test[i] = new int[3];
			}

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					test[i][j] = 1;
				}
			}
			//Pass in the 2d array into the set maze function.
			SetMaze((const int**)test, 3, 3);

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
			mazeWidth = 3;
			mazeHeight = 3;

			int x;
			int y;
			
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
			mazeWidth = 3;
			mazeHeight = 3;

			int x;
			int y;

			SetEnd(2, 2);
			GetEnd(x, y);

			Assert::AreEqual(2, x);
			Assert::AreEqual(2, y);
		}
	};
}

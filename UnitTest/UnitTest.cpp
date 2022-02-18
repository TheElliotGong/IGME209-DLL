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
		TEST_METHOD(TestMethod1)
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
		TEST_METHOD(TestMethod2)
		{
			char* test = GetTeam();
			char* ret = "Elliot Gong & Michael Xie";
			Assert::AreEqual(strcmp(test,ret), 0);
		}
		/// <summary>
		/// Test the Set Maze method.
		/// </summary>
		TEST_METHOD(TestMethod3)
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
		/// <summary>
		/// Test if the SetStart function worked.
		/// </summary>
		TEST_METHOD(TestMethod4)
		{
			int X = 2;
			int Y = 3;
			SetStart(X, Y);
			Assert::AreEqual(startX, X);

		}
		/// <summary>
		/// Test if the SetEnd function worked.
		/// </summary>
		TEST_METHOD(TestMethod5)
		{
			int X = 2;
			int Y = 3;
			SetEnd(X, Y);
			Assert::AreEqual(endX, X);
		}
		/// <summary>
		/// Test the GetStart function.
		/// </summary>
		TEST_METHOD(TestMethod6)
		{

			int x = 3;
			int y = 5;
			
			GetStart(x, y);

			Assert::AreEqual(startX, x);


			
		}
	};
}

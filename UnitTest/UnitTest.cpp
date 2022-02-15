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
		
		TEST_METHOD(TestMethod1)
		{
			int x = 0;
			int y = 0;
			 
			GetNextPosition(x, y);

			Assert::AreEqual(4, x);
			Assert::AreEqual(1, y);
		}

		TEST_METHOD(TestMethod2)
		{
			char* test = GetTeam();
			char* ret = "Elliot Gong & Michael Xie";
			Assert::AreEqual(strcmp(test,ret), 0);
		}

		TEST_METHOD(TestMethod3)
		{
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
			//nst int** data = (const int**)test;
			SetMaze((const int**)test, 3, 3);

			bool notEqual = true;
			int correct = 0;

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

			if (correct == 9)
			{
				notEqual = false;
			}

			Assert::AreEqual(notEqual, false);
		}
	};
}

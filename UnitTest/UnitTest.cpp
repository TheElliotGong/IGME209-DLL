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
	};
}

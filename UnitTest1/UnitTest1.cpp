#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 8.2.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string input = "abc(io)def";
			string expected = "abcdef";
			string result = ProcessBrackets(input);
			Assert::AreEqual(expected, result);
		}
	};
}

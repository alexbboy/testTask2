#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Алексей\source\repos\testTask\testTask\Tape.h"
#include "C:\Users\Алексей\source\repos\testTask\testTask\Tapeclass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		
		TEST_METHOD(TestMethod1)
		{
			list<int> check;
			check.push_back(4);
			check.push_back(6);
			check.push_back(5);
			check.push_back(2);
			list<int> check2;
			check2.push_back(2);
			check2.push_back(4);
			check2.push_back(5);
			check2.push_back(6);
			Tapeclass tape;
			check = tape.sort(&check,4);
			Assert::AreEqual(tape.checkSorted(&check), true);
		//	Assert::AreEqual(tape.checkSorted(&check2), true);
		}
	};
}

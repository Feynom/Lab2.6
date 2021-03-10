#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab2.6/Lab2.6/Fraction.h"
#include "../Lab2.6/Lab2.6/Fraction.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest26
{
	TEST_CLASS(UnitTest26)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Fraction::Pair a(1, 5), b(1, 5);
			Assert::AreEqual(a == b, true);
		}
	};
}

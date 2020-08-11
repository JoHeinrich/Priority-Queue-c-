#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "../CodeManufaktur/Priorities.h"
#include "../CodeManufaktur/CommandLineParser.h"

//Necessary because we don't have library
#include "../CodeManufaktur/Priorities.cpp"
#include "../CodeManufaktur/Student.cpp"
#include "../CodeManufaktur/CommandLineParser.cpp"




namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Insert)
		{
			Priorities p;
			Student s1(1, "sa", 4);
			Student s2(2, "sa", 4);
			Student s3(3, "sa", 4);
			p.Enter(s2);
			p.Enter(s1);
			p.Enter(s3);
			Assert::IsTrue(s1 == p.Served());
			Assert::IsTrue(s2 == p.Served());
			Assert::IsTrue(s3 == p.Served());
		}

		TEST_METHOD(Comparison)
		{
			Student f(1, "sa", 4);
			Student s(2, "sa", 4);
			Assert::IsTrue(f < s);
			Assert::IsFalse(f > s);
		}


		TEST_METHOD(DeepComparison)
		{
			Student s(2, "sa", 3);

			Assert::IsTrue(s < Student(2, "sa", 4));
			Assert::IsTrue(s < Student(2, "sb", 3));
			Assert::IsTrue(s < Student(3, "sa", 3));
			Assert::IsFalse(s < Student(2, "sa", 2));
			Assert::IsFalse(s < Student(2, "aa", 3));
			Assert::IsFalse(s < Student(1, "sa", 3));
			auto func = [] {Student(2, "sa", 3) < Student(2, "sa", 3); };
			Assert::ExpectException<exception>(func);
		}

		TEST_METHOD(GetStudentsSingle)
		{
			Priorities p;
			Student s1(1, "sa", 4);
			Student s2(2, "sb", 4);
			Student s3(3, "sc", 4);
			p.Enter(s2);
			p.Enter(s1);
			p.Enter(s3);
			list<string > rem;
			rem.push_back("sb");
			auto remaining =p.GetStudents(rem);
			Assert::IsTrue(remaining.size() == 2);

			Assert::IsTrue(s1 == p.Served());
			Assert::IsTrue(s3 == p.Served());
		}
		TEST_METHOD(GetStudentsMulti)
		{
			Priorities p;
			Student s1(1, "sa", 4);
			Student s2(2, "sb", 4);
			Student s3(3, "sc", 4);
			p.Enter(s2);
			p.Enter(s1);
			p.Enter(s3);
			list<string > rem;
			rem.push_back("sb");
			rem.push_back("sc");
			rem.push_back("sa");
			auto remaining = p.GetStudents(rem);

			Assert::IsTrue(remaining.size() == 0);
		}

		TEST_METHOD(CorrectInsert)
		{
			CommandLineParser parser;
			Student s = parser.ParsInsert("sina 2.2 4");
			Assert::IsTrue(s.getName() == "sina");
			Assert::IsTrue(s.getCGP() == 2.2);
			Assert::IsTrue(s.getId() == 4);
		}

		void TestInsert(string s)
		{
			auto func = [s] {CommandLineParser parser;	parser.ParsInsert(s); };
			Assert::ExpectException<exception>(func);
		}
		TEST_METHOD(BadInsert)
		{
			TestInsert("2.2 4");
			TestInsert("sina 4");
			TestInsert("sina 2.2 ");

			TestInsert("6 22 4");
			TestInsert("sina 5.2 5");
			TestInsert("s 2.2 4");
		}

		TEST_METHOD(CommandLine)
		{
			//Not a good test but i won't rerout io for this example
			CommandLineParser parser;
			parser.ComputeCommand("ENTER sa 2 2");
			parser.ComputeCommand("ENTER sinb 2.2 4");
			parser.ComputeCommand("ENTER sinc 2.2 4");
			parser.ComputeCommand("PRINT");
			parser.ComputeCommand("SERVED");
			parser.ComputeCommand("SERVED");
			parser.ComputeCommand("SERVED");
			parser.ComputeCommand("PRINT");
			parser.ComputeCommand("QUIT");


		}
	};
}

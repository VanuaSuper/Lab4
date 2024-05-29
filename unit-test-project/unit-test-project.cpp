#include "pch.h"
#include "CppUnitTest.h"

#include "../main-project/lecture_plan.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	lecture_plan* build_lecture_plan(int start_hours, int start_minutes, int finish_hours, int finish_minutes)
	{
		lecture_plan* lectures = new lecture_plan;
		lectures->start.hours = start_hours;
		lectures->start.minutes = start_minutes;
		lectures->finish.hours = finish_hours;
		lectures->finish.minutes = finish_minutes;
		return lectures;
	}
	void delete_lecture_plan(lecture_plan* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}


	TEST_CLASS(unittestproject)
	{
	public:
		
		// тест с стандартными данными
		TEST_METHOD(TestMethod1)
		{
			lecture_plan* lectures[3];
			lectures[0] = build_lecture_plan(8,30,10,0); // 90
			lectures[1] = build_lecture_plan(10,30,12,0); // 90 
			lectures[2] = build_lecture_plan(9,0,12,0); // 180 
			Assert::AreEqual(180, process(lectures, 3));
			delete_lecture_plan(lectures, 3);
		}

		// тест с одинаковыми значениями

		TEST_METHOD(TestMethod2)
		{
			lecture_plan* lectures[3];
			lectures[0] = build_lecture_plan(9,0,10,0); // 60
			lectures[1] = build_lecture_plan(9,0,10,0); // 60
			lectures[2] = build_lecture_plan(9,0,10,0); // 60 
			Assert::AreEqual(60, process(lectures, 3));
			delete_lecture_plan(lectures, 3);
		}

		// тест с одним элементом

		TEST_METHOD(TestMethod3)
		{
			lecture_plan* lectures[1];
			lectures[0] = build_lecture_plan(8, 30, 10, 0); // 90
			Assert::AreEqual(90, process(lectures, 1));
			delete_lecture_plan(lectures, 1);
		}
	};
}

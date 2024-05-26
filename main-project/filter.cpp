#include "filter.h"
#include <cstring>
#include <iostream>
#include "processing.h"

lecture_plan** filter(lecture_plan* array[], int size, bool(*check)(lecture_plan* element), int& result_size)
{
	lecture_plan** result = new lecture_plan * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_lecture_plan_by_author(lecture_plan* element)
{
	return strcmp(element->author.first_name, "Иван") == 0 &&
		strcmp(element->author.middle_name, "Иванович") == 0 &&
		strcmp(element->author.last_name, "Иванов") == 0;
}

bool check_lecture_plan_by_duration(lecture_plan* element)
{
	return duration(element) > 15;
}

#include "processing.h"

int duration(lecture_plan* element)
{
	return (element->finish.hours*60 + element->finish.minutes - element->start.hours * 60 - element->start.minutes);
}

#ifndef LECTURE_PLAN_H
#define LECTURE_PLAN_H

#include "constants.h"

struct date
{
    int hours;
    int minutes;
};

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct lectre_plan
{
    person author;
    date start;
    date finish;
    char theme[MAX_STRING_SIZE];
};

#endif
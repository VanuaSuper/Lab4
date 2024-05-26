#ifndef PROCESSING_H
#define PROCESSING_H

#include "lecture_plan.h"

int duration(lecture_plan* element);

bool compare_by_duration(lecture_plan* a, lecture_plan* b);

bool compare_by_author_last_name(lecture_plan* a, lecture_plan* b);

void merge(lecture_plan* array[], int left, int mid, int right, bool (*compare)(lecture_plan*, lecture_plan*));

void merge_sort(lecture_plan* array[], int left, int right, bool (*compare)(lecture_plan*, lecture_plan*));

void swap(lecture_plan* array[], int i, int j);

void heapify(lecture_plan* array[], int size, int index, bool (*compare)(lecture_plan*, lecture_plan*));

void heap_sort(lecture_plan* array[], int size, bool (*compare)(lecture_plan*, lecture_plan*));

#endif


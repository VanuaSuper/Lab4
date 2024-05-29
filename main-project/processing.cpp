#include "processing.h"

#include "cstring"
#include <iostream>

int duration(lecture_plan* element)
{
	return (element->finish.hours*60 + element->finish.minutes - element->start.hours * 60 - element->start.minutes);
}

bool compare_by_duration(lecture_plan* a, lecture_plan* b) {
    return duration(a) > duration(b);
}

bool compare_by_author_last_name(lecture_plan* a, lecture_plan* b) {
    int last_name_comparison = strcmp(a->author.last_name, b->author.last_name);
    if (last_name_comparison < 0) {
        return true;
    }
    else if (last_name_comparison > 0) {
        return false;
    }
    else {
        int theme_comparison = strcmp(a->theme, b->theme);
        if (theme_comparison < 0) {
            return true;
        }
        else {
            return false;
        }
    }
}

// Функция для слияния массивов
void merge(lecture_plan* array[], int left, int mid, int right, bool (*compare)(lecture_plan*, lecture_plan*)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    lecture_plan** L = new lecture_plan * [n1];
    lecture_plan** R = new lecture_plan * [n2];

    for (int i = 0; i < n1; ++i)
        L[i] = array[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
            array[k] = L[i];
            ++i;
        }
        else {
            array[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        array[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        array[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

// Функция сортировки слиянием
void merge_sort(lecture_plan* array[], int left, int right, bool (*compare)(lecture_plan*, lecture_plan*)) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(array, left, mid, compare);
        merge_sort(array, mid + 1, right, compare);

        merge(array, left, mid, right, compare);
    }
}

void swap(lecture_plan* array[], int i, int j) {
    lecture_plan* temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// Функция для создания пирамиды

void heapify(lecture_plan* array[], int size, int index, bool (*compare)(lecture_plan*, lecture_plan*)) {
    int largest = index;  
    int left = 2 * index + 1; 
    int right = 2 * index + 2;  


    if (left < size && compare(array[left], array[largest]) == false)
        largest = left;

    if (right < size&& compare(array[right], array[largest]) == false)
        largest = right;

    if (largest != index) {
        swap(array, index, largest);
        heapify(array, size, largest, compare);
    }
}

// Функция пирамидальной сортировки

void heap_sort(lecture_plan* array[], int size, bool (*compare)(lecture_plan*, lecture_plan*)) {
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(array, size, i, compare);

    for (int i = size - 1; i > 0; --i) {
        swap(array, 0, i);

        heapify(array, i, 0, compare);
    }
}

int process(lecture_plan* array[], int size) {

    int max = 0;
    for (int i = 0; i < size; i++) {
        if (duration(array[i]) > max) {
            max = duration(array[i]);
        }
    }

    return max;
}

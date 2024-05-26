#include <iostream>

using namespace std;

#include "lecture_plan.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа #4. GIT\n";
    cout << "Вариант #2. Программа конференции\n";
    cout << "Автор: Ivan Grechko\n";
    lecture_plan* lectures[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", lectures, size);
        for (int i = 0; i < size; i++)
        {
            cout << lectures[i]->start.hours << ' ';
            cout << lectures[i]->start.minutes << '\n';
            cout << lectures[i]->finish.hours << ' ';
            cout << lectures[i]->finish.minutes << '\n';
            cout << lectures[i]->author.first_name << '\n';
            cout << lectures[i]->author.middle_name << '\n';
            cout << lectures[i]->author.last_name << '\n';
            cout << lectures[i]->theme << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete lectures[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}

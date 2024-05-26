#include <iostream>
#include <iomanip>

using namespace std;

#include "lecture_plan.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
<<<<<<< HEAD
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа #4. GIT\n";
    cout << "Вариант #2. Программа конференции\n";
    cout << "Автор: Ivan Grechko\n\n";
    lecture_plan* lectures[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", lectures, size);
        cout << "***** Программа конференции *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод времени **********/
            cout << "Время...: ";
            // вывод времени начала
            cout << setw(2) << setfill('0') << lectures[i]->start.hours << ':';
            cout << setw(2) << setfill('0') << lectures[i]->start.minutes << " - ";
            // вывод времени конца
            cout << setw(2) << setfill('0') << lectures[i]->finish.hours << ':';
            cout << setw(2) << setfill('0') << lectures[i]->finish.minutes << '\n';
            /********** вывод спикера **********/
            cout << "Спикер..: ";
            // вывод фамилии 
            cout << lectures[i]->author.last_name << " ";
            // вывод первой буквы имени автора
            cout << lectures[i]->author.first_name[0] << ". ";
            // вывод первой буквы отчества автора
            cout << lectures[i]->author.middle_name[0] << ".\n";
            /********** вывод темы **********/
            cout << "Тема....: ";
            cout << lectures[i]->theme << '\n';
            cout << "\n";
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
=======
    cout << "Laboratory work #4. GIT\n";
    cout << "Variant #2. Conference program\n";
    cout << "Author: Ivan Grechko\n";
    cout << "Группа: 23ПИ1д\n";
>>>>>>> data
    return 0;
}

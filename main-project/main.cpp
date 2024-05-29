#include <iostream>
#include <iomanip>

using namespace std;

#include "lecture_plan.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "processing.h"

void output(lecture_plan* lecture) {
    /********** вывод времени **********/
    cout << "Время....: ";
    // вывод времени начала
    cout << setw(2) << setfill('0') << lecture->start.hours << ':';
    cout << setw(2) << setfill('0') << lecture->start.minutes << " - ";
    // вывод времени конца
    cout << setw(2) << setfill('0') << lecture->finish.hours << ':';
    cout << setw(2) << setfill('0') << lecture->finish.minutes << '\n';
    /********** вывод спикера **********/
    cout << "Спикер...: ";
    // вывод фамилии 
    cout << lecture->author.last_name << " ";
    // вывод первой буквы имени автора
    cout << lecture->author.first_name[0] << ". ";
    // вывод первой буквы отчества автора
    cout << lecture->author.middle_name[0] << ".\n";
    /********** вывод темы **********/
    cout << "Тема.....: ";
    cout << lecture->theme << '\n';
    cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа #4. GIT\n";
    cout << "Вариант #2. Программа конференции\n";
    cout << "Автор: Ivan Grechko\n\n";
    cout << "Группа: 23ПИ1д\n";

    lecture_plan* lectures[MAX_FILE_ROWS_COUNT];
    int size;

    try
    {
        read("data.txt", lectures, size);

        bool (*compare_function)(lecture_plan*, lecture_plan*) = NULL;
        
        cout << "Выберите критерий сортировки данных:\n";
        cout << "1) По убыванию длительности доклада\n";
        cout << "2) По возрастанию фамилии автора доклада, а в рамках одного автора по возрастанию темы доклада\n";
        cout << "\nВведите номер выбранного пункта: ";
        int item;
        cin >> item;
        cout << '\n';

        switch (item)
        {
        case 1:
            compare_function = compare_by_duration;
            break;
        case 2:
            compare_function = compare_by_author_last_name;
            break;
        default:
            throw "Некорректный номер пункта";
        }

        cout << "Выберите способ сортировки данных:\n";
        cout << "1) Сортировка слиянием\n";
        cout << "2) Пирамидальная сортировка\n";
        cout << "\nВведите номер выбранного пункта: ";
        cin >> item;
        cout << '\n';

        switch (item)
        {
        case 1:
            merge_sort(lectures, 0, size - 1, compare_function);
            break;
        case 2:
            heap_sort(lectures, size, compare_function);
            break;
        default:
            throw "Некорректный номер пункта";
        }
        

        cout << "***** Программа конференции *****\n\n";
        for (int i = 0; i < size; i++)
        {
            output(lectures[i]);
        }

        bool (*check_function)(lecture_plan*) = NULL;

        cout << "\nВыберите способ фильтрации или обработки данных:\n";
        cout << "1) Доклады Иванова Ивана Ивановича\n";
        cout << "2) Доклады длительностью более 15 минут\n";
        cout << "3) Длительность самого длинного доклада\n";
        cout << "\nВведите номер выбранного пункта: ";
        cin >> item;
        cout << '\n';

        int minutes;
        switch (item)
        {
        case 1:
            check_function = check_lecture_plan_by_author; // присваиваем в указатель на функцию соответствующую функцию
            cout << "***** Доклады Иванова Ивана Ивановича *****\n\n";
            break;
        case 2:
            check_function = check_lecture_plan_by_duration; // присваиваем в указатель на функцию соответствующую функцию
            cout << "***** Доклады длительностью более 15 минут *****\n\n";
            break;
        case 3:
            minutes = process(lectures, size);
            cout << "***** Длительность самого длинного доклада *****\n\n";
            cout << minutes << "\n\n";
            break;
        default:
            throw "Некорректный номер пункта";
        }


        if (check_function)
        {
            int new_size;
            lecture_plan** filtered = filter(lectures, size, check_function, new_size);
            for (int i = 0; i < new_size; i++)
            {
                output(filtered[i]);
            }
            delete[] filtered;
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

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
    cout << "������������ ������ #4. GIT\n";
    cout << "������� #2. ��������� �����������\n";
    cout << "�����: Ivan Grechko\n\n";
    lecture_plan* lectures[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", lectures, size);
        cout << "***** ��������� ����������� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** ����� ������� **********/
            cout << "�����...: ";
            // ����� ������� ������
            cout << setw(2) << setfill('0') << lectures[i]->start.hours << ':';
            cout << setw(2) << setfill('0') << lectures[i]->start.minutes << " - ";
            // ����� ������� �����
            cout << setw(2) << setfill('0') << lectures[i]->finish.hours << ':';
            cout << setw(2) << setfill('0') << lectures[i]->finish.minutes << '\n';
            /********** ����� ������� **********/
            cout << "������..: ";
            // ����� ������� 
            cout << lectures[i]->author.last_name << " ";
            // ����� ������ ����� ����� ������
            cout << lectures[i]->author.first_name[0] << ". ";
            // ����� ������ ����� �������� ������
            cout << lectures[i]->author.middle_name[0] << ".\n";
            /********** ����� ���� **********/
            cout << "����....: ";
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
    cout << "������: 23��1�\n";
>>>>>>> data
    return 0;
}

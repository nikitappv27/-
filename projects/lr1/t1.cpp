#include <iostream>
#include <string>
#include "student.h"

using namespace std;

int main(int argc, char const *argv[])
{
    system("chcp 65001");
    
    //Задание 1
    cout << "Задание 1" << endl;

    const int LENGROUP = 7;
    int i = 0, i_person = 0, i_maxPoint = 0;
    string findPerson;
    const student_task1* person[LENGROUP]{nullptr};
    const student_task1* maxPoint[LENGROUP]{nullptr};

    student_task1 group[LENGROUP] = {
        {"Попов", "Никита", 231},
        {"Ворошилова", "Елизавета", 227},
        {"Костров", "Михаил", 231},
        {"Ворошилова", "Василиса", 231},
        {"Ворошилова", "Настя", 240},
        {"Ягуткин", "Никита", 229},
        {"Кряквин", "Фрол", 231}
    };

    cout << "Введите фамилию искомого человека: ";
    cin >> findPerson;

    cout << "\nГруппа:" << endl;
    for (i = 0; i < LENGROUP; i++) {
        if (findPerson == group[i].surname) {
            person[i_person++] = &group[i];
        }
        
        if (i != 0) {
            if (maxPoint[i_maxPoint]->point < group[i].point) {
                while (i_maxPoint != -1) {
                    maxPoint[i_maxPoint--] = nullptr;
                }
                maxPoint[++i_maxPoint] = &group[i];
            } else if (maxPoint[i_maxPoint]->point == group[i].point) {
                maxPoint[++i_maxPoint] = &group[i];
            }
        } else {    
            maxPoint[i_maxPoint] = &group[i];
        }

        cout << group[i].surname << " " << group[i].name << " " << group[i].point << endl;
    }

    if (i_person == 0){ 
        cout << "\nИскомый человек не найден" << endl;
    } else {
        cout << "\nИскомый человек: " << endl;
        i = 0;
        while (true) {
            if (person[i] != nullptr){
                cout << person[i]->surname << " " << person[i]->name << " " << person[i]->point << endl;
                i++;
            } else {
                break;
            }
        }
    }

    cout << "\nСамый высокий балл группы: " << endl;
    i = 0;
        while (true) {
            if (maxPoint[i] != nullptr){
                cout << maxPoint[i]->surname << " " << maxPoint[i]->name << " " << maxPoint[i]->point << endl;
                i++;
            } else {
                break;
            }
        }
    for (i = 0; i <= i_maxPoint; i++) {
        
    }
    return 0;
}

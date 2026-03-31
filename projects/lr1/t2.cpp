#include <iostream>
#include <string>
#include <ctime>
#include "tasks.h"

using namespace std;

void printBirth (const student_task2& student) {
    cout << student.dateOfBirth.day << "." << student.dateOfBirth.mon << "." << student.dateOfBirth.year << endl;
}


int main(int argc, char const *argv[])
{
    system("chcp 65001");
    
    cout << "Задание 2" << endl;

    const int LENGROUP = 5;
    const student_task2* fit[LENGROUP]{nullptr};
    int i = 0, i_fit = 0;

    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    int fit_year = ltm.tm_year + 1900, fit_month = ltm.tm_mon + 1, fit_day = ltm.tm_mday, age;

    student_task2 group[LENGROUP]{
        {{23, 2, 2008}, "Попов", "Никита", 'M'},
        {{21, 2, 2006}, "Ворошилова", "Елизавета", 'F'},
        {{21, 2, 2008}, "Костров", "Михаил", 'M'},
        {{4, 1, 2008}, "Костров", "Никита", 'M'},
        {{24, 5, 2007}, "Парамонова", "Василиса", 'F'}
    };

    cout << "\nГруппа:" << endl;
    for (i = 0; i < LENGROUP; i++) {
        if (group[i].gender == 'M') {
            if (fit_year - group[i].dateOfBirth.year > 18) {
                fit[i_fit++] = &group[i];
            } else if (fit_year - group[i].dateOfBirth.year == 18) {
                if (fit_month > group[i].dateOfBirth.mon) {
                    fit[i_fit++] = &group[i];
                } else if (fit_month == group[i].dateOfBirth.mon && fit_day >= group[i].dateOfBirth.day) {
                    fit[i_fit++] = &group[i];
                }
            }
        }

        cout << group[i].surname << " " << group[i].name << " " << group[i].gender << " ";
        printBirth(group[i]);
    }
    
    if (i_fit == 0){ 
        cout << "\nПризывников не найдено" << endl;
    } else {
        cout << "\nПризвать: " << endl;
        i = 0;
        while (true) {
            if (fit[i] != nullptr && i != LENGROUP){
                cout << fit[i]->surname << " " << fit[i]->name << " " << " ";
                printBirth(*fit[i]);
                i++;
            } else {
                break;
            }
        }
    }

    return 0;
}

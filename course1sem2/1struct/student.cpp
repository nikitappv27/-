//student.cpp
#include "student.h"  // Подключаем наш чертёж, чтобы знать, что такое Student
#include <iostream>
#include <cstring>    // Для strcpy
#include <iomanip>    // Для форматирования вывода

using namespace std;

// Реализация функции: красиво вывести студента
void print(Student& s) {      // Принимает ссылку
    cout << s.name << "\n" << endl;           // Точка
}                    // Передаем просто переменную

void f1(Student s) { //По значению
    //Маленькие структуры (< 16 байт)  Безопасность (копия), но накладные расходы на копирование
}

void f2(Student* s) { //По указателю
    //Большие структуры, изменение оригинала 
}

void f3(Student& s) { //По ссылке
    //Большие структуры, изменение оригинала, нет nullptr
}

void f4(const Student& s) { //По указателю
    //Только чтение 
}

// Возврат по значению (современные компиляторы оптимизируют через RVO)
Student createStudent(char x, int y) {
    return {x, y};  // Uniform initialization (C++11)
}

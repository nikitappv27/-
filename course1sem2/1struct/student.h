// #pragma once (аналог ниже)
#ifndef STUDENT_H
#define STUDENT_H

// Описание структуры "Студент"
struct Student {
    char name[20];
    int marcs;
};

// Объявление функций (говорим: "они есть где-то в .cpp файле")
void print(Student& s);

#endif
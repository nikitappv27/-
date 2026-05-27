#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string surname;
    string name;
    int age;
    int course;

public:

    Student() {
        surname = "";
        name = "";
        age = 0;
        course = 0;
    }

    Student(string s, string n, int a, int c) {
        surname = s;
        name = n;
        age = a;
        course = c;
    }

    void print() const {
        cout << "Фамилия: " << surname
            << "\nИмя: " << name
            << "\nВозраст: " << age
            << "\nКурс: " << course
            << "\n-------------------" << endl;
    }

    string getSurname() const {
        return surname;
    }

    int getAge() const {
        return age;
    }

    string getName() const {
        return name;
    }

    int getCourse() const {
        return course;
    }
};
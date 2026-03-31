#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

struct day {
    int day;
    int mon;
    int year;
};

struct student_task1 {
    string surname;
    string name;
    int point;
};

struct student_task2 {
    day dateOfBirth;
    string surname;
    string name;
    char gender;
};

struct homeAddress {
    string street;
    int numberHouse;
    int numberFlat;
};

struct patient {
    homeAddress address;
    string surname;
    long long int insurancePolicyNumber;
    string diagnosis;
    
};
#endif
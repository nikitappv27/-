#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Patient {
private:
    char surname[50];
    char policy[19];
    char diagnosis[50];
    char street[100];
    int numberHouse;
    int numberFlat;
public:

    Patient() {
        strcpy(surname, "");
        strcpy(policy, "");
        strcpy(diagnosis, "");
        strcpy(street, "");
        numberHouse = 0;
        numberFlat = 0;
    }

    Patient(const char* s, const char* p, const char* d, const char* st, int house, int flat) {
        strcpy(surname, s);
        strcpy(policy, p);
        strcpy(diagnosis, d);
        strcpy(street, st);
        numberHouse = house;
        numberFlat = flat;
    }

    Patient(const char* s, const char* p, const char* d, const char* st, int house) {
        strcpy(surname, s);
        strcpy(policy, p);
        strcpy(diagnosis, d);
        strcpy(street, st);
        numberHouse = house;
        numberFlat = -1;
    }

    void print() const
    {
        cout << "Фамилия: " << surname
             << "\nПолис: " << policy
             << "\nДиагноз: " << diagnosis
             << "\nУлица: " << street
             << "\nДом: " << numberHouse;
        if (numberFlat != -1){
            cout << "\nКвартира: " << numberFlat;
        }
        cout << "\n----------------------\n";
    }

    const char* getSurname() const
    {
        return surname;
    }

    const char* getDiagnosis() const
    {
        return diagnosis;
    }

    const char* getPolicy() const {
        return policy;
    }
};
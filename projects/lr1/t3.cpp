#include<iostream>
#include<string>
#include "tasks.h"

using namespace std;

void printAddress(const patient& p) {
    if (p.address.numberFlat == -1) {
        cout << "улица " << p.address.street << " дом " << p.address.numberHouse << endl;
    } else {
        cout << "улица " << p.address.street << " дом " << p.address.numberHouse << " квартира " << p.address.numberFlat << endl;
    }

}

int main(int argc, char const *argv[])
{
    system("chcp 65001");
    const int LEN = 5;
    int i = 0, i_patient = 0;
    const patient* findPatients[LEN]{nullptr};
    string findStreet;

    patient patients[LEN] {
        {{"Московское шоссе", 21, 1}, "Параманова", 4351726581923764, "Covid-`9"},
        {{"Мария-Тореза", 20, 12014}, "Артемьев", 21412987636335577, "Ветрянка"},
        {{"Цветочная", 19, -1}, "Кузнецов", 123785242559638713, "Цинга"},
        {{"5 просека", 1, 1}, "Дикарёва", 7452369874175142, "Covid-`9"},
        {{"Цветочная", 231, 81}, "Артемьев", 7412145986523648, "ВИЧ"}
    };

    cout << "Введите искомую улицу: ";
    cin >> findStreet;

    cout << "\nБольные:" << endl;
    for (i = 0; i < LEN; i++) {
        if (findStreet == patients[i].address.street) {
            findPatients[i_patient++] = &patients[i];
        }
        cout << patients[i].surname << " " << patients[i].insurancePolicyNumber << " " << patients[i].diagnosis << " ";
        printAddress(patients[i]);
    }

    if (i_patient == 0){ 
        cout << "\nНа указанной вами улице пациентов не найдено" << endl;
    } else {
        i = 0;
        cout << "\nПациенты ";
        printAddress(*findPatients[i]);
        while (true) {
            if (findPatients[i] != nullptr && i != LEN){
                cout << findPatients[i]->surname << " " << findPatients[i]->insurancePolicyNumber << " " << findPatients[i]->diagnosis << endl;
                i++;
            } else {
                break;
            }
        }
    }

    return 0;
}

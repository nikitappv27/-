#include "handler.h"

Handler::Handler(const char* fname) {
    strcpy(filename, fname);
}

void Handler::saveList(const LinkedList& list) {
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cout << "Ошибка открытия файла\n";
        return;
    }

    Node* temp = list.getHead();
    while (temp != nullptr){
        fout.write((char*)&temp->data, sizeof(Patient));
        temp = temp->next;
    }
    fout.close();
}

LinkedList Handler::loadList() {
    LinkedList list;
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "Ошибка открытия файла\n";
        return list;
    }

    Patient temp;
    while (fin.read((char*)&temp, sizeof(Patient))) {
        list.addToTail(temp);
    }
    
    fin.close();
    return list;
}

void printMenu() {
    char surname[50];
    char policy[19];
    char diagnosis[50];
    char street[100];
    int numberHouse;
    int numberFlat;
    char switchChar;
    char helper[100];
    char delPolicy[19];

    cout << "Меню больницы, для дальнейшей работы выберите файл: ";

    cout << "Введите название бинарного файла .bin" << endl;
    cin >> helper;
    Handler file(helper);
    LinkedList list = file.loadList();

    while (true) {
        cout << "\nВыберете действие над файлом"
             << "\n1 - добавить данные"
             << "\n2 - удалить данные"
             << "\n3 - вывести данные на экран"
             << "\n4 - вывести диагнозы и список пациентов, подверженных ему"
             << "\n5 - очистить весь список"
             << "\n0 - сохранить бинарный файл и закончить работу" << endl;
        cin >> switchChar;
        if (switchChar) {
            cout << "неверно введенное число";
            return;
        }

        if (switchChar == '1') {
            cout << "\nЗаполнить форму:" << endl;
            cout << "фамилия: " << endl;
            cin >> surname;
            cout << "полис 18 символов: " << endl;
            cin >> policy;
            cout << "Диагноз: " << endl;
            cin >> diagnosis;
            cout << "Улица: " << endl;
            cin >> street;
            cout << "Номер дома: " << endl;
            cin >> numberHouse;
            cout << "Номер квартиры (-1 если нет): " << endl;
            cin >> numberFlat;

            if (numberFlat == -1) {
                list.addToTail(Patient(surname, policy, diagnosis, street, numberHouse));
            }
            else {
                list.addToTail(Patient(surname, policy, diagnosis, street, numberHouse, numberFlat));
            }

            strcpy(surname, "");
            strcpy(policy, "");
            strcpy(diagnosis, "");
            strcpy(street, "");
            numberHouse = 0;
            numberFlat = 0;
        }

        else if (switchChar == '2') {
            cout << "\nВведите полис пользователя для удаления: ";
            cin >> delPolicy;
            list.deleteByPolicy(delPolicy);
            strcpy(delPolicy, "");
        }

        else if (switchChar == '3') {
            cout << "список: ";
        }
    }
}
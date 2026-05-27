#include "handler.h"


void printMenu() {
    char surname[50];
    char policy[19];
    char diagnosis[50];
    char street[100];
    int numberHouse;
    int numberFlat;
    int switchChar;
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
             << "\n6 - отсортировать весь список"
             << "\n0 - сохранить бинарный файл и закончить работу" << endl;
        cin >> switchChar;
        if (switchChar < 0 || switchChar > 9) {
            cout << "неверно введенное число";
            return;
        }

        if (switchChar == 1) {
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

        else if (switchChar == 2) {
            cout << "\nВведите полис пользователя для удаления: ";
            cin >> delPolicy;
            list.deleteByPolicy(delPolicy);
            strcpy(delPolicy, "");
        }

        else if (switchChar == 3) {
            cout << "список:" << endl;
            list.printList();
        }

        else if (switchChar == 4) {
            cout << "списки диагнозов:" << endl;
            list.printDiagnosisStatistics();
        }

        else if (switchChar == 5) {
            list.clear();
            cout << "файл очищен" << endl;
        }

        else if (switchChar == 6) {
            list.sortBySurname();
            cout << "файл отсортирован";
        }

        else if (switchChar == 0) {
            file.saveList(list);
            cout << "файл сохранён";
            break;
        }
    }
}

int main()
{
    system("chcp 65001");
    printMenu();
    return 0;
}
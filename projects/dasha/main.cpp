#include "handler.h"


void printMenu() {
    char film[50];
    char sessionTime[6];
    int ticketPrice;
    int numberHall;
    int numberSeats;
    int switchChar;
    char helper[100];
    char delFilm[19];

    cout << "Меню Афиша, для дальнейшей работы выберите файл: ";

    cout << "Введите название бинарного файла .bin" << endl;
    cin >> helper;
    Handler file(helper);
    LinkedList list = file.loadList();

    while (true) {
        cout << "\nВыберете действие над файлом"
             << "\n1 - добавить данные"
             << "\n2 - удалить данные"
             << "\n3 - вывести данные на экран"
             << "\n4 - вывести максимально возможную выручку за каждый фильм"
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
            cout << "фильм: ";
            cin >> ws;
            cin.getline(film, 50);
            cout << "\nВремя: ";
            cin >> ws;
            cin.getline(sessionTime, 6);
            cout << "\nЦена: ";
            cin >> ticketPrice;
            cout << "\nНомер зала: ";
            cin >> numberHall;
            cout << "\nколичество мест: ";
            cin >> numberSeats;
            
            list.addToTail(Poster(film, sessionTime, ticketPrice, numberHall, numberSeats));

            strcpy(film, "");
            strcpy(sessionTime, "");
            ticketPrice = 0;
            numberHall = 0;
            numberSeats = 0;
        }

        else if (switchChar == 2) {
            cout << "\nВведите фильм пользователя для удаления: ";
            cin >> delFilm;
            list.deleteByFilm(delFilm);
            strcpy(delFilm, "");
        }

        else if (switchChar == 3) {
            cout << "список:" << endl;
            list.printList();
        }

        else if (switchChar == 4) {
            cout << ":" << endl;
            list.printMaximumRevenue();
        }

        else if (switchChar == 5) {
            list.clear();
            cout << "файл очищен" << endl;
        }

        else if (switchChar == 6) {
            list.sortByFilm();
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
#include <iostream>
#include <fstream>

using namespace std;

struct homeAddress {
    char street[100];
    int numberHouse;
    int numberFlat;
};

struct patient {
    homeAddress address;
    char surname[50];
    char insurancePolicyNumber[18];
    char diagnosis[50];
};

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
    const int LEN = 10;
    int i;
    patient mas[LEN];

    patient patients[LEN] {
        {{"Московское шоссе", 21, 1}, "Параманова", "4351726581923764", "Covid-`9"},
        {{"Мария-Тореза", 20, 12014}, "Артемьев", "21412987636335577", "Ветрянка"},
        {{"Цветочная", 19, -1}, "Кузнецов", "12378522559638713", "Цинга"},
        {{"5 просека", 1, 1}, "Дикарёва", "7452369874175142", "Covid-`9"},
        {{"Цветочная", 231, 81}, "Попов", "7412145986523668", "ВИЧ"},
        {{"Московское шоссе", 21, 1}, "Костров", "4351727581923764", "Covid-`9"},
        {{"Мария-Тореза", 20, 12014}, "Ибатулин", "21412987636335577", "Ветрянка"},
        {{"Цветочная", 19, -1}, "Ягуткин", "12785242559638713", "Цинга"},
        {{"5 просека", 1, 1}, "Ворошилова", "7452369874175142", "Covid-`9"},
        {{"Цветочная", 231, 81}, "Бышов", "7412145984543648", "ВИЧ"}
    };

    ofstream fileW("t3.bin", ios::binary);
    fileW.write((char*)patients, sizeof(patients));
    fileW.close();

    ifstream file("t3.bin", ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла";
        return 0;
    }

    file.read((char*)mas, sizeof(mas));
    cout << "Фамилия имя диагноз адрес" << endl;
    for (i = 0; i < LEN; i++) {
        cout << patients[i].surname << " " << patients[i].insurancePolicyNumber << " " << patients[i].diagnosis << " ";
        printAddress(patients[i]);
    }

    file.close();
    return 0;
}

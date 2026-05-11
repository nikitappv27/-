#include <iostream>
#include <fstream>

using namespace std;

struct student {
    char surname[30];
    char name[30];
    int group;
};

int main(int argc, char const *argv[])
{
    int a, b;
    student i, j;
    size_t sizeStudent = sizeof(student);

    fstream file("t1.bin", ios::in | ios::out | ios::binary);

    if (!file) {
        cout << "Ошибка открытия файла";
        return 0;
    }
    
    file.seekg(0, ios::end);
    int sizeFile = file.tellg();
    file.seekg(0, ios::beg);

    int sizeMas = sizeFile / sizeof(student);
    cout << "Назовите два числа от 0 до " << sizeMas - 1 << " что-бы поменять местами записи в файле: ";
    cin >> a >> b;

    if (a < 0 || a > sizeMas || b < 0 || b > sizeMas) {
        cout << "Числа введены неверно";
        return 0;
    }

    file.seekg(a * sizeStudent, ios::beg);
    file.read((char*)&i, sizeStudent);
    file.seekg(b * sizeStudent, ios::beg);
    file.read((char*)&j, sizeStudent);

    file.seekp(b * sizeStudent, ios::beg);
    file.write((char*)&i, sizeStudent);
    file.seekp(a * sizeStudent, ios::beg);
    file.write((char*)&j, sizeStudent);

    file.close();
    return 0;
}

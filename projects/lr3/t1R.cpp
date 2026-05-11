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
    system("chcp 65001");

    int i;
    ifstream file("t1.bin", ios::binary);

    if (!file) {
        cout << "Ошибка открытия файла";
        return 0;
    }
    
    file.seekg(0, ios::end);
    int sizeFile = file.tellg();
    file.seekg(0, ios::beg);

    int sizeMas = sizeFile / sizeof(student);
    student* mas = new student[sizeMas];

    file.read((char*)mas, sizeFile);

    cout << "Фамилия имя группа" << endl;
    for (i = 0; i < sizeMas; i++) {
        cout << mas[i].surname << " " << mas[i].name << " " << mas[i].group << endl;
    }

    file.close();
    return 0;
}

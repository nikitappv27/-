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
    const int CONST = 10;
    student mas[CONST] = {
        {"Попов", "Никита", 119},
        {"Ворошилова", "Елизавета", 119},
        {"Костров", "Михаил", 109},
        {"Ворошилова", "Настя", 103},
        {"Костров", "Никита", 119},
        {"Артемьев", "Фрол", 101},
        {"Кузнецов", "Михаил", 109},
        {"Попова", "Настя", 103},
        {"Артемьев", "Никита", 119},
        {"Дикарёв", "Фрол", 101}
    };
    
    ofstream file("t1.bin", ios::binary);
    file.write((char*)mas, sizeof(mas));
    file.close();

    return 0;
}
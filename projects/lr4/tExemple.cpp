#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct student {
    string surname;
    string name;
    int point;
    int group;
    int course;
};

int main(int argc, char const *argv[])
{
    system("chcp 65001");

    const int LENGROUP = 10;
    int i;
    student group[LENGROUP] = {
        {"Попов", "Никита", 231, 119, 1},
        {"Ворошилова", "Елизавета", 227, 103, 2},
        {"Костров", "Михаил", 201, 119, 1},
        {"Ворошилова", "Анастасия", 240, 119, 1},
        {"Костров", "Никита", 229, 104, 3},
        {"Артемьев", "Фрол", 203},
        {"Кузнецов", "Игорь", 131, 101, 1},
        {"Ибатулин", "Алексей", 247, 119, 1},
        {"Костров", "Михаил", 221, 103, 2},
        {"Годкова", "Анастасия", 208, 109, 4}
    };
    ofstream file("students.txt");
    for (i = 0; i < LENGROUP; i++) {
        file << group[i].surname << " " << group[i].name << " " << group[i].point << " " << group[i].group << " " << group[i].course << endl;
    }

    return 0;
}

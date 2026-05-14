#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct student {
    string surname;
    string name;
    int point;
    int group;
    int course;
};

int main(int argc, char const *argv[]) {
    student st;
    ifstream students("students.txt");
    ofstream studentProf("grant.txt");

    if (!students) {
        cout << "ошибка открытия";
        return 0;
    }

    while (students >> st.surname >> st.name >> st.point >> st.group >> st.group) {
        if (st.point >= 215) {
            studentProf << st.surname << " " << st.name << " " << st.point << " " << st.group << " " << st.group << endl;
        }
    }

    students.close();
    studentProf.close();

    return 0;
}

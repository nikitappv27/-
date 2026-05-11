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
    string element;
    string line;
    int i = 1, numberOfPoint = 3;
    
    ifstream students("students.txt");
    ofstream positive("grant.txt");

    while (getline(students, element)) {
        
    }
    
    students.close();
    positive.close();

    return 0;
}

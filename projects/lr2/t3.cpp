#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string numbers;
    string numbersHelper;
    bool flag = false;
    ifstream data("data.txt");
    ofstream data2("data2.txt");

    while (getline(data, numbers)) {
        if (flag) {
            data2 << numbers << endl;
            data2 << numbersHelper << endl;
            flag = false;
        } else {
            numbersHelper = numbers;
            flag = true;
        }
    }
    if (flag) {
        data2 << numbersHelper;
    }
    
    data.close();
    data2.close();

    return 0;
}

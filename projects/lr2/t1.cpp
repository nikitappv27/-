#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    double number;
    ifstream data("data.txt");
    ofstream positive("positive.txt");

    while (data >> number) {
        if (number > 0) {
            positive << number << " ";
        }
        if (data.peek() == '\n'){
            positive << endl;
        }
    }
    
    data.close();
    positive.close();

    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    int countP = 0;
    int countN = 0;
    string numbers;
    int number;
    ifstream data("input.txt");
    ofstream data2("output.txt");

    while (getline(data, numbers)) {
      istringstream stream(numbers);
      while (stream >> number) {
        if (number > 0) {
          countP++;
        } else if (number < 0) {
          countN++;
        }
      }
      if (countP == countN) {
        data2 << numbers;
      }
    }

    data.close();
    data2.close();

    return 0;
}

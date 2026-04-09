#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int main(int argc, char const *argv[]) {
    string typeStr;
    ifstream type("type.txt");
    ofstream typeCharacteristic("typeCharacteristic.txt");

    typeCharacteristic << left << setw(20) << "data type" << setw(10) << "byte" << setw(20) << "min value" << setw(20) << "max value" << endl;

    while (getline(type, typeStr)) {
        typeCharacteristic << left << setw(20) << typeStr;
        if (typeStr == "char") {
            typeCharacteristic << left
                << setw(10) << sizeof(char) 
                << setw(20) << (int)numeric_limits<char>::min() 
                << setw(20) << (int)numeric_limits<char>::max();
        }
        else if (typeStr == "short int") {
            typeCharacteristic << left
                << setw(10) << sizeof(short int)
                << setw(20) << numeric_limits<short int>::min()
                << setw(20) << numeric_limits<short int>::max();
        }
        else if (typeStr == "unsigned short int") {
            typeCharacteristic << left
                << setw(10) << sizeof(unsigned short int)
                << setw(20) << numeric_limits<unsigned short int>::min()
                << setw(20) << numeric_limits<unsigned short int>::max();
        }
        else if (typeStr == "int") {
            typeCharacteristic << left
                << setw(10) << sizeof(int)
                << setw(20) << numeric_limits<int>::min()
                << setw(20) << numeric_limits<int>::max();
        }
        else if (typeStr == "unsigned int") {
            typeCharacteristic << left
                << setw(10) << sizeof(unsigned int)
                << setw(20) << numeric_limits<unsigned int>::min()
                << setw(20) << numeric_limits<unsigned int>::max();
        }
        else if (typeStr == "long int") {
            typeCharacteristic << left
                << setw(10) << sizeof(long int)
                << setw(20) << numeric_limits<long int>::min()
                << setw(20) << numeric_limits<long int>::max();
        }
        else if (typeStr == "unsigned long int") {
            typeCharacteristic << left
                << setw(10) << sizeof(unsigned long int)
                << setw(20) << numeric_limits<unsigned long int>::min()
                << setw(20) << numeric_limits<unsigned long int>::max();
        }
        else if (typeStr == "float") {
            typeCharacteristic << left
                << setw(10) << sizeof(float)
                << setw(20) << numeric_limits<float>::min()
                << setw(20) << numeric_limits<float>::max();
        }
        else if (typeStr == "double") {
            typeCharacteristic << left
                << setw(10) << sizeof(double)
                << setw(20) << numeric_limits<double>::min()
                << setw(20) << numeric_limits<double>::max();
        }
        else if (typeStr == "long double") {
            typeCharacteristic << left
                << setw(10) << sizeof(long double)
                << setw(20) << numeric_limits<long double>::min()
                << setw(20) << numeric_limits<long double>::max();
        }
        typeCharacteristic << endl;
    }
    
    type.close();
    typeCharacteristic.close();

    return 0;
}

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
        if (typeStr == "char") {
            typeCharacteristic << left << setw(20) << "char"
                            << setw(10) << sizeof(char)
                            << setw(20) << (int)numeric_limits<char>::min()
                            << setw(20) << (int)numeric_limits<char>::max();
        }

        if (typeStr == "short int") {
            typeCharacteristic << left << setw(20) << "short int"
                            << setw(10) << sizeof(short int)
                            << setw(20) << numeric_limits<short int>::min()
                            << setw(20) << numeric_limits<short int>::max();
        }

        if (typeStr == "unsigned short int") {
            typeCharacteristic << left << setw(20) << "unsigned short int"
                            << setw(10) << sizeof(unsigned short int)
                            << setw(20) << numeric_limits<unsigned short int>::min()
                            << setw(20) << numeric_limits<unsigned short int>::max();
        }

        if (typeStr == "int") {
            typeCharacteristic << left << setw(20) << "int"
                            << setw(10) << sizeof(int)
                            << setw(20) << numeric_limits<int>::min()
                            << setw(20) << numeric_limits<int>::max();
        }

        if (typeStr == "unsigned int") {
            typeCharacteristic << left << setw(20) << "unsigned int"
                            << setw(10) << sizeof(unsigned int)
                            << setw(20) << numeric_limits<unsigned int>::min()
                            << setw(20) << numeric_limits<unsigned int>::max();
        }

        if (typeStr == "long int") {
            typeCharacteristic << left << setw(20) << "long int"
                            << setw(10) << sizeof(long int)
                            << setw(20) << numeric_limits<long int>::min()
                            << setw(20) << numeric_limits<long int>::max();
        }

        if (typeStr == "unsigned long int") {
            typeCharacteristic << left << setw(20) << "unsigned long int"
                            << setw(10) << sizeof(unsigned long int)
                            << setw(20) << numeric_limits<unsigned long int>::min()
                            << setw(20) << numeric_limits<unsigned long int>::max();
        }

        if (typeStr == "float") {
            typeCharacteristic << left << setw(20) << "float"
                            << setw(10) << sizeof(float)
                            << setw(20) << numeric_limits<float>::min()
                            << setw(20) << numeric_limits<float>::max();
        }

        if (typeStr == "double") {
            typeCharacteristic << left << setw(20) << "double"
                            << setw(10) << sizeof(double)
                            << setw(20) << numeric_limits<double>::min()
                            << setw(20) << numeric_limits<double>::max();
        }

        if (typeStr == "long double") {
            typeCharacteristic << left << setw(20) << "long double"
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

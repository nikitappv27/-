#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Patients
{
private:
    struct homeAddress {
        string street;
        int numberHouse;
        string numberFlat;
    };

    homeAddress address;
    string surname;
    string insurancePolicyNumber;
    string diagnosis;
    
public:
    Patients() = default;

    Patients(const string& st, int numH, const string& numF, const string& s, const string& p, const string& d) {
        address = {st, numH, numF};
        surname = s;
        insurancePolicyNumber = p; 
        diagnosis = d;
    }
    Patients(const string& st, int numH, const string& s, const string& p, const string& d) {
        address = {st, numH, ""};
        surname = s;
        insurancePolicyNumber = p; 
        diagnosis = d;
    }

    string toString() {
        return address.street + " " + to_string(address.numberHouse) + " " + address.numberFlat + " " +
            surname + " " + insurancePolicyNumber + " " + diagnosis;
    }

    string getterDiagnosis(){
        return diagnosis;
    }
};

int main(int argc, char const *argv[])
{
    system("chcp 65001");

    Patients p1("Цветочная", 19, "Ягуткин", "12785242559638713", "Цинга");
    Patients p2("5 просека", 1, "1", "Ворошилова", "7452369874175142", "Covid-19");
    Patients p3("Цветочная", 231, "81", "Бышов", "7412145984543648", "ВИЧ");

    cout << "Пациенты:" << "\nадрес: улица, дом, квартира (при наличии); фамилия; полис; диагноз" << endl;
    cout << p1.toString() << "\n" << p2.toString() << "\n" << p3.toString() << endl;
    cout << "Запрошенный диагноз пациента 1: " << p1.getterDiagnosis();

    ofstream patients("patients.txt");
    patients << p1.toString() << "\n" << p2.toString() << "\n" << p3.toString();
}

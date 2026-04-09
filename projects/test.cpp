#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct day {
  int day;
  int mon;
  int year;
};

struct Student {
  day dateofbirth;
  string surname;
  string name;
  string gender;
};

void printBirth(const Student& students) {
  cout << students.dateofbirth.day << "." << students.dateofbirth.mon << "." << students.dateofbirth.year << endl;
}
int main() {

  system("chcp 65001");

  const int N = 5;
  Student* fit[N]{ nullptr };
  int i = 0, i_fit = 0;

  time_t now = time(0);
  tm ltm;
  localtime_s(&ltm, &now);
  int fit_year = ltm.tm_year + 1900, fit_month = ltm.tm_mon + 1, fit_day = ltm.tm_mday, age;
  Student students[N]{
    { {14, 3, 2007}, "Костров", "Михаил", "M"},
    { {5, 1, 2008}, "Плешакова", "Анастасия", "Ж" },
    { {26, 4, 2007}, "Попов", "Никита", "М" },
    { {9, 5, 2007}, "Крепышев", "Михаил", "М" },
    { {1, 5, 2007}, "Ворошилова", "Лиза", "Ж" },
  };

  cout << "\nГруппа:" << endl;
  for (i =0; i < N; i++) {
    if (students[i].gender == "М") {
      if (fit_year - students[i].dateofbirth.year > 18) {
        fit[i_fit++] = &students[i];
      }
      else if (fit_year - students[i].dateofbirth.year == 18) {
        if (fit_month > students[i].dateofbirth.mon) {
          fit[i_fit++] = &students[i];
        }
        else if (fit_month == students[i].dateofbirth.mon && fit_day >= students[i].dateofbirth.day) {
          fit[i_fit++] = &students[i];
        }
      }
    }
    cout << students[i].surname << " " << students[i].name << " " << students[i].gender << " ";
    printBirth(students[i]);
  }

  if (i_fit== 0) {
    cout << "\nПризывников не найдено" << endl;
  }
  else {
    cout << "\nПризвать: " << endl;
    i = 0;

    for (int j = 0; j < i_fit; j++) {
      cout << fit[j]->surname << " " << fit[j]->name << " ";
      printBirth(*fit[j]);
    }
  }
}

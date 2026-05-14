#include <iostream>
#include <ctime>
#include <sstream>
#include <string>

using namespace std;

class Date
{
private:
    int day, month, year;

    time_t toTimeT() const {
        tm timeInfo = {};
        timeInfo.tm_mday = day;
        timeInfo.tm_mon = month - 1;
        timeInfo.tm_year = year - 1900;
        timeInfo.tm_hour = 0;
        timeInfo.tm_min = 0;
        timeInfo.tm_sec = 0;
        timeInfo.tm_isdst = -1;
        
        return mktime(&timeInfo);
    }

    int ifSmall (int y) {
    if (y < 1000) {
        return 2000 + y;
    }
    return y;
    }

public:
    Date(){
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);
        
        year = ltm.tm_year + 1900;
        month = ltm.tm_mon + 1;
        day = ltm.tm_mday;
    }
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = ifSmall(y);
    }
    Date(string s) {
        char sep;
        istringstream stream(s);
        stream >> day >> sep >> month >> sep >> year;
    }

    void setterDay(int val) {
        day = val;
    }
    void setterMonth(int val) {
        month = val;
    }
    void setterYear(int val) {
        year = ifSmall(val);
    }

    int getterDay() {
        return day;
    }
    int getterMonth() {
        return month;
    }
    int getterYear() {
        return year;
    }

    string toString() {
        string d, m;
        (day < 10) ? d = "0" + to_string(day) : d = to_string(day);
        (month < 10) ? m = "0" + to_string(month) : m = to_string(month);
        return d + '.' + m + '.' + to_string(year);
    }

    bool equals(const Date &d) const {
        return (day == d.day && month == d.month && year == d.year);
    }

    int daysTo(const Date &d) const {
        time_t time1 = toTimeT();
        time_t time2 = d.toTimeT();
        
        double diffSeconds = difftime(time2, time1);
        
        int diffDays = static_cast<int>(diffSeconds / 86400);
        
        return diffDays;
    }
};

int main(int argc, char const *argv[])
{
    Date d1;                    
    Date d2(26, 4, 26);
    Date d3("02.03.2007");

    cout << "даты:" << endl;
    cout << "d1: " << d1.toString() << endl;
    cout << "d2: " << d2.toString() << endl;
    cout << "d3: " << d3.toString() << endl;

    cout << "\nd2 и d3: ";
    cout << ((d2.equals(d3)) ? "равны" : "не равны");

    cout << "\nРазница в днях между d1 и d2: " << d1.daysTo(d2);
    return 0;
}
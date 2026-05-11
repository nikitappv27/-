#include <iostream>
#include <ctime>

using namespace std;

const int DMY = 10;

int ifSmall (int y) {
    if (y < 100) {
        return 2000 + y;
    }
    return y;
}

class Date
{
private:
    int day, month, year;
public:
    Date(){
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);
        year = ltm.tm_year + 1900, month = ltm.tm_mon + 1, day = ltm.tm_mday;
    }
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = ifSmall(y);
    }
    Date(char s[DMY]) {
        int flag = 0;
        year = 0;
        month = 0;
        day = 0;
        int helper = 1;
        for (int i = DMY-1; i >= 0; i--) {
            if (s[i] == '.' or s[i] == ',') {
                flag++;
                helper = 1;
                continue;
            }
            switch (flag)
            {
            case 0:
                year += (int)s[i]*helper;
                helper*=10;
                break;
            case 1:
                month += (int)s[i]*helper;
                helper*=10;
                break;
            case 2:
                day += (int)s[i]*helper;
                helper*=10;
                break;
            default:
                break;
            }
        }
    }
    void setterDay(int val) {
        if (val >= 0 && val <=31){
            day = val;
        }
    }
    void setterMonth(int val) {
        if (val > 0 && val <=12){
            month = val;
        }
    }
    void setterYear(int val) {
        if (val > 0){
            year = ifSmall(val);
        }
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
    char toString() {
        return (char)day << '.' << (char) month << '.' << (char) year;
    }
    bool equals(const Date &d other) {
        if (d1.getterYear() == d2.getterYear()) {
            if (d1.getterMonth() == d2.getterMonth()){
                if (d1.getterDay() == d2.getterDay()) {
                    return true;
                }
            }
        } 
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Date d1;
    Date d2(1, 3, 25);
    Date d3("12,2,13");
    return 0;
}

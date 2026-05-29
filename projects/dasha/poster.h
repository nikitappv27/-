#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Poster {
private:
    char film[50];
    char sessionTime[6];
    int ticketPrice;
    int numberHall;
    int numberSeats;
public:

    Poster() {
        strcpy(film, "");
        strcpy(sessionTime, "");
        ticketPrice = 0;
        numberHall = 0;
        numberSeats = 0;
    }

    Poster(const char* f, const char* s, int t, int h, int se) {
        strcpy(film, f);
        strcpy(sessionTime, s);
        ticketPrice = t;
        numberHall = h;
        numberSeats = se;
    }

    void print() const
    {
        cout << "Фильм: " << film
             << "\nВремя: " << sessionTime
             << "\nЦена билета: " << ticketPrice
             << "\nНомер зала: " << numberHall
             << "\nКол-во мест: " << numberSeats;
        cout << "\n----------------------\n";
    }

    const char* getFilm() const {
        return film;
    }

    const char* getTime() const {
        return sessionTime;
    }

    int getPrice() const {
        return ticketPrice;
    }

    int getNumHall() const {
        return numberHall;
    }

    int getNumSeats() const {
        return numberSeats;
    }
};
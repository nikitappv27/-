#pragma once

#include "node.h"

class LinkedList {
private:
    Node* head;
public:
    LinkedList();

    void addToTail(const Poster& p);

    void printList() const;

    void clear();

    void deleteByFilm(const char* film);

    void printMaximumRevenue();

    void sortByFilm();

    Node* getHead() const;
    
    ~LinkedList();
};
#pragma once
#include "node.h"

class LinkedList {
private:
    Node* head;

public:

    LinkedList() {
        head = nullptr;
    }

    void addToHead(const Student& st);

    void addToTail(const Student& st);

    void printList() const;

    void clear();

    void deleteLast();

    void printableFindBySurname(string surname);

    void printableFindByAge(int age);

    Node* findBySurname(string surname);

    Node* findByAge(int age);
};
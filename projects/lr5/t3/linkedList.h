#pragma once

#include "node.h"

class LinkedList {
private:
    Node* head;
public:
    LinkedList();

    void addToTail(const Patient& p);

    void printList() const;

    void clear();

    void deleteByPolicy(const char* policy);

    void printDiagnosisStatistics();

    void sortBySurname();

    Node* getHead() const;
    
    ~LinkedList();
};
#pragma once

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "linkedlist.h"

class Handler {
private:
    char filename[100];
public:
    Handler(const char* fname);
    void saveList(const LinkedList& list);
    LinkedList loadList();
};
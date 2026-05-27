#pragma once
#include "student.h"

struct Node {
    Student data;
    Node* next;

    Node(const Student& st) {
        data = st;
        next = nullptr;
    }
};
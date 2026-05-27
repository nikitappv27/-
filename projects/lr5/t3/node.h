#pragma once

#include "patient.h"

struct Node {
    Patient data;
    Node* next;
    Node(const Patient& p) {
        data = p;
        next = nullptr;
    }
};
#pragma once

#include "poster.h"

struct Node {
    Poster data;
    Node* next;
    Node(const Poster& p) {
        data = p;
        next = nullptr;
    }
};
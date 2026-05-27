#include "linkedlist.h"


void LinkedList::addToHead(const Student& s) {
    Node* newNode = new Node(s);
    newNode->next = head;
    head = newNode;
}

void LinkedList::addToTail(const Student& s) {
    Node* newNode = new Node(s);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::printList() const {
    if (head == nullptr) {
        cout << "Список пуст" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        temp->data.print();
        temp = temp->next;
    }
}

void LinkedList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::deleteLast() {
    if (head == nullptr) {
        return;
    }
    else if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

Node* LinkedList::findBySurname(string surname) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.getSurname() == surname) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

Node* LinkedList::findByAge(int age) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.getAge() == age) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void LinkedList::printableFindBySurname(string surname) {
    findBySurname(surname)->data.print();
}

void LinkedList::printableFindByAge(int age) {
    findByAge(age)->data.print();
}
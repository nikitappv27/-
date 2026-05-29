#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = nullptr;
}

void LinkedList::addToTail(const Poster& p) {
    Node* newNode = new Node(p);
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
        cout << "Список пуст\n";
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

void LinkedList::deleteByFilm(const char* film) {
    if (head == nullptr) {
        return;
    }

    if (strcmp(head->data.getFilm(), film) == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && strcmp(temp->next->data.getFilm(), film) != 0) {
        temp = temp->next;
    }

    if (temp->next != nullptr){
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

void LinkedList::printMaximumRevenue() {
    if (head == nullptr) {
        cout << "Список пуст\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        bool alreadyPrinted = false;
        Node* check = head;
        while (check != temp) {
            if (strcmp(check->data.getFilm(), temp->data.getFilm()) == 0) {
                alreadyPrinted = true;
                break;
            }
            check = check->next;
        }

        // Если фильм ещё не выводился
        if (!alreadyPrinted) {
            int revenue = 0;

            Node* current = head;
            while (current != nullptr) {
                if (strcmp(current->data.getFilm(), temp->data.getFilm()) == 0) {
                    revenue += current->data.getPrice() * current->data.getNumSeats();
                }
                current = current->next;
            }

            cout << "Фильм: " << temp->data.getFilm()
                 << "\nМаксимальная выручка: " << revenue
                 << "\n----------------------\n";
        }

        temp = temp->next;
    }
}

void LinkedList::sortByFilm() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    int size = 0;
    Node* temp = head;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }

    Node** arr = new Node*[size];
    temp = head;
    for (int i = 0; i < size; i++) {
        arr[i] = temp;
        temp = temp->next;
    }

    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            Node* current = arr[i];
            int j = i;
            while (j >= gap && strcmp(arr[j - gap]->data.getFilm(), current->data.getFilm()) > 0) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = current;
        }
    }

    head = arr[0];
    for (int i = 0; i < size - 1; i++) {
        arr[i]->next = arr[i + 1];
    }
    
    arr[size - 1]->next = nullptr;
    delete[] arr;
}

Node* LinkedList::getHead() const {
    return head;
}


LinkedList::~LinkedList()
{
    clear();
}
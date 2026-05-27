#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = nullptr;
}

void LinkedList::addToTail(const Patient& p) {
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

void LinkedList::deleteByPolicy(const char* policy) {
    if (head == nullptr) {
        return;
    }

    if (strcmp(head->data.getPolicy(), policy) == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && strcmp(temp->next->data.getPolicy(), policy) != 0) {
        temp = temp->next;
    }

    if (temp->next != nullptr){
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

void LinkedList::printDiagnosisStatistics() {
    Node* temp1 = head;
    while (temp1 != nullptr) {
        int count = 0;
        Node* temp2 = head;
        while (temp2 != nullptr) {
            if (strcmp(temp1->data.getDiagnosis(), temp2->data.getDiagnosis()) == 0) {
                count++;
            }
            temp2 = temp2->next;
        }

        bool alreadyPrinted = false;
        Node* temp3 = head;
        while (temp3 != temp1) {
            if (strcmp(temp1->data.getDiagnosis(), temp3->data.getDiagnosis()) == 0) {
                alreadyPrinted = true;
            }
            temp3 = temp3->next;
        }

        if (!alreadyPrinted){
            cout << temp1->data.getDiagnosis()
                 << " : "
                 << count
                 << endl;
        }
        temp1 = temp1->next;
    }
}

void LinkedList::sortBySurname() {
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
            while (j >= gap && strcmp(arr[j - gap]->data.getSurname(), current->data.getSurname()) > 0) {
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
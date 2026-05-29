#include "handler.h"

Handler::Handler(const char* fname) {
    strcpy(filename, fname);
}

void Handler::saveList(const LinkedList& list) {
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cout << "Ошибка открытия файла\n";
        return;
    }

    Node* temp = list.getHead();
    while (temp != nullptr){
        fout.write((char*)&temp->data, sizeof(Poster));
        temp = temp->next;
    }
    fout.close();
}

LinkedList Handler::loadList() {
    LinkedList list;
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "Ошибка открытия файла\n";
        return list;
    }

    Poster temp;
    while (fin.read((char*)&temp, sizeof(Poster))) {
        list.addToTail(temp);
    }
    
    fin.close();
    return list;
}
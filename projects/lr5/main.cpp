#include "linkedlist.h"

int main()
{
    system("chcp 65001");
    LinkedList list;
    int age;
    string surname;

    Student s1("Попов", "Никита", 19, 1);
    Student s2("Ворошилова", "Елизавета", 19, 2);
    Student s3("Костров", "Михаил", 20, 3);
    Student s4("Ворошилова", "Настя", 19, 2);
    Student s5("Артемьев", "Фрол", 20, 3);

    list.addToTail(s1);
    list.addToTail(s2);
    list.addToHead(s3);
    list.addToTail(s4);
    list.addToHead(s5);

    cout << "Список студентов:" << endl;
    list.printList();

    cout << "\nУдаление последнего студента из списка:" << endl;
    list.deleteLast();
    list.printList();

    cout << "\nОбращение по возрасту: ";
    cin >> age;
    list.printableFindByAge(age);

    cout << "\nОбращение по имени: ";
    cin >> surname;
    list.printableFindBySurname(surname);

    cout << "\nОчистка списка:" << endl;
    list.clear();
    list.printList();

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    system("chcp 65001");

    int const LEN = 100;
    int i;
    int arr[LEN];

    cout << "до сортировки" << endl;
    for (i = 0; i < LEN; i++){
        arr[i] = 10 + rand() % 90;
        if (i % 20 == 0 && i != 0) {
            cout << endl;
        }
        cout << arr[i] << " ";
    }

    for (int i = 0; i < LEN - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < LEN; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    cout << "\n\nпосле сортировки" << endl;
    for (int i = 0; i < LEN; i++){
        if (i % 20 == 0 && i != 0) {
            cout << endl;
        }
        cout << arr[i] << " ";
    }
}
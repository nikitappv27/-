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
        for (int j = 0; j < LEN - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "\n\nпосле сортировки" << endl;
    for (int i = 0; i < LEN; i++){
        if (i % 20 == 0 && i != 0) {
            cout << endl;
        }
        cout << arr[i] << " ";
    }
}
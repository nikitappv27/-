#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    system("chcp 65001");

    int const LEN = 100;
    int gap, i;
    int arr[LEN];

    cout << "до сортировки" << endl;
    for (i = 0; i < LEN; i++){
        arr[i] = 10 + rand() % 90;
        if (i % 20 == 0 && i != 0) {
            cout << endl;
        }
        cout << arr[i] << " ";
    }

    for (gap = LEN / 2; gap > 0; gap /= 2) {
        for ( i = gap; i < LEN; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }

    cout << "\n\nпосле сортировки" << endl;
    for (i = 0; i < LEN; i++){
        if (i % 20 == 0 && i != 0) {
            cout << endl;
        }
        cout << arr[i] << " ";
    }
}
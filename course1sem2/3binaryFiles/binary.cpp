#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
    system("chcp 65001");

    /*
    Двоичный файл — это файл, в котором данные хранятся в виде байтов (0 и 1) и не предназначены для чтения как текст.
    Хранит сырые данные файла
    */

    fstream file("t1.bin", ios::in | ios::out | ios::binary); //ios::binary - указывается режим чтения/записи (работает и с if/of)

    return 0;
}

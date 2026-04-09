#include <iostream>
#include <fstream> //работа с файлом
#include <string>

using namespace std;

int main(int argc, char const *argv[]){
    system("chcp 65001");
    /*
    Файл — это именованная область данных на носителе (например, диск), содержащая последовательность байтов
    Типы:
    - текстовый (символы, читается в блокноте)
    - бинарный (байты, не читаются напрямую)
    */

    //запись в файл (Если файл существует → он перезапишется)
    ofstream file_fout("example1.txt");// открыть файл
    file_fout << "Hello" << "\n" << 1;     // Данные записываются как текст, даже числа
    file_fout.close();             // закрыть

    //чтение файла
    ifstream file_fin("example2.txt");
    string strF;
    char c[100];

    strF = file_fin.get();   // читает символ
    cout << strF << endl;
    
    file_fin >> strF;        // читает до пробела
    cout << strF << endl;

    file_fin.getline(c, 100); // читает строку
    cout << c << endl;
    //прочитанные символы одним методом не возвращают "курсор" в начальное положение
    
    //курсоры
    file_fin.seekg(0);//seekp(0);  1 - в начало для чтения 2 - в начало для записи

    //проверка ошибки открытия файла
    if (!file_fin) {
        cout << "Ошибка открытия файла" << endl;
    } else {
        cout << "Файл открыт" << endl;
    }

    file_fin.close();

    //ios - Режимы открытия файлов
    /*
    fstream - чтение и запись
    | Режим         | Описание           |
    | ------------- | ------------------ |
    | `ios::in`     | чтение             |
    | `ios::out`    | запись             |
    | `ios::app`    | добавление в конец |
    | `ios::trunc`  | очистка файла      |
    | `ios::binary` | бинарный режим     |
    комбинируются и ставятся после открытия файла
    .open("file.txt", ios::out | ios::app);
    */
   
    fstream fin("example3.txt", ios::in | ios::out);
    //Работа до конца файла (EOF) и проверка на пустой файл
    string finStr;
    if (fin.peek() == EOF) { //проверка на  пустоту
        cout << "Файл пустой";
        fin << "Hello\n1";
        fin.flush();   // записать в файл
        fin.seekg(0);
    }
    while (fin >> finStr) { //полный проход по файлу посимвольно
        cout << finStr << endl;
    }
    
    return 0;
}

//Вариант 12 - сформировать двумерный массив и удалить из него все строки, в которых встречается заданное число
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(0));

    int stro = 4;
    int stol = 3;
    int min_val = 1;
    int max_val = 10;
    int t;
    int udal = 0;
    int c = 0;
    int** mat1 = new int* [stro];

    for (int i = 0; i < stro; i++) {
        mat1[i] = new int[stol];
    }

    for (int i = 0; i < stro; i++){
        for (int j = 0; j < stol; j++) {
            mat1[i][j] = rand() % (max_val - min_val + 1) + min_val;
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Введите число от 1 до 10: ";
    cin >> t;

    for (int i = 0; i < stro; i++) {
        bool flag = false;
        for (int j = 0; j < stol; j++) {
            if (mat1[i][j] == t) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            udal++;
        }
    }

    int** mat2 = new int* [udal];
    for (int i = 0; i < udal; i++) {
        mat2[i] = new int[stol];
    }

    for (int i = 0; i < stro; i++) {
        bool flag = false;
        for (int j = 0; j < stol; j++) {
            if (mat1[i][j] == t) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            for (int j = 0; j < stol; j++) {
                mat2[c][j] = mat1[i][j]; 
            }
            c++;
        }
    }

    for (int i = 0; i < udal; i++) {
        for (int j = 0; j < stol; j++) {
            cout << mat2[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < stro; i++) {
        delete[] mat1[i];
    }
    delete[] mat1;

    for (int i = 0; i < udal; i++) {
        delete[] mat2[i];
    }
    delete[] mat2;

    return 0;
}

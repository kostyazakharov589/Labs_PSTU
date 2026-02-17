//Вариант 12
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int m = 5;
const int n = 6;

int maxstroka(int arr[][m], int stro, int c) {
    int max = arr[stro][0];
    for (int j = 1; j < c; j++) {
        if (arr[stro][j] > max) {
            max = arr[stro][j];
        }
    }
    return max;
}

int main() {

    srand(time(0));
    setlocale(LC_ALL, "Russian");

    int arr[n][m];
    int range_min = 2;
    int range_max = 1000;
    int shift;
    int c;
    int stro = 3;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % (range_max - range_min + 1) + range_min;
        }
    }

    cout << " Исходный: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Строка номер " << stro + 1 << endl;
    cout << endl;

    int maxelem = maxstroka(arr, stro, m);

    shift = maxelem % m;
    for (int s = 0; s < shift; s++) {
        int temp = arr[stro][m - 1];
        for (int j = m - 1; j > 0; j--) {
            arr[stro][j] = arr[stro][j - 1];
        }
        arr[stro][0] = temp;
    }
    
    cout << "Максимальный элемент " << maxelem << " смещение на " << shift << endl << endl;
    cout << " Полученный массив: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


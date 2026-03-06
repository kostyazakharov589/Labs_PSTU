//задача о 8 ферзях с визуализацией
#include <iostream>
using namespace std;

const int s = 8;
int arr[8][8] = { 0 };
int kolvo = 0;

bool stvit(int stro, int kol) {
    for (int i = 0; i < kol; i++) {
        if (arr[stro][i] == 1) {
            return false;
        }
    }

    for (int i = stro, j = kol; i >= 0 && j >= 0; i--, j--) {
        if (arr[i][j] == 1) {
            return false;
        }
    }

    for (int i = stro, j = kol; i < s && j >= 0; i++, j--) {
        if (arr[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void doska() {
    cout << "  *-----------------*" << endl;
    for (int i = 0; i < s; i++) {
        cout << 8 - i << " |";
        for (int j = 0; j < s; j++) {
            if (arr[i][j] == 1) {
                cout << " Q";
            }
            else {
                cout << " *";
            }
        }
        cout << " |" << endl;
    }
    cout << "  *-----------------*" << endl;
    cout << "    a b c d e f g h" << endl << endl;
}

void res(int b) {
    if (b >= s) {
        kolvo++;
        cout << "   Попытка номер " << kolvo << endl;
        doska();
        return;
    }

    for (int a = 0; a < s; a++) {
        if (stvit(a, b)) {
            arr[a][b] = 1;
            res(b + 1);
            arr[a][b] = 0;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "задача о 8 ферзях" << endl << endl;
    res(0);
    cout << "всего попыток " << kolvo << endl;

    return 0;
}

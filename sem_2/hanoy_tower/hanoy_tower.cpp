#include <iostream>
using namespace std;

void hanoi(int n, int d1, int to, int k) {
    if (n == 1) {
        cout << "переместить 1 диск с " << d1 << " на " << to << endl;
        return;
    }

    hanoi(n - 1, d1, k, to);
    cout << "Переметить " << n << " с " << d1 << " на " << to << endl;
    hanoi(n - 1, k, to, d1);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int disks;
    cin >> disks;
    cout << "Используется " << disks << " диск(ов)" << endl << endl;
    hanoi(disks, 1, 3, 2); 

    return 0;
}

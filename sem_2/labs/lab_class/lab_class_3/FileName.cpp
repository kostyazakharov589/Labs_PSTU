//Вариант 12 - 
#include <iostream>
#include <windows.h>
#include <string>
#include "h1.h"
using namespace std;


int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
        Pair p1(10, 5.5);
        Pair p2(10, 7.1);

        cout << p1 << endl;
        cout << p2 << endl;

        if (p1 > p2) cout << "p1 > p2" << endl;
        else cout << "p1 <= p2" << endl;

        if (p1 < p2) cout << "p1 < p2" << endl;
        else cout << "p1 >= p2" <<  endl;

        ++p1;
        cout << p1 << endl;

        p1++;
        cout << p1 << endl;

        Pair p3;
        cin >> p3;
        cout << p3 << endl;

        return 0;
    }
//Вариант 12 - 
#include <iostream>
#include <windows.h>
#include <string>
#include "h1.h"
using namespace std;

kvit make_tovar()
{
    string s;
    int i;
    double d;
    cout << "дата";
    cin >> s;
    cout << "номер ";
    cin >> i;
    cout << "стоимость";
    cin >> d;
    kvit t(i, s, d);
    return t;
}
void print_kvit(kvit t)
{
    t.show();
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    //конструктор без параметров
    kvit t1;
    t1.show();
    //коструктор с параметрами
    kvit t2(123, "17 декабря", 123.98);
    t2.show();
    //конструктор копирования
    kvit t3 = t2;
    t3.set_naimenovanie("20 октября");
    t3.set_kolichestvo(2);
    t3.set_stoimost(5000.0);
    //конструктор копирования
    print_kvit(t3);
    //конструктор копирования
    t1 = make_tovar();
    t1.show();

    return 0;
}
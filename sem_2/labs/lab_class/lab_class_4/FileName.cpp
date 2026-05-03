//Вариант 12 - 
#include <iostream>
#include <windows.h>
#include <string>
#include "h1.h"
#include "h2.h"
using namespace std;

void f1(Person& p) {
    p.set_name("Олег");
    cout << p;
}

Person f2() {
    Student s("Анна", 20, 2);
    return s;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Person a;
    cin >> a;
    cout << a;

    Person b("ИИван", 25);
    cout << b;
    a = b;
    cout << a;

    cout << endl;

    Student c;
    cin >> c;
    cout << c;
    c.increase_age();
    c.increase_year();

    cout << endl;
    cout << c;
    cout << endl;

    f1(c);
    cout << endl;
    a = f2();
    cout << a;
    cout << endl;
    return 0;
}
//Вариант 12 - Поле first – целое положительное число, продолжительность телефонного разговора в минутах, поле second –  
// дробное положительное число, стоимость одной минуты разговора в рублях.
// Реализовать метод cost() –вычисление общей стоимости разговора
#include <iostream>
#include <windows.h>

using namespace std;

class phone {
public:
    unsigned int first; 
    double second;      
    void in(unsigned int f, double s) {
        first = f;
        second = s;
    }
    void vvod() {
        cout << "Введите продолжительность разговора в минутах: ";
        cin >> first;
        cout << "Введите стоимость одной минуты ";
        cin >> second;
    }

    void vyv() {
        cout << "Продолжительность: " << first << " мин" << endl;
        cout << "Стоимость минуты: " << second << " руб" << endl;
    }
    double cost() {
        return first * second;
    }
};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    phone c;
    c.vvod();
    c.vyv();

    cout << "Итоговая стоимость звонка: " << c.cost() << " руб" << endl;
    return 0;
}
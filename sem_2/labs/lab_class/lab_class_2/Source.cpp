#include <iostream>
#include <windows.h>
#include <string>
#include "h1.h"
using namespace std;

kvit::kvit() {
    number = 0;
    name = "";
    sum = 0.0;
    cout << "без параметров" << endl;
}
kvit::kvit(int n, string y, double s) {
    number = n;
    name = y;
    sum = s;
    cout << "с параметрами" << endl;
}
kvit::kvit(const kvit& t) {
    number = t.number;
    name = t.name;
    sum = t.sum;
    cout << "копирования" << endl;
}
kvit::~kvit() {
    cout << "деструктор" << endl;
}
string kvit::get_naimenovanie()
{
    return name;
}
int kvit::get_kolichestvo()
{
    return number;
}
double kvit::get_stoimost()
{
    return sum;
}

void kvit::set_naimenovanie(string n)
{
    name = n;
}
void kvit::set_kolichestvo(int y)
{
    number = y;
}
void kvit::set_stoimost(double s)
{
    sum = s;
}

void kvit::show()
{
    cout << "дата: " << name << endl;
    cout << "номер :" << number << endl;
    cout << "сумма :" << sum << endl;
}
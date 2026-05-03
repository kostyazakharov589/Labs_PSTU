#include <iostream>
#include <windows.h>
#include <string>
#include "h1.h"
using namespace std;

Pair::Pair() {
    first = 0;
    second = 0.0;
}

Pair::Pair(int f, double s) {
    first = f;
    second = s;
}

Pair::Pair(const Pair& p) {
    first = p.first;
    second = p.second;
}

Pair::~Pair() {}

int Pair::get_first() { 
    return first; 
}
double Pair::get_second() { 
    return second; 
}
void Pair::set_first(int f) { 
    first = f; 
}
void Pair::set_second(double s) { 
    second = s;
}

Pair& Pair::operator=(const Pair& p) {
    if (this == &p) return *this;
    first = p.first;
    second = p.second;
    return *this;
}

bool Pair::operator>(const Pair& p) {
    if (first > p.first) return true;
    if (first == p.first && second > p.second) return true;
    return false;
}

bool Pair::operator<(const Pair& p) {
    if (first < p.first) return true;
    if (first == p.first && second < p.second) return true;
    return false;
}

Pair& Pair::operator++() {
    first++;
    return *this;
}

Pair Pair::operator++(int) {
    Pair temp(*this);
    second++;
    return temp;
}

ostream& operator<<(ostream& out, const Pair& p) {
    out << p.first << " и " << p.second;
    return out;
}

istream& operator>>(istream& in, Pair& p) {
    in >> p.first >> p.second;
    return in;
}
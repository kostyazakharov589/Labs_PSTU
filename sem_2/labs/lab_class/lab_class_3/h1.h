#pragma once
#include <iostream>

using namespace std;

class Pair {
    int first;
    double second;
public:
    Pair();
    Pair(int, double);
    Pair(const Pair&);
    ~Pair();

    int get_first();
    double get_second();
    void set_first(int);
    void set_second(double);

    Pair& operator=(const Pair&);

    bool operator>(const Pair&);
    bool operator<(const Pair&);

    Pair& operator++();
    Pair operator++(int);

    friend ostream& operator<<(ostream&, const Pair&);
    friend istream& operator>>(istream&, Pair&);
};
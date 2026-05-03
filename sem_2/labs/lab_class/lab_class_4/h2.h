#pragma once
#include "h1.h"

class Student : public Person {
protected:
    int year;
public:
    Student();
    Student(string, int, int);
    Student(const Student&);
    ~Student();

    int get_year();
    void set_year(int);
    void increase_year();

    Student& operator=(const Student&);
    friend istream& operator>>(istream& in, Student& s);
    friend ostream& operator<<(ostream& out, const Student& s);
}; 

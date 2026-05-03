#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person();
    Person(string, int);
    Person(const Person&);
    virtual ~Person();

    string get_name();
    int get_age();
    void set_name(string);
    void set_age(int);
    void increase_age();
    Person& operator=(const Person&);
    friend istream& operator>>(istream& in, Person& p);
    friend ostream& operator<<(ostream& out, const Person& p);
};
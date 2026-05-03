#include "h1.h"

Person::Person() {
    name = "";
    age = 0;
}

Person::Person(string n, int a) {
    name = n;
    age = a;
}

Person::Person(const Person& p) {
    name = p.name;
    age = p.age;
}

Person::~Person() {}

string Person::get_name() { 
    return name; 
}
int Person::get_age() { 
    return age; 
}
void Person::set_name(string n) { 
    name = n; 
}
void Person::set_age(int a) { 
    age = a; 
}
void Person::increase_age() {
    age++;
}

Person& Person::operator=(const Person& p) {
    if (&p == this) return *this;
    name = p.name;
    age = p.age;
    return *this;
}

istream& operator>>(istream& in, Person& p) {
    cout << " Имя "; in >> p.name;
    cout << " Возраст "; in >> p.age;
    return in;
}

ostream& operator<<(ostream& out, const Person& p) {
    out << " Имя " << p.name << " Возраст: " << p.age << endl;
    return out;
}
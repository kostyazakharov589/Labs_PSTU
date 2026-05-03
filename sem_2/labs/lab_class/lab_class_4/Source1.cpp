#include "h2.h"

Student::Student() : Person() {
    year = 0;
}

Student::Student(string n, int a, int y) : Person(n, a) {
    year = y;
}

Student::Student(const Student& s) : Person(s) {
    year = s.year;
}

Student::~Student() {}

int Student::get_year() { 
    return year; 
}
void Student::set_year(int y) { 
    year = y; }
void Student::increase_year() {
    year++;
}

Student& Student::operator=(const Student& s) {
    if (&s == this) return *this;
    Person::operator=(s);
    year = s.year;
    return *this;
}

istream& operator>>(istream& in, Student& s) {
    cout << " имя: " ; in >> s.name;
    cout << " возраст: " ; in >> s.age;
    cout << " год обучения: "; in >> s.year;
    return in;
}

ostream& operator<<(ostream& out, const Student& s) {
    out << "имя: " << s.name << endl << " возраст: " << s.age << endl << " год обучения: " << s.year << " ";
    return out;
}
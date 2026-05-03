#pragma once
#include <string>
using namespace std;
class kvit {
	int number;
	string name;
	double sum;
public:
	kvit();
	kvit(int n, string y, double s);
	kvit(const kvit&);
	~kvit();
	string get_naimenovanie();
	void set_naimenovanie(string);
	int get_kolichestvo();
	void set_kolichestvo(int); 
	double get_stoimost();
	void set_stoimost(double); 
	void show();
};
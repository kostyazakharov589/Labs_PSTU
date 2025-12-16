#include <iostream>
int main() {
	float a = 2.1;
	float b = 10.4;
	std::cout << "a " << a << "  b " << b << std::endl;

	float *ua = &a;
	float *ub = &b;
	float s = *ua + *ub;
	std::cout << s << std::endl;

	return 0;
}



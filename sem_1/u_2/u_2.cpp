#include <iostream>

int main() {
	int a = 2;
	int b = 6;
	std::cout << "a - " << a << " b - " << b <<  std::endl;

	int *ua = &a;
	int *ub = &b;
	int c = *ub;

	*ub = *ua;
	*ua = c;
	std::cout << "a - " << a << " b - " << b << std::endl;
}

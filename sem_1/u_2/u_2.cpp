#include <iostream>

int main() {
	int a = 10;
	int b = 20;

	std::cout << "a - " << a << " b - " << b <<  std::endl;

	int *ua = &a;
	int *ub = &b;
	int c = *ub;

	*ub = *ua;
	*ua = c;
	std::cout << "a - " << a << " b - " << b << std::endl;
}

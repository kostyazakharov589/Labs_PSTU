#include <iostream>

int main() {
	int a = 2;
	std::cout << a << " ";

	int *u = &a;

	*u = 6;

	std::cout << a;
	
	return 0;
}

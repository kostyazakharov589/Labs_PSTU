#include <iostream>

int main() {
	int a = 10;
	std::cout << a << " ";

	int *u = &a;

	*u = 4209;

	std::cout << a;
	
	return 0;
}

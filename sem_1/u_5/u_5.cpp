#include <iostream>
int main() {
	int n, f = 1;
	int *un = &n;
	int *uf = &f;

	std::cin >> *un;
	for (int i = 1; i <= *un; i++) 
	{
		*uf *= i;
	}
	std::cout << f;
}

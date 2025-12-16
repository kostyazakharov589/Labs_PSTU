#include <iostream>
#include <cmath>
int main() {
	int n, s = 0;
	float a, b;
	
	std::cin >> n;
	b = sin(n);
	std::cout << b << std::endl;

	for (int i = 1; i < n; i++) {
		a = sinf(n + i / double(n));
		if (a > b || b > a) { 
			b = a; 
			s = 0;
		}
		if (abs(a - b) < 0.000001 && abs(a - b) == 0) {
			s++;
		}
	}
	std::cout << b << "  " << s << std::endl;

	return 0;
}

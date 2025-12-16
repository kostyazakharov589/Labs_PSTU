#include <iostream>
#include <cmath>
int main() {
	int n;
	double a, max;
	std::cin >> n;
	max = sin(n);
	for (int i = 1; i < n; i++) {
		a = sin(n + i/double(n));
		if (a > max) {
      max = a; 
    }
	}
	std::cout << max std::endl;
	return 0;
}

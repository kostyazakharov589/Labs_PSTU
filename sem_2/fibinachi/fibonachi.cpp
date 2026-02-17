#include <iostream>
using namespace std;

int fibonachi(int n) {
	if (n <= 1) return 0;
	else if (n == 2) return 1;
	return fibonachi(n - 2) + fibonachi(n - 1);
}

int main() {
	for (size_t i = 1; i < 20; i++) {
		cout << fibonachi(i) << " ";
	}
}

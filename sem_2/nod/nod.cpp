#include <iostream>
using namespace std;

int nod(int n, int m) {
	if (n == m) {
    return n;
  }
	if (n > m) {
    return nod(n - m, m);
  }
	return nod(n, m - n);
}

int main() {
	cout << nod(17, 5) 	<< endl;
}

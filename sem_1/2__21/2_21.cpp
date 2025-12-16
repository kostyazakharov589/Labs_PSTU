#include <iostream>
int main() {
	int n, b;
	bool f = 1;
	std::cin >> b;
	
	while (true) {
		std::cin >> n;
		if (b > n){ 
		    f = 0; 
		}
	    if (n == 0){
		    break;
		}
	}
	if (f == 1 && n == 0) {
		std::cout << "возрастающая";
	}
	if (f == 0) {
		std::cout << "не возрастающая";
	}
	return 0;
}

#include <iostream>
using namespace std;

int main() {
	int d, n, c = 0;
	std::cout << "Ввести число"<< std::endl;
	std::cin >> n;
	while( n != 0){
	    d = n % 10;   
        c = c * 10 + d;   
        n = n / 10;
	}
	std::cout << c << std::endl;
	
	
	return 0;

}

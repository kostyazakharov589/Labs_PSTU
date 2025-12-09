#include <iostream>

int main() {
	float a;
	std::cin >> a;
	if (a < 5){
	    std::cout<<a*3<<endl;
	}
	if (a >= 5 and a <= 7){
	    std::cout<<a+3<<endl;
	}
	else{
	    std::cout<<a/10<<endl;
	}
return 0;
}

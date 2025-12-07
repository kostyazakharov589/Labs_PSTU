#include <iostream>
using namespace std;
int main() {
	float a, b;
	std::cin >> a >> b;
	if (b == 0){
	    std::cout<<"не делить на 0"<<endl;
	}
	else{
	    std::cout<<a/b<<endl;
	}
return 0;
}

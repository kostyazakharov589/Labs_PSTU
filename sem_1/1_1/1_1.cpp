#include <iostream>
using namespace std;
int main() {
	int a, b, c, s;
	std::cin >> a >> b >> c;
	if (a>=b) {
	    s = a;
	}
	else{
	    s = b;
	}
	if (c>s){
	    s = c;
	}
	
std::cout<<s<<std::endl;
}

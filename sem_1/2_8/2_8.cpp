#include <iostream>

int main() {
	int n;
	std::cin >> n;
	if(n > 2){
	    for(int i = 0; i < n; i++)
	    {
	    for(int j = 0; j <= i; j++)
	    {
	        std::cout << "* ";
	    }
	        
	        std::cout << std::endl;
    	}
	    }
	else{
	    std::cout<< "больше 2" << std::endl;
	}
	return 0;
}


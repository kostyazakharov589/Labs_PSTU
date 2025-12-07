#include <iostream> 
int main(){
    int n;
    std::cin >>n;
    if(n>2){
        for(int i = 0; i < n; i++){
            for(int j = 1; j<n-1;j++){
                std::cout << " ";
            }
            for(int k = 0; k<=i;k++){
                std::cout << "*";
            }
        std::cout << std::endl;
        }
    }
    else{
        std::cout << "больше 2" << std::endl;
    }
    return 0;
}

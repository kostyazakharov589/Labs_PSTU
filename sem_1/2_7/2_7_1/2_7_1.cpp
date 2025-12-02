#include <iostream> 
#include <cmath>
int main(){
    int n;
    std::cin >> n;
    int k = sqrt(n);
    for(int i = 0;i < k;i++){
        for(int j = 0;j<k;j++){
            std::cout << "* ";
        }
    std::cout << std::endl;
    }
}

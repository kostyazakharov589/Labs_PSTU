#include <iostream> 
int main(){
    int n;
    std::cin >> n;
    int k = n / 2;
    int s = 1;
    if (n>3,n%2!=0){
        for (int i = 1; i <= (n+1)/2; i++)
        {
        for (int j = 0; j < k; j++)
        {
            std::cout << " ";
        }
        k--;
        for (int t = 0; t < s; t++)
        {
            std::cout << "*";
        }
        s += 2;
        std::cout << std::endl;
        }
    }
    else{
        std::cout << "больше 3 или нечётное число" << std::endl;
    }
}

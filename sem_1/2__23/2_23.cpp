#include <iostream>
#include <cmath>
int main(){
    float n, a, max;
    int i = 2; 
    int c = 1;
    std::cin >> n;
    max = sin(n + 1/n);
    while (i <= n)
    {
        a = sin(n + i/n);
        if (a > max)
        {
            max = a;
            c = 1;
        }
        else if (a == max) 
        { 
        c++; 
        }
        i++;
    }
    std::cout << "Макс эл: " << max << std::endl;
    std::cout << "Число эл: " << c << std::endl;
return 0;
}

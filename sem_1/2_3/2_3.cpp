#include <iostream> 
int main(){
    int n;
    int a, b = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        {
            a = 1;
            for (int j = i; j <= 2*i; j++)
            {
                a *= j;
            }
        b += a;
        }
    std::cout << a << std::endl;
}


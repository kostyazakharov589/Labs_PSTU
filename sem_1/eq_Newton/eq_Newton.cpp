//Вариант 12    0.1*a^2 - x*ln(x)  0,2x−lnx−1

#include <iostream>
#include <cmath>
int main()
{
    float x, xPrev;
    float t = 0.1; 
    float t2 = 0.2;
    
    x = 2; // x0 = b;
    xPrev = 0; // иницилизируем переменную x_{n-1} меньшим значением
    double eps = 0.000001;

     while(abs(x - xPrev) > eps)
    {
    xPrev = x;
    // теперь пишем формулу, где x_{i-1} - f(x_{i-1} / f'(x_{i-1}))

    x = xPrev - (((t*pow(x, 2)) - (x*log(x))) / (t2*x - (log(x)) - 1));
 }
 std::cout << "Корень: " << x << std::endl;
 return 0;
}




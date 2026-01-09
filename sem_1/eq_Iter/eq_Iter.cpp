//Вариант 12    0.1*a^2 - x*ln(x)  0,2x−lnx−1
#include <iostream>
#include <cmath>
int main()
{
    float x, xPrev;
    double eps = 0.000001;
    double lambda = 0.5;
    float t = 0.1;

    x = 1.12;
    xPrev = 0; 

    while(abs(x - xPrev) > eps)
     {
        xPrev = x;
        x = lambda * ((t * pow(x, 2)) - (x*log(x))) + xPrev; // вычисляем значение Фи
     }
    std::cout << "Корень по методу итераций: " << x << std::endl;
 return 0;
}







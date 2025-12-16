//Вариант 12    0.1*a^2 - x*ln(x) = 0

#include <iostream>
#include <cmath>
int main()
{
    double a, b, c;
    float t = 0.1;
    double fA, fB, fC;
    double eps = 0.0000001;

    a = 1;
    b = 2;

    while (b-a > eps)
 {
    c = (a + b) / 2;
    fA = ((t * pow(a, 2)) - (a*log(a)));
    fB = ((t * pow(b, 2)) - (b*log(b)));
    fC = ((t * pow(c, 2)) - (c*log(c)));

    if (fA * fC < 0) { 
        b = c; 
    }
    else if (fC * fB < 0) { 
        a = c; 
    }
    else { 
        std::cout << "----" << std::endl; 
        
    }
 }
    std::cout << "Корни " << a << " и " << b << std::endl;
 return 0;
}

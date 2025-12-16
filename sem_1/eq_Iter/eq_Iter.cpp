//Вариант 12    0.1*a^2 - x*ln(x)  0,2x−lnx−1
#include <iostream>
#include <cmath>
int main()
{
    float x, xPrev;
    double eps = 0.000001;
    double lambda = -0.05; // λ = -1/20 = -0.05
    float t = 0.1;

    x = 1.18; // можно выбрать любое x0 из [1, 2] — заданного по условию задачи промежутка, a или b берем по желанию
    xPrev = 0; // делаем заведомо меньше x

    while(abs(x - xPrev) > eps)
     {
        xPrev = x;
        x = lambda * ((t * pow(x, 2)) - (x*log(x))) + xPrev; // вычисляем значение Фи
     }
    std::cout << "Корень по методу итераций: " << x << std::endl;
 return 0;
}









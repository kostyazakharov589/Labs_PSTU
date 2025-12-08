#include <iostream> 
#include <cmath>
using namespace std;
int main(){

float a, b, c, d, x1, x2;
std::cin >> a >> b >> c;
d = pow(b, 2) - 4*a*c; // b*b - 4*a*c
if (d > 0)
{
 x1 = (-b + sqrt(d)) / (2*a);
 x2 = (-b - sqrt(d)) / (2*a);
 std::cout << "x1=" << x1 << "; x2=" << x2 << std::endl;
}
else if (d == 0)
{
 x1 = (-b) / (2*a)
 std::cout << "x1 = x2=" << x1 << std::endl;
}
else { std::cout << "Корней нет" << std::endl; }

return 0;
}


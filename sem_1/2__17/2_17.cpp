#include <iostream> 
#include <cmath>
using namespace std;
int main(){
int n;
float x, f, s;
std::cin >> n >> x;
s = 1 + x;
f = 1;
for (int i = 2; i <= n; i++)
{
  factorial *= i;
  sum += (pow(x, i) / factorial);
}

std::cout << sum << std::endl;
return 0;
}


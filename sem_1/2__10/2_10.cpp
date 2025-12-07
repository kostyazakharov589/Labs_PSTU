#include <iostream> 
using namespace std;
int main(){
int n, tmp, max;
std::cout << "длина последовательности:" << std::endl;
std::cin >> n;
cout << "Первое число:" << endl;
std::cin >> max;
for (int i = 2; i <= n; i++)
{
 std::cout << "Следующее число:" << std::endl;
 std::cin >> tmp;
 if (tmp > max) { 
  max = tmp; 
 }
}
std::cout << "Макс. эл.: " << max << std:;endl;

return 0;
}



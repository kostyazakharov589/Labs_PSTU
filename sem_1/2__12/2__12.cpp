#include <iostream> 

int main(){
int n, tmp, max, min;
std::cout << "Введите длину последовательности:" << std::endl;
std::cin >> n;
std::cout << "Введите первое число:" << std::endl;
std::cin >> tmp;
max = tmp;
min = tmp;
for (int i = 2; i <= n; i++)
{
 std::cout << "Введите следующее число:" << std::endl;
 std::cin >> tmp;
 if (tmp > max) { max = tmp; }
 else if (tmp < min) { min = tmp; }
}
std::cout << "Сумма максимального и минимального элементов: " << (max+min) <<
std::endl;

return 0;
}



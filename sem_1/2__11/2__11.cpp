#include <iostream> 

int main(){
int n, tmp;
bool plus1 = false; 
bool minus1 = false; 
std::cout << "Введите длину последовательности:" << std::endl;
std::cin >> n;
for (int i = 1; i <= n; i++)
{
 std::cin >> tmp;
 if (!plus1 && !minus1)
 {
 if (tmp > 0) { plus1 = true; }
 else if (tmp < 0) { minus1 = true; }
 }
}
if (plus1) { cout << "Сначала ввели положительное число"; }
else if (minus1) { std::cout << "Сначала ввели отрицательное число"; }
else { std::cout << "Все элементы были нулевыми"; }

std::cout << std::endl;
return 0;
}



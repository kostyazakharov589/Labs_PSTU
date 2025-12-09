#include <iostream> 

int main(){
int n, s, k;
bool flag = false;
std::cin >> n >> s;
while (n > 0 && !flag)
{
  k = n % 10;
 if (k == s)
 {
 flag = true;
 std::cout << "Цифра найдена" << std::endl;
 }
 else { n /= 10; }
}
if (!flag) { std::cout << "Цифра не найдена" << std::endl; }

return 0;
}



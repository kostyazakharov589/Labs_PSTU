#include <iostream> 

int main(){
int n;
int s = 0;
std::cin >> n;
while (n > 0)
{
 s += n % 10;
 n /= 10;
}
std::cout << s << std::endl;

return 0;
}



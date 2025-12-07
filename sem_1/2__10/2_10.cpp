#include <iostream> 
int main(){
int n, tmp, max;
cout << "длина последовательности:" << endl;
cin >> n;
cout << "Первое число:" << endl;
cin >> max;
for (int i = 2; i <= n; i++)
{
 cout << "Следующее число:" << endl;
 cin >> tmp;
 if (tmp > max) { max = tmp; }
}
cout << "Макс. эл.: " << max << endl;
return 0;
}

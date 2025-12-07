#include <iostream> 
int main(){
int n, tmp;
bool plus1 = false; 
bool minus1 = false; 
cout << "Введите длину последовательности:" << endl;
cin >> n;
for (int i = 1; i <= n; i++)
{
 cin >> tmp;
 if (!plus1 && !minus1)
 {
 if (tmp > 0) { plus1 = true; }
 else if (tmp < 0) { minus1 = true; }
 }
}
if (plus1) { cout << "Сначала ввели положительное число"; }
else if (minus1) { cout << "Сначала ввели отрицательное число"; }
else { cout << "Все элементы были нулевыми"; }
cout << endl;
return 0;
}
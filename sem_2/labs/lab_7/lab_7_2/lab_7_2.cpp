//Вариант 12 перевести число из десятичной в восьмиричную СС, вывести 3 5 8 чисел
#include <iostream>
#include <cstdarg>

using namespace std;
void treh(int co, ...) {
	setlocale(LC_ALL, "Russian");
	va_list(t);
	va_start(t, co);
	for (int i = 0; i < co; i++) {
		int d = va_arg(t, int);
		int n = d;
		int arr[20];
		int s = 0;
		if(n > 0){
		while(n > 0){
			arr[s] = n % 8;
			n = n / 8;
			s += 1;
			}
		}
		else {
			arr[0] = 0;
			s = 1;
		}
		for (int j = s-1; j >= 0; j--) {
			cout << arr[j];
		}
		cout << endl;
	}

}
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "3 числа 4, 17, 8 " << endl;
	treh(3, 4, 17, 8);
	cout << endl;

	cout << "5 чисел 17, 15, 1, 0, 4" << endl;
	treh(5, 17, 15, 1, 0, 4);
	cout << endl;

	cout << "8 чисел 21, 29, 7, 26, 49, 57, 41, 9" << endl;
	treh(8, 21, 29, 7, 26, 49, 57, 41, 9);
	return 0;
}

//12 вариант - деление десятичных и обыкновенных дробей 
#include <iostream>
using namespace std;
double del(int c, int d, int n1, int n2) {
	if (n1 != 0 && n2 != 0) {
		// (c/n1) / (d/n2) = (c/n1) * (n2/d) = (c*n2) / (n1*d)
		int chisl = c * n2;    
		int znam = n1 * d;        
		return (double)chisl / znam;
	}
	else {
		cout << "деление на 0" << endl;
		return 0;
	}
}
double del(double a, double b) {
	if (b != 0) {
		return a / b;
	}
	else {
		cout << "деление на 0" << endl;
		return 0;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");

	double a, b;
	cout << "деление десятичных дробей";
	cin >> a;
	cin >> b;
	cout << "итог:  " << del(a, b) << endl;

	cout << "деление обыкновенных дробей";
	int c, d, n1, n2;
	cout << "введите числитель и знаменатель";
	cin >> c >> n1;
	cout << "введите числитель и знаменатель для второй";
	cin >> d >> n2;
	cout << "итог:  " << del(c, d, n1, n2);

	return 0;
}

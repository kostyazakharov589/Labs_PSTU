//Вариант 12
#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

double cy(double x, double pi) {
    return -0.5*log(1.0 - 2.0 * x * cos(pi / 3.0) + x*x);
}

double csn(double x, int n, double pi) {
    double sn = 0.0;
    for (int c = 1; c <= n; c++) {
        sn += (pow(x ,c) * cos(c*pi /3.0)) / c;
    }
    return sn;
}

double cse(double x, double eps, double pi) {
    double se = 0.0;
    int it = 1;
    double term = (pow(x ,it) * cos(it*pi /3.0)) / it;

    while (abs(term) >= eps) {
        se += term;
        it++;
        term = (pow(x ,it) * cos(it*pi /3.0)) / it;
    }
    return se;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    const double a = 0.1;
    const double b = 0.8;
    const int k = 10;
    const int n = 35;
    const double step = (b - a) / k;
    const double eps = 0.0001;
    const double pi = 3.14159265359;

    for (int i = 0; i <= k; i++) {
        double x = a + i * step;
        double y = cy(x,pi);
        double sn = csn(x,n,pi);
        double se = cse(x,eps,pi);

        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "Сумма для заданного n: " << sn << " и для заданной точности eps: " << se << endl << endl;
    }

    return 0;
}

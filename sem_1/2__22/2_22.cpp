#include <iostream>
#include <cmath>
int main() {
	int num = 1;
	float a, max, n;
	std::cin >> n;
	max = sin(n + 1/n);
	int i = 2;
    while (i <= n)
    {
        a = sin(n + i/n);
        if (a > max)
        {
            max = a;
            num = i;
        }
        i++;
}
	std::cout << max << "  " << num << std::endl;
	return 0;
}

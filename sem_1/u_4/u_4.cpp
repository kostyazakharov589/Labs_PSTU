#include <iostream>
int main() {
	int b;
	float max, min, a;

	std::cin >> b;
	std::cin >> max;
	float *umax = &max;
	float *umin = &min;
	*umin = *umax;

	for (int i = 1; i < b; i++) {
		std::cin >> a;
		if (a > *umax) 
		{
			*umax = a;
		}
		if (a < *umin) 
		{
			*umin = a;
		}
	}
    std::cout << "max " << *umax << "  min " << *umin << std::endl;
}

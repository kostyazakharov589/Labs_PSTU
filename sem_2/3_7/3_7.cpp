#include <iostream>
using namespace std;
int main()
{
	const int n = 7; 
	int arr[n] = { 1, 3, 4, 5, 13, 100, 8 };


	int max = arr[0];
	int min = arr[0];
	setlocale(LC_ALL, "Russian");

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


	for (int i = 1; i < n; i++) {
		if (arr[i] > max) { 
			max = arr[i]; 
		}
		if (arr[i] < min) { 
			min = arr[i]; 
		}
	}


		cout << max << " и " << min << endl;


	return 0;
}

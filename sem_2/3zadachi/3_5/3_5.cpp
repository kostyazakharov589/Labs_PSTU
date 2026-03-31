#include <iostream>
using namespace std;
int main()
{
	const int n = 8;
	setlocale(LC_ALL, "Russian");
	int arr[n] = { 40, 54, 1, 0, 656, 77, 33, 9 };

	int max = arr[0];
	cout << arr[0] << " ";
	for (int i = 1; i < n; i++)
	{
		cout << arr[i] << " ";
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
		cout << endl;

		cout << "макс " << max << endl;

		return 0;
	}

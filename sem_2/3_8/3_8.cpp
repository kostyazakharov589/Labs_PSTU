#include <iostream>
using namespace std;
int main()
{
	const int n = 6;
	int arr[n] = { 3, 8, 17, 56, 51, 13 };

	int tmp[2 * n];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			tmp[j] = -1;
			j++;
		}
		tmp[j] = arr[i];
		j++;
	}
	for (int i = 0; i < j; i++)
	{
		cout << tmp[i] << " ";
	}
	cout << endl;

	return 0;
}

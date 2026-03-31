#include <iostream>
using namespace std;
int main()
{
	const int n = 7; 
	int arr[n] = { 1, 3, 4, 5, 13, 100, 8 };
	int k;
	int tmp[n];

	cin >> k;
	k = k % n;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


	for (int i = 0; i < n; i++)
	{
		int newe = i - k;
		if (newe < 0) { 
			newe += n; 
		}
		tmp[newe] = arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		arr[i] = tmp[i];
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}

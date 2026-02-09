#include <iostream>
using namespace std;



int main() {
    const int n = 6;
    int c = 0;
    int max;
    int arr[n] = { 0, 2, 1, 3, 5, 9 };
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    max = arr[0];
    for (int i = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
            c = 1;
        }
        else if (arr[i] = max) {
            c += 1;
        }
    }
        cout << max << " " << c << endl;
    return 0;
}

#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 8;
    int arr[n];
    int range_min = 1;
    int range_max = 280000;
    int max = 0;
    int min = 0;
    srand(time(0));  

    cout << "исходный" << endl;
    for (int i = 0; i < n; i++) {
        arr[i] = ((float)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        cout << arr[i] << " ";
    }
    cout << endl << endl;

     
    int max_value = arr[0];
    int min_value = arr[0];

    for (int i = 1; i < n; i++) {  
        if (arr[i] > max_value) {
            max_value = arr[i];
            max = i;
        }
        if (arr[i] < min_value) {
            min_value = arr[i];
            min = i;
        }
    }

    int temp = arr[min];
    arr[min] = arr[max];
    arr[max] = temp;
    cout << "поменяли местами" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double srednee = (sum / n) * 1.10;          
    cout << "среднее значение" << srednee << endl;

    int razm = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= srednee) {  
            arr[razm] = arr[i];     
            razm++;
        }
    }


    for (int i = 0; i < razm; i++) { 
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    return 0;
}

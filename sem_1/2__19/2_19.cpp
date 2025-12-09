#include <iostream>
using namespace std;

int main() {
    int n, s = 0;
    std::cout << "Введите кол-во слагаемых " << std::endl;
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        int r = i % 3;  
        if (r == 1 || r == 2){
            s += i;       
        }
        else{
            s -= i;
        }
    }

    std::cout << s << std::endl;
    return 0;
}

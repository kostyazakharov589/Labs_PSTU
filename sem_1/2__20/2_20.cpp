#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float n,s,a;
    int i = 1;
    bool flag = false;
    std::cin>> n >> s;
    while (i<= n || !flag){
        a = sin(n+ i/n);
        a = round(a*10)/10;
        std::cout<< n+i/n << "|" << a << std::endl;
        if( a== s) {
            flag = true;
        }
        else{ i++;}}
    if (flag){
        std::cout << i << std::endl;
    }
    else{
        std::cout<< "эл. не найден"<<std::endl;
    }
    return 0;
}

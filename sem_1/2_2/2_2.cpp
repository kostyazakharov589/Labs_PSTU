#include <iostream>
using namespace std;
int main() {
    int n, s = 1;
    std::cin >> n;
    if (n > 0){
        for (int i = 1;i<=n;i++){
            s*=i;
        }
        std::cout<<s<<std::endl;
    }
    else{
        std::cout<<"ввести больше 0"<<std::endl;
    }
    
return 0;
}

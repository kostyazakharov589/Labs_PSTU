#include <iostream>

int main() {
    int n, s = 0;
    std::cin >> n;
    if (n > 0){
        for (int i = 1;i<=n;i++){
            s = i*(i+1);
        }
        std::cout<<s<<std::endl;
    }
    else{
        std::cout<<"ввести больше 0"<<std::endl;
    }
    
return 0;
}


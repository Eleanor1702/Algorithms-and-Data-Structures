#include <iostream>

//der Code hier ist schneller
int ggT(int a, int b){
    int r = 1;

    do{
        r = a % b;
        a = b;
        b = r;
    }while (r != 0);

    return a;
}

int main() {
    int a = 0;
    int b = 0;

    std::cout << "Zahl 1:" << std::endl;
    std::cin >> a;

    std::cout << "Zahl 2:" << std::endl;
    std::cin >> b;

    std::cout<< ggT(a,b) << std::endl;

    return 0;
}
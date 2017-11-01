#include <iostream>

//in diesem Code läuft das program lamgsamer vom performance her...
int ggT(int a, int b, int r){
    if(r != 0){
        r = a % b;
        a = b;
        b = r;
    }else{
        return a;
    }

    return ( ggT(a, b, r) );
}

int main() {
    int a = 0;
    int b = 0;
    int r = 1;

    std::cout << "Zahl 1:" << std::endl;
    std::cin >> a;

    std::cout << "Zahl 2:" << std::endl;
    std::cin >> b;

    std::cout<< ggT(a, b, r) << std::endl;

    return 0;
}
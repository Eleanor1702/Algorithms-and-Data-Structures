#include <iostream>
#include <vector>

int function(int n, int m){
    if(n == 0){
        return (n,m+1);
    }else if(m == 0 && n >= 1){
        return function(n-1, 1);
    }else{
        return function(n-1, function(n, m-1));
    }
}

int main() {
    int n = 0;
    int m = 0;

    std::cout <<"n: ";
    std::cin >> n;
    std::cout <<"m: ";
    std::cin >> m;

    if(m < 0 || n < 0){
        std::cerr <<"m and n should be an Element of natural quantity inclu. 0"<< std::endl;
    }

    //function implementation
    std::cout << function(n, m);

    return 0;
}
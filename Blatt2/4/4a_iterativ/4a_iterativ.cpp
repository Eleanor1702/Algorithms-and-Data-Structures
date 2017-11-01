#include <iostream>
#include <vector>

int function(int n, int m){
    std::vector <int> n_elements;
    int i = n_elements.size() - 1;

    int terminate = 0;
    while(!terminate){
        if(n == 0){
            m = m + 1;
            if(i >= 0){
                n = n_elements[i];
                --i;
                n_elements.pop_back();
            }else if(i < 0){
                std::cout << m << std::endl;
                terminate = 1;
            }
        }else if(m == 0 && n >= 1){
            m = 1;
            n = n -1;
        }else{
            int tmp = 0;
            tmp = n -1;
            n_elements.push_back(tmp);
            i = n_elements.size() - 1;
            m = m -1;
        }
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
        return 1;
    }

    function(n, m);

    return 0;
}
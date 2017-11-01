#include <iostream>
#include <vector>

class MaxTeilSum{
public:

   MaxTeilSum(int n, int m){
        this->CorX = n;
        this->CorY = m;
        for(int i = 0; i < this->CorX; i++){
            for(int j = 0; j < this->CorY; j++){
                //To print the technically right Point...
                std::cout << "Point (" << i+1 << "," << j+1 << "): ";
                std::cin >> Vec2D[i][j];
            }
        }

    }
/*
    void Print(){
        //Ausgabe Test....
        for(int i = 0; i < this->CorX; i++){
            for(int j = 0; i < this->CorY; j++){
                std::cout <<Vec2D[i][j];
                std::cout << "  ";
            }
            std::cout << std::endl;
        }
    }
*/
private:
    int CorX;
    int CorY;
    std::vector <std::vector <int>> Vec2D;
};

int main() {
    int x = 0;
    int y = 0;

    std::cout << "Enter Coordinate X: ";
    std::cin >> x;
    std::cout << "Enter Coordinate Y: ";
    std::cin >> y;

    MaxTeilSum test(x, y);
    //test.Print();

    return 0;
}
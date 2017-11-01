#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

class Feld{

public:
    Feld(int n){
        this->size = n;
        for (int i = 0; i < n; i++) {
            Data.push_back(0);
        }
    }

    static Feld Init(int n) {
        return Feld(n);
    }

    void FillRandom(){
        srand(time(nullptr));
        for(int i = 0; i < this->size; i++){
            Data[i] = (rand() % (1000 - 0) + 0);
        }
    }

    void Print(){
        for(int i = 0; i < this->size; i++){
            std::cout << Data[i] << std::endl;
        }
    }
    void Min(){
        std::sort(Data.begin(), Data.end());
        std::cout << "Min: " << Data[0] << std::endl;
    }

    void Max(){
        std::sort(Data.begin(), Data.end());
        std::cout << "Max: " << Data[this->size - 1] << std::endl;
    }

    void Avg(){
        int total = 0;
        for(int i = 0; i < this->size; i++){
            total += Data[i];
        }
        std::cout << "Avg: "<< total/this->size << std::endl;
    }

private:
    int size = 0;
    std::vector<int> Data;
};


int main() {
    int zahl = 0;
    std::cout << "Size eingeben: " << std::endl;
    std::cin >> zahl;

    //statisches Methode wird nur mit der Klasse selbst aufgerufen
    Feld f = Feld::Init(zahl);

    f.FillRandom();
    f.Print();
    f.Min();
    f.Max();
    f.Avg();

    return 0;
}
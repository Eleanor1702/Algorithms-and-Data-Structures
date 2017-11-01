#include <iostream>
#include <vector>

class Sort{
public:
    Sort(){
        std::cout <<"Number of Elements: ";
        std::cin >> this->n;

        //test
        std::cout <<"You entered: " << n << std::endl;

        std::cout <<"Enter Elements: " << std::endl;
        int input = 0;
        for(auto i = 1; i <= this->n; i++){
            std::cin >> input;
            this->OriginalNumList.push_back(input);
        }

    };

    void ResetSortedList(){
        SortedList.clear();
        for(auto i :this->OriginalNumList){
            this->SortedList.push_back(i);
        }
    }

    void Insertionsort(){
        ResetSortedList();
        std::cout <<"Insertionsort: " << std::endl;
        std::cout <<"---------------------------" << std::endl;
        int i, j, key;

        for (j = 1; j < n; j++) {
            key = this->SortedList[j]; //second Element in vector
            i = j-1;

            // Comparing Key with previous Element in Vector
            while (i >= 0 && this->SortedList[i] > key) {  // Move Elements
                this->SortedList[i+1] = this->SortedList[i];
                i = i-1;
            }
            this->SortedList[i+1] = key; // Set Key in right position

            std::cout << j <<".Schritt: ";
            Print();
        }
        std::cout <<"---------------------------" << std::endl;
    }

    void Bubblesort(){
        ResetSortedList();
        std::cout <<"Bubblesort: " << std::endl;
        std::cout <<"---------------------------" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = n-2; j >=i; j--) {
                if (this->SortedList[j] > this->SortedList[j+1]) {
                    int h = this->SortedList[j];
                    this->SortedList[j] = this->SortedList[j+1];
                    this->SortedList[j+1] = h;
                }
            }
            std::cout << i+1 <<".Schritt: ";
            Print();
        }
        std::cout <<"---------------------------" << std::endl;
    }

    void Selectionsort(){
        ResetSortedList();
        std::cout <<"Selectionsort: " << std::endl;
        std::cout <<"---------------------------" << std::endl;
        int i, j, min;
        for (i = 0; i < n; i++) {
            min = i;

            // looking for actual Minimum
            for (j = i; j < n; j++) {
                if (this->SortedList[j] < this->SortedList[min])
                    min = j;
                }

            // replace with first Element in vector
            int h = this->SortedList[i];

            this->SortedList[i] = this->SortedList[min];
            this->SortedList[min] = h;

            std::cout << i+1 <<".Schritt: ";
            Print();
        }
        std::cout <<"---------------------------" << std::endl;
    }

    void Print(){
        for(auto i:this->SortedList){
            std::cout << i << " ";
        }
        std::cout << "\n";
    }

private:
    int n = 0;
    std::vector <int> OriginalNumList;
    std::vector <int> SortedList;
};

int main() {

    Sort try1;

    try1.Insertionsort();

    try1.Bubblesort();

    try1.Selectionsort();

    return 0;
}
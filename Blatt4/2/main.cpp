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

    }

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
            while (i >= 0 && this->SortedList[i] < key) {  // Move Elements
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
        for (int i = n-1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (this->SortedList[j] > this->SortedList[j+1]) {
                    int h = this->SortedList[j];
                    this->SortedList[j] = this->SortedList[j+1];
                    this->SortedList[j+1] = h;
                }
            }
            std::cout << n-i <<".Schritt: ";
            Print();
        }
        std::cout <<"---------------------------" << std::endl;
    }

    void Selectionsort(){
        ResetSortedList();
        std::cout <<"Selectionsort: " << std::endl;
        std::cout <<"---------------------------" << std::endl;
        int i, j, max;
        for (i = n-1; i > 0; i--) {
            max = i;

            // looking for actual Maximum
            for (j = i; j >= 0; j--) {
                if (this->SortedList[j] > this->SortedList[max])
                    max = j;
            }

            // replace with first Element in vector
            int h = this->SortedList[i];

            this->SortedList[i] = this->SortedList[max];
            this->SortedList[max] = h;

            std::cout << i+1 <<".Schritt: ";
            Print();
        }
        std::cout <<"---------------------------" << std::endl;
    }

    //the reason behind this is to make main clean of complication
    void StartQuicksort(){
        quicksort(this->SortedList, first, last);
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
    int first = 0;
    int last = n;

    void swap(int &element1, int &element2){
        int tmp = element2;
        element2 = element1;
        element1 = tmp;
    }

    void PreparePartition(const std::vector <int> SortedList, int first, int last, int &part) {
        //initialize random seed
        srand (time(NULL));
        //Pivot Element
        int pivot = this->SortedList[rand() % this->n-1];
        part = first-1;

        for(int i = first; i <= last; i++){
            if(this->SortedList[i] <= pivot){
                part++;
                swap(this->SortedList[i], this->SortedList[part]);
            }
        }

        //Pivot in right position
        swap(this->SortedList[first], this->SortedList[part]);
    }

    void quicksort(std::vector <int> SortedList, int first, int last){
        int part;

        if(first < last){
            PreparePartition(this->SortedList, first, last, part);
            quicksort(this->SortedList, first, part-1);
            quicksort(this->SortedList, first, part+1);

        }
    }
};

int main() {

    Sort try1;

    try1.Insertionsort();
    try1.Bubblesort();
    try1.Selectionsort();
    try1.StartQuicksort();
    try1.Print();

    return 0;
}
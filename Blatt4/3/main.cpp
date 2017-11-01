#include <iostream>
#include <vector>

class Sort{
public:
    Sort(){}

    void Init(long int parameter){
        this->elements = parameter;

        std::cout << "You entered: " << this->elements << std::endl;

        for (auto i = 1; i <= this->elements; i++) {
            this->SortedList.push_back(rand() % 1000);
        }
    }

    void Insertionsort(){
        int i, j, key;

        for (j = 1; j < elements; j++) {
            key = this->SortedList[j]; //second Element in vector
            i = j-1;

            // Comparing Key with previous Element in Vector
            while (i >= 0 && this->SortedList[i] > key) {  // Move Elements
                this->SortedList[i+1] = this->SortedList[i];
                i = i-1;
            }
            this->SortedList[i+1] = key; // Set Key in right position
        }
    }

    //the reason behind this is to make main clean of complication
    void StartQuicksort(){
        quicksort(this->SortedList, first, last);
    }

private:
    long int elements = 0;
    std::vector <int> SortedList;
    int first = 0;
    long int last = elements;

    void swap(int &element1, int &element2){
        int tmp = element2;
        element2 = element1;
        element1 = tmp;
    }

    void PreparePartition(const std::vector <int> &SortedList, int first, long int last, int &part) {
        //initialize random seed
        srand (time(NULL));
        //Pivot Element
        int pivot = this->SortedList[first];
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

    void quicksort(const std::vector <int> &SortedList, int first, long int last){
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

    long int n = 10000;

    time_t start, end;
    double elapsed;

    int terminate = 1;

    while(terminate){
        start = time(nullptr);

        try1.Init(n);
        try1.Insertionsort();

        end = time(nullptr);

        elapsed = difftime(end, start);
        std::cout << elapsed << std::endl;

        if(elapsed >= 60.0){ // 1 minute. Can be changed to 2, 5 or 10 minutes
            terminate = 0;
            std::cout <<"Elements: " << n << "\n";
        }else{
            n += 10000;
        }
    }

    long int m = 10000000;

    terminate = 1;

    while(terminate){
        start = time(nullptr);

        try1.Init(m);
        try1.StartQuicksort();

        end = time(nullptr);

        elapsed = difftime(end, start);
        std::cout << elapsed << std::endl;

        if(elapsed >= 60.0){ // 1 minute. Can be changed to 2, 5 or 10 minutes
            terminate = 0;
            std::cout <<"Elements: " << m << "\n";
        }else{
            m += 10000000;
        }
    }

    return 0;
}
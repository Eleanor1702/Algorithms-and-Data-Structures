#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>

int ggT(int a, int b){
    int r = 1;

    do{
        r = a % b;
        a = b;
        b = r;
    }while (r != 0);

    return a;
}

int img_arr_size(int zahl){

    return (ceil(log(zahl)/log(2)));
}

int kgV(int z_1, int z_2){
    int Faktor_1 = img_arr_size(z_1);
    int Faktor_2 = img_arr_size(z_2);
    int arr_1[Faktor_1];
    int arr_2[Faktor_2];
    int i = 0;
    int j = 0;

    //How many Prime numbers in the z_1
    for(int n = 2; n <= z_1; n++){
        if(z_1 % n == 0){
            arr_1[i] = n;
            i++;
            z_1 = z_1 / n;
            n = 1;
        }
    }

    //check if Faktor_1 = i
    if(Faktor_1 != i){
        Faktor_1 = i;
    }

    //Prime Numbers in z_2
    for(int n = 2; n <= z_2; n++){
        if(z_2 % n == 0){
            arr_2[j] = n;
            j++;
            z_2 = z_2 / n;
            n = 1;
        }
    }

    //check if Faktor_2 = j
    if(Faktor_2 != j){
        Faktor_2 = j;
    }

    std::map <int, int> prim_zahl_1;
    std::map<int, int> prim_zahl_2;

    //filter Prime Numbers in a map for arr_1
    for(int n = 0; n < Faktor_1; n++){
        if(prim_zahl_1.find(arr_1[n]) == prim_zahl_1.end()){
            prim_zahl_1[arr_1[n]] = arr_1[n];
        }else{
            prim_zahl_1[arr_1[n]] = prim_zahl_1[arr_1[n]] * arr_1[n];
        }
    }

    //filter Prime Numbers in a map for arr_2
    for(int n = 0; n < Faktor_2; n++){
        if(prim_zahl_2.find(arr_2[n]) == prim_zahl_2.end()){
            prim_zahl_2[arr_2[n]] = arr_2[n];
        }else{
            prim_zahl_2[arr_2[n]] = prim_zahl_2[arr_2[n]] * arr_2[n];
        }
    }

    std::vector<int> keys_1;
    std::vector<int> keys_2;

    //prim_zahl_1 in keys_1
    for(auto const& elem: prim_zahl_1)
        keys_1.push_back(elem.first);

    //prim_zahl_2 in keys_2
    for(auto const& elem: prim_zahl_2)
        keys_2.push_back(elem.first);

    int total = 1;

    //obtaining the result from key 1
    for(int n = 0; n < keys_1.size(); n++){
        if(prim_zahl_2.find(keys_1[n]) == prim_zahl_2.end()){        //if Prime Number doesnt exist in z_2 map
            total *= prim_zahl_1[keys_1[n]];
        }else if(prim_zahl_2[keys_1[n]] > prim_zahl_1[keys_1[n]]){     //if it does exist and value in map 2 is greater
            total *= prim_zahl_2[keys_1[n]];
        }else{                                                      //if it exist and value in map 1 ist greater
            total *= prim_zahl_1[keys_1[n]];
        }
    }

    //obtaining the result from key 2
    for(int n = 0; n < keys_2.size(); n++){
        if(prim_zahl_1.find(keys_2[n]) == prim_zahl_1.end()){        //if Prime Number doesnt exist in z_1 map
            total *= prim_zahl_2[keys_2[n]];
        }
    }

    return total;

}

int main() {
    int a = 0;
    int b = 0;

    //You notice the relationship a*b = kgV(a,b) * ggT(a,b)
    for(a = 30; a <= 40; a++){
        for(b = 30; b <= 40; b++){
            std::cout << "a: " << a << " , " << "b: " << b << std::endl;
            std::cout << ggT(a,b) << std::endl;
            std::cout << kgV(a,b) << std::endl;
            std::cout << a * b << std::endl;
        }
    }

    return 0;
}
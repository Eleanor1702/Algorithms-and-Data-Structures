#include "AVL_Tree.h"

int main() {

    AVL_Tree* tree1 = new AVL_Tree();

    int arr[] = {19, 6, 8 ,10};

    for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
        tree1->insert(arr[i]);
    }

    tree1->print();

    return 0;
}
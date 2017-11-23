#include "Tree.h"

int main() {

    int num = 0;

    Tree* tree1 = new Tree();

    tree1->insert(40);
    tree1->insert(30);
    tree1->insert(20);
    tree1->insert(10);
    tree1->insert(60);
    tree1->insert(50);
    tree1->insert(70);

    tree1->print();

    tree1->deleteValueIterative(10);
    tree1->deleteValueIterative(40);

    tree1->print();

    //delete tree1;

    return 0;
}
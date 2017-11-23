#include "Tree.h"

int main() {

    int num = 0;

    Tree* tree1 = new Tree();

    tree1->insert(5);
    tree1->insert(2);
    tree1->insert(6);
    tree1->insert(1);

    tree1->print();

    tree1->contains(3);
    tree1->contains(1);

    tree1->deleteValue(2);
    tree1->deleteValue(5);

    tree1->print();

    delete tree1;

    return 0;
}
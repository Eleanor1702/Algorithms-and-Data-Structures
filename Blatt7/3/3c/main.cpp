#include "AVL_Tree.h"

int main() {

    AVL_Tree* tree1 = new AVL_Tree();

    tree1->insert(18);
    tree1->insert(12);
    tree1->insert(27);
    tree1->insert(7);
    tree1->insert(15);
    tree1->insert(23);
    tree1->insert(34);

    tree1->print();

    tree1->erase(7);

    tree1->print();

    tree1->erase(12);

    tree1->print();

    tree1->erase(15);

    tree1->print();

    return 0;
}
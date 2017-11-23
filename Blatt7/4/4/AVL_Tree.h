#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "Element.h"

class AVL_Tree {
public:
    AVL_Tree();
    void insert(int number);
    void print();

private:
    Element* root = nullptr;
    int max(int a, int b);
    int getHeight(Element* elem);
    void updateHeight(Element* elem);
    void insert(Element** elem, int value);

    //Rotations
    void checkRotationRight(Element** elem);
    void checkRotationLeft(Element** elem);
    void rotateLeft(Element** a);
    void doubleRotationLeft(Element* a);
    void rotateRight(Element** a);
    void doubleRotationRight(Element* a);
    void print(Element* curr);
};


#endif
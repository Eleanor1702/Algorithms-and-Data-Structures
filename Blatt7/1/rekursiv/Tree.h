#ifndef TREE_H
#define TREE_H

#include "Element.h"

class Tree {
public:
    Tree();
    ~Tree();
    void insert(int number);
    bool contains(int number);
    Element* deleteValue(int number);
    void print();

private:
    Element* root = nullptr;
    void insert(Element* root,Element* obj);
    void deleteTree(Element * root);
    void print(Element* root);
    Element* getNextValue(Element* elem);
    Element* deleteValueRecursive(Element* elem, int value);
};


#endif
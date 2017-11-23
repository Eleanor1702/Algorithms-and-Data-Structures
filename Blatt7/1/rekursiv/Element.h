#ifndef ELEMENT_H
#define ELEMENT_H


class Element {
public:
    Element(int value);

private:
    int value = 0;
    Element* left = nullptr;
    Element* right = nullptr;

    friend class Tree;
};


#endif
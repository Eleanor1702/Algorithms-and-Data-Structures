#include "Tree.h"
#include <iostream>

Tree::Tree(){
    this->root = nullptr;
}

Tree::~Tree(){
    deleteTree(this->root);         //recursive Methode
    this->root = nullptr;
}

void Tree::deleteTree(Element *root) {
    if(this->root != nullptr){
        if(this->root->left != nullptr){
            deleteTree(this->root->left);
        }else if(this->root->right != nullptr){
            deleteTree(this->root->right);
        }

        delete this->root;
    }
}

bool Tree::contains(int number) {          //rekursiv Methode
    Element* curr = this->root;

    while(curr != nullptr){
        if(curr->value == number){
            return true;
        }else{
            if(number <= curr->value){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
    }
    return false;
}

void Tree::insert(int number){
    Element* elem = new Element(number);

    if(this->root == nullptr){
        this->root = elem;
    }else{
        insert(this->root,elem);   //Call the recursive Methode
    }
}

void Tree::insert(Element *currRoot, Element *elem) {
    if(elem->value <= currRoot->value){
        if(currRoot->left == nullptr){
            currRoot->left = elem;
        }else{
            insert(currRoot->left, elem);
        }
    }else{
        if(currRoot->right == nullptr){
            currRoot->right = elem;
        }else{
            insert(currRoot->right, elem);
        }
    }
}

void Tree::print(){
    print(this->root);          //call the recursive Methode
    std::cout << std::endl;
}

void Tree::print(Element* root){
    if(root != nullptr){
        std::cout << "(";
        print(root->left);                          //left recursive
        std::cout << "," << root->value << ",";     //print out root
        print(root->right);                         //right recursive
        std::cout << ")";
    }else{
        std::cout << "n";
    }
}

//get smallest value...
Element* Tree::getNextValue(Element *elem) {
    Element* current = elem;

    /* loop down to find the leftmost leaf */
    while (current->left != nullptr)
        current = current->left;

    return current;
}


Element* Tree::deleteValue(int number) {
    if (root == nullptr) {
        return root;
    } else {
        return deleteValueRecursive(root, number);
    }
}
//rekursiv deleteValue Methode...
Element* Tree::deleteValueRecursive(Element *elem, int value) {
    if(value < elem->value){
        //Element is in left Subtree
        elem->left = deleteValueRecursive(elem->left, value);
    }else if(value > elem->value){
        //Element is in right Subtree
        elem->right = deleteValueRecursive(elem->right, value);
    }else{
        //curr ist Element wished to be deleted

        //Element with one or no child
        if(elem->left == nullptr){
            Element* tmp = elem->right;
            delete elem;
            return tmp;
        }else if(elem->right == nullptr){
            Element* tmp = elem->left;
            delete elem;
            return tmp;
        }

        //Element with two children
        Element* tmp = getNextValue(elem->right);

        elem->value = tmp->value;

        elem->right = deleteValueRecursive(elem->right, tmp->value);

    }
    return elem;
}
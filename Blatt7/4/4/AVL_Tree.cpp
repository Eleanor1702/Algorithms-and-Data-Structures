#include "AVL_Tree.h"
#include <iostream>
#include <vector>

AVL_Tree::AVL_Tree(){
    this->root = nullptr;
}

int AVL_Tree::max(int a, int b) {
    if(a < b){
        return b;
    }else{
        return a;
    }
}

int AVL_Tree::getHeight(Element *elem) {
    if(elem == nullptr){
        return -1;
    }else{
        return elem->height;
    }
}

void AVL_Tree::updateHeight(Element* elem) {
    elem->height = 1 + max(getHeight(elem->left), getHeight(elem->right));
}

void AVL_Tree::rotateLeft(Element** a) {
    Element* b = (*a)->right;

    (*a)->right = b->left;
    b->left = &(**a);
    if(*a == this->root){
        this->root = b;
        updateHeight(this->root->left);
        updateHeight(this->root);
    }else{
        a = &b;
        updateHeight((*a)->left);
        updateHeight(*a);
    }
}

void AVL_Tree::rotateRight(Element** a) {
    Element* b = (*a)->left;

    (*a)->left = b->right;
    b->right = *a;
    *a = b;

    updateHeight((*a)->right);
    updateHeight(*a);
}

void AVL_Tree::doubleRotationLeft(Element* a) {
    rotateRight(&a->right);
    rotateLeft(&a);
}

void AVL_Tree::doubleRotationRight(Element* a) {
    rotateLeft(&a->left);
    rotateRight(&a);
}

void AVL_Tree::checkRotationLeft(Element** elem) {
    if(*elem != nullptr){
        if( (*elem)->right != nullptr ){
            if( getHeight( (*elem)->right ) - getHeight( (*elem)->left) == 2 ){
                if( getHeight( (*elem)->right->left ) > getHeight( (*elem)->right->right ) ){       //inner Subtree und outside Subtree
                    doubleRotationLeft(*elem);
                }else{
                    rotateLeft(elem);
                }
            }else{
                updateHeight(*elem);         //update to root
            }
        }else{
            updateHeight(*elem);             //update to root
        }
    }
}

void AVL_Tree::checkRotationRight(Element** elem) {
    if(*elem != nullptr){
        if((*elem)->left != nullptr){
            if(getHeight((*elem)->left)-getHeight((*elem)->right) == 2){
                if(getHeight((*elem)->left->right) > getHeight((*elem)->left->right)){       //inner Subtree und outside Subtree
                    doubleRotationRight(*elem);
                }else {
                    rotateRight(elem);
                }
            }else{
                updateHeight(*elem);         //update to root
            }
        }else{
            updateHeight(*elem);             //update to root
        }
    }
}

void AVL_Tree::insert(int number) {
    insert(&this->root, number);
}

void AVL_Tree::insert(Element** elem, int value) {
    if(*elem == nullptr){            //Basic case
        *elem = new Element(value);
    }else{                          //Position not found recursive
        if(value <= (*elem)->value){
            insert( &(*elem)->left, value );
            checkRotationRight(&(*elem));
        }else{
            insert( &(*elem)->right, value );
            checkRotationLeft(&(*elem));
        }
    }
}

void AVL_Tree::print(){
    print(this->root);          //call the recursive Methode
    std::cout << std::endl;
}

void AVL_Tree::print(Element* root){
    if(root != nullptr){
        print(root->left);                          //left recursive
        std::cout << root->value << " ";     //print out root
        print(root->right);                         //right recursive
    }
}
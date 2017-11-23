#include "Tree.h"
#include <iostream>
#include <vector>

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
    }else if(elem->value > currRoot->value){
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

//iterative deleteValue Methode...
void Tree::deleteValueIterative(int value) {
    Element* curr = this->root;
    std::vector <Element*> vorRoot;

    while(curr != nullptr){
        //code comes here
        if(value < curr->value){
            //Element is in left Subtree
            vorRoot.push_back(curr);
            curr = curr->left;
        }else if(value > curr->value){
            //Element is in right Subtree
            vorRoot.push_back(curr);
            curr = curr->right;
        }else{
            //curr ist Element wished to be deleted

            //Element with one child
            Element* tmp = curr;
            if(curr->right == nullptr && curr->left != nullptr){
                tmp = curr->left;
                curr->value = tmp->value;
                curr->left = tmp->left;
                break;
            }else if(curr->left == nullptr && curr->right != nullptr){
                tmp = curr->right;
                curr->value = tmp->value;
                curr->right = tmp->right;
                break;
            }else if(curr->left == nullptr && curr->right == nullptr){          //Element with no child
                //Where is our curr connected to the pre Element
                int test = vorRoot.size();
                if(curr = vorRoot[vorRoot.size()-1]->left){
                    vorRoot[vorRoot.size()-1]->left = nullptr;
                }else{
                    vorRoot[vorRoot.size()-1]->right = nullptr;
                }
                delete curr;
                break;
            }

            //Element with two children
            tmp = curr->right;
            curr->value = tmp->value;
            curr->right = tmp->right;
            delete tmp;
            break;
        }
    }
}
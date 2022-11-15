#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <stack>

typedef unsigned int uint;
using namespace std;

template<typename V, typename K>
struct Node {

    T value;
    int key;
    Node* left;
    Node* right;
    Node(T value, int key) {
        this->value = value;
        this->key = key;
    }
};

template<typename V, typename K>
class BSTree {
    public:
        BSTree() {}
        BSTree(const BSTree& copy);
        ~BSTree(){}
        uint getSize();
        bool clear();
        bool isEmpty();
        T get(int key);
        bool set(T value, int key);
        T insert(T value, int key);
        bool remove(int key);
        string printKeys();
        void printTree();
        void makeUpTree();
    
    private:
        uint size;
        Node<T>* root;
>>>>>>> badblues
};
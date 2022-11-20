#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <stack>


typedef unsigned int uint;
using namespace std;

template <typename K, typename V>
struct Node {
    V value;
    K key;
    Node* left;
    Node* right;
    Node(K key, V value) {
        this->value = value;
        this->key = key;
        left = NULL;
        right = NULL;
    }
};

template <typename K, typename V>
class BSTree {
    public:
        BSTree();
        BSTree(const BSTree& copy);
        ~BSTree();
        //Iterator begin();
        //RIterator rbegin();
        //Iterator end();
        //RIterator rend();
        uint getSize();
        bool clear();
        bool isEmpty();
        V get(K key);
        bool set(K key, V value);
        bool insert(K key, V value);
        bool remove(K key);
        string printKeys();
        void printTree();
        void printPreorder(Node<K,V>* node);
        int getLookedElemCount();

    private:
        uint size;
        int l_elem_c = 0;
        Node<K, V>* root;
};
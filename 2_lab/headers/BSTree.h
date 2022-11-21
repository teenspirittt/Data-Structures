#pragma once
#include "Node.h"
#include "Iterator.h"
#include "RIterator.h"
#include <string>




template <typename K, typename V>
class BSTree {
    public:
        BSTree();
        BSTree(const BSTree& copy);
        ~BSTree();
        Iterator<K, V> begin();
        RIterator<K, V> rbegin();
        Iterator<K, V> end();
        RIterator<K, V> rend();
        uint getSize();
        void clear();
        bool isEmpty();
        V get(K key);
        bool set(K key, V value);
        bool insert(K key, V value);
        bool remove(K key);
        string printKeys();
        void printTree();
        void printTree(Node<K, V> *tree, int depth, char *path, int right);
        int getLookedElemCount();
        
    private:
        uint size;
        int l_elem_c = 0;
        Node<K, V>* root;
};
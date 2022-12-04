#pragma once
#include "Node.h"
#include <vector>
#include <stack>


template <typename K, typename V>
class Iterator {
    public:

        Iterator() {
            size = 0;
            index = -1;
            root = nullptr;
        }

        Iterator (Internal<K, V>* root, int index, uint size) {
            this->size = size;
            this->root = root;
            this->index = index;
            if (root)
                fill(root);
        }

        Iterator& operator++() {
             index++;
             if (index == size)
                index = -1;
             return *this;
        }
        
        Iterator& operator--() {
            index--;
            return *this;
        }

        bool operator==(const Iterator& iterator) {
            return this->index == iterator.index;
        }

        bool operator!=(const Iterator& iterator) {
            return this->index != iterator.index;
        }

        Node<K, V>* operator*() {
            return vc[index];
        }



    private:

        // void fill(Internal<K,V>* node) {
        //     if (!node)
        //         return;
            
        //     if N is a leaf
        //         visit (e.g. print) the key(s) stored in N
        //     else if N is a 2-node
        //         traverse(N.left)
        //         visit key
        //         traverse(N.right)
        //     else N is a 3-node
        //         traverse(N.left)
        //         visit small key
        //         traverse(N.middle)
        //         visit large key
        //         traverse(N.right)
        // }

        uint size;
        int index;
        vector<Leaf<K, V>*> vc;
        Internal<K, V>* root;
};
#pragma once
#include "Node.h"
#include <vector>


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

        Leaf<K, V>* operator*() {
            return vc[index];
        }

    protected:

        void fill(Node<K,V>* node) {
            if (!node)
                return;
            if (!(node->inner())) {
                vc.push_back(((Leaf<K, V>*)node));
            } else {
                fill(((Internal<K,V>*)node)->son1);
                fill(((Internal<K,V>*)node)->son2);
                if (((Internal<K,V>*)node)->son3)
                    fill(((Internal<K,V>*)node)->son3);
            }
        }

        uint size;
        int index;
        vector<Leaf<K, V>*> vc;
        Internal<K, V>* root;
};

template<typename K, typename V>
class RIterator {
    public:

        RIterator() {
            size = 0;
            index = -1;
            root = nullptr;
        }

        RIterator (Internal<K, V>* root, int index, uint size) {
            this->size = size;
            this->root = root;
            this->index = index;
            fill(root);
        }

        RIterator& operator++() {
             index--;
             return *this;
        }
        
        RIterator& operator--() {
            index++;
            if (index == size) index = -1;
            return *this;
        }


        bool operator==(const RIterator& iterator) {
            return this->index == iterator.index;
        }

        bool operator!=(const RIterator& iterator) {
            return this->index != iterator.index;
        }

        Leaf<K, V>* operator*() {
            return vc[index];
        }

    protected:

        void fill(Node<K,V>* node) {
            if (!node)
                return;
            if (!(node->inner())) {
                vc.push_back(((Leaf<K, V>*)node));
            } else {
                fill(((Internal<K,V>*)node)->son1);
                fill(((Internal<K,V>*)node)->son2);
                if (((Internal<K,V>*)node)->son3)
                    fill(((Internal<K,V>*)node)->son3);
            }
        }

        uint size;
        int index;
        vector<Leaf<K, V>*> vc;
        Internal<K, V>* root;
};
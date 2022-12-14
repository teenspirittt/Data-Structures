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

        Iterator (Node<K, V>* root, int index, uint size) {
            this->size = size;
            this->root = root;
            this->index = index;
            if (root)
                fill();
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

        void fill() {
            Node<K, V> *tmp = root;
            stack<Node<K, V> *> st;
            while (!st.empty() || tmp) {
                if (tmp) {
                st.push(tmp);
                tmp = tmp->left;
                } else {
                tmp = st.top();
                st.pop();
                vc.push_back(tmp);
                tmp = tmp->right;
                }
            }
        }
        uint size;
        int index;
        vector<Node<K, V> *> vc;
        Node<K, V>* root;
};
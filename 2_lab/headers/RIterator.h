#include "Node.h"
#include <vector>
#include <stack>

using namespace std;

template<typename K, typename V>
class RIterator {
    public:

        RIterator() {
            index = -1;
            root = nullptr;
        }

        RIterator (Node<K, V>* root, int index) {
            this->root = root;
            this->index = index;
            if (root)
                fill();
        }

        RIterator& operator++() {
             index--;
             return *this;
        }
        
        RIterator& operator--() {
            index++;
            return *this;
        }

        bool operator==(const RIterator& iterator) {
            return this->index == iterator.index;
        }

        bool operator!=(const RIterator& iterator) {
            return this->index != iterator.index;
        }

        Node<K,V>* operator*() {
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
        int index;
        vector<Node<K, V> *> vc;
        Node<K, V>* root;
};
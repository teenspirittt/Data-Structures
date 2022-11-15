#include "BSTree.h"


template<typename K, typename V>
class Iterator {
    public:
        Iterator () {currNode = NULL;}

        Iterator& operator++() {
             
        }
        
        Iterator& operator--() {

        }

        bool operator==(const Iterator& iterator) {
            return this->currNode == iterator.currNode;
        }

        bool operator!=(const Iterator& iterator) {
            return this->currNode != iterator.currNode;
        }

        V operator*() {
            return currNode->value;
        }
    private:
        Node<K, V>* currNode;
};
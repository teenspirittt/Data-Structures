#include "../headers/BSTree.h"

template<typename>

template<typename V, typename K>
bool BSTree<V, K>::isEmpty() {
  return size == 0;
}

template<typename V, typename K>
uint BSTree<V, K>::getSize() {
  return 0;
}

template<typename V, typename K>
BSTree<V, K::BSTree() {
root = 0;
size++;
}

template<typename V, typename K>
BSTree<V, K>::~BSTree() {

}

template<typename V, typename K>
bool BSTree<V, K>::insert(V value, K key) {
  Node<V, K> *tmp = nullptr;

  if (isEmpty()) {
    root = new Node(value);
    return true;
  }
  tmp = root;
  while (tmp) {
    if (value > tmp.value) {
      if (tmp.right) {
        tmp = tmp.right;
      } else {
        tmp.right = new Node(value);
        return true;
      }
    } else if (value < tmp.value) {
      if (tmp.left) {
        tmp = tmp.left;
      } else {
        tmp.left = new Node(value);
        return true;
      }
    }
  }

  return false;
}




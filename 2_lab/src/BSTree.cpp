#include "../headers/BSTree.h"

template<typename K, typename V>
bool BSTree<K, V>::isEmpty() {
  return size == 0;
}

template<typename K, typename V>
uint BSTree<K, V>::getSize() {
  return 0;
}

template<typename K, typename V>
BSTree<K, V>::BSTree() {
root = 0;
size++;
}

template<typename K, typename V>
BSTree<K, V>::~BSTree() {

}

template<typename K, typename V>
bool BSTree<K, V>::insert(V value, K key) {
  Node<K, V> *tmp = nullptr;

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


template<typename K, typename V>
bool BSTree<K, V>::isEmpty() {
  return size == 0;
}

template<typename K, typename V>
uint BSTree<K, V>::getSize() {
  return size;
}

template<typename K, typename V>
string BSTree<K, V>::printKeys() {
  stringstream *sstr = new stringstream;
  Node<K, V>* tmp = root;
  stack<Node<K, V>*> st;
  st.push(tmp);
  while(!st.empty()) {
    tmp = st.top();
    st.pop();
    if (tmp->left != NULL)
      st.push(tmp->left);
    *sstr << " " << tmp->key;
    if (tmp->right != NULL)
      st.push(tmp->right);
  }
  return sstr->str();
}

template<typename K, typename V>
T BSTree<K, V>::get(int key) {
  Node<K, V>* tmp = root;
  while(tmp != NULL && tmp->key != key) {
    if (key < tmp->key)
      tmp = tmp->left;
    else
      tmp = tmp->right;
  }
  if (tmp == NULL)
    return NULL;
  return tmp->value;
}

template<typename K, typename V>
bool BSTree<K, V>::set(T value, int key) {
  Node<K, V>* tmp = root;
  while(tmp != NULL && tmp->key != key) {
    if (key < tmp->key)
      tmp = tmp->left;
    else
      tmp = tmp->right;
  }
  if (tmp == NULL)
    return false;
  tmp->value = value;
  return true;
}



template<typename K, typename V>
bool BSTree<T>::clear() {
  Node<T>* tmp = root;
  stack<Node<T>*> st;
  st.push(tmp);
  while(!st.empty()) {
    tmp = st.top();
    st.pop();
    if (tmp->left != NULL)
      st.push(tmp->left);
    if (tmp->right != NULL)
      st.push(tmp->right);
    delete tmp;
  }
  return true;
}

template 
class BSTree<int>;

template
class BSTree<double>;

template
class BSTree<char>;

template
class BSTree<unsigned int>;

template
class BSTree<long>;

template
class BSTree<long long>;

template
class BSTree<short>;

template
class BSTree<string>;
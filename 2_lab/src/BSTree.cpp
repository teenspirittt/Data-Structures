#include "../headers/BSTree.h"


template <typename>


template<typename T>
bool BSTree<T>::isEmpty() {
  return size == 0;
}

template<typename T>
uint BSTree<T>::getSize() {
  return size;
}

template<typename T>
string BSTree<T>::printKeys() {
  stringstream *sstr = new stringstream;
  Node<T>* tmp = root;
  stack<Node<T>*> st;
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

template<typename T>
T BSTree<T>::get(int key) {
  Node<T>* tmp = root;
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

template<typename T>
bool BSTree<T>::set(T value, int key) {
  Node<T>* tmp = root;
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



template<typename T>
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
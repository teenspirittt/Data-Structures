#include "../headers/BSTree.h"
#include <iostream>
#include <stack>
#include <sstream>

template<typename K, typename V>
BSTree<K, V>::BSTree() {
  root = NULL;
  size = 0;
}

template<typename K, typename V>
BSTree<K, V>::~BSTree() {
  clear();
}

template<typename K, typename V>
bool BSTree<K, V>::insert(K key, V value) {
  nodes_counter = 0;
  if (isEmpty()) {
    root = new Node<K, V>(key, value);
    size++;
    return true;
  }
  Node<K, V> *tmp = root;
  while (tmp) {
    nodes_counter++;
    if (key > tmp->key) {
      if (tmp->right) {
        tmp = tmp->right;
      } else {
        tmp->right = new Node<K, V>(key, value);
        size++;
        return true;
      }
    } else if (key < tmp->key) {
      if (tmp->left) {
        tmp = tmp->left;
      } else {
        tmp->left = new Node<K, V>(key, value);

        size++;
        return true;
      }
    } else {
      return false;
    }
  }
  return false;
}

template<typename K, typename V>
bool BSTree<K, V>::remove(K key) {
  Node<K, V> *curr = root;
  Node<K, V> *prev = nullptr;
  // check if the key is actually present int tree
  while (curr != nullptr && curr->key != key) {
    prev = curr;
    if (key < curr->key)
      curr = curr->left;
    else
      curr = curr->right;
  }
  if (curr == nullptr)
    return false;

  // check if the removing node  has one child
  if (curr->left == nullptr || curr->right == nullptr) {
    Node<K, V> *newCurr;
    if (curr->left == nullptr)
      newCurr = curr->right;
    else
      newCurr = curr->left;
    // check is the removing node is root
    if (prev == nullptr) {
      root = newCurr;
      size--;
      return true;
    }
    // check is the removing node is prevs left or right child
    if (curr == prev->left)
      prev->left = newCurr;
    else
      prev->right = newCurr;
    size--;
    free(curr);
    return true;
  } else {
    Node<K, V> *p = nullptr;
    Node<K, V> *tmp;

    tmp = curr->right;
    while (tmp->left != nullptr) {
      p = tmp;
      tmp = tmp->left;
    }

    if (p != nullptr)
      p->left = tmp->right;
    else
      curr->right = tmp->right;
    curr->key = tmp->key;
    curr->value = tmp->value;
    size--;
    free(tmp);
  }
  return true;
}

template<typename K, typename V>
bool BSTree<K, V>::isEmpty() {
  nodes_counter = 0;
  return size == 0;
}

template<typename K, typename V>
uint BSTree<K, V>::getSize() {
  nodes_counter = 0;
  return size;
}

template<typename K, typename V>
string BSTree<K, V>::printKeys() {
  nodes_counter = 0;
  if (!root)
    return "";
  stringstream *sstr = new stringstream;
  Node<K, V> *tmp = root;
  stack<Node<K, V> *> st;
  while (!st.empty() || tmp) {
    if (tmp) {
      st.push(tmp);
      tmp = tmp->left;
    } else {
      tmp = st.top();
      st.pop();
      *sstr << " " << tmp->key;
      tmp = tmp->right;
    }
    nodes_counter++;
  }
  return sstr->str();
}

template<typename K, typename V>
V BSTree<K, V>::get(K key) {
  nodes_counter = 0;
  Node<K, V> *tmp = root;
  while (tmp != NULL && tmp->key != key) {
    if (key < tmp->key)
      tmp = tmp->left;
    else
      tmp = tmp->right;
    nodes_counter++;
  }
  if (tmp == NULL)
    return (V) 0;
  return tmp->value;
}

template<typename K, typename V>
bool BSTree<K, V>::set(K key, V value) {
  nodes_counter = 0;
  Node<K, V> *tmp = root;
  while (tmp != NULL && tmp->key != key) {
    if (key < tmp->key)
      tmp = tmp->left;
    else
      tmp = tmp->right;
    nodes_counter++;
  }
  if (tmp == NULL)
    return false;
  tmp->value = value;
  return true;
}

template<typename K, typename V>
void BSTree<K, V>::clear() {
  nodes_counter = 0;
  Node<K, V> *lnp = NULL;
  Node<K, V> *peekn = NULL;
  Node<K, V> *tmp = root;
  stack<Node<K, V> *> st;
  while (!st.empty() || tmp) {
    if (tmp) {
      st.push(tmp);
      tmp = tmp->left;
    } else {
      peekn = st.top();
      if (peekn->right && lnp != peekn->right) {
        tmp = peekn->right;
      } else {
        st.pop();
        lnp = peekn;
        delete (peekn);
      }
    }
    nodes_counter++;
  }
  root = NULL;
  size = 0;
}

template<typename K, typename V>
void BSTree<K, V>::printTree(Node<K, V> *tree, int depth, char *path, int right) {
  // stopping condition
  if (!tree)
    return;

  // increase spacing
  depth++;

  // start with right node
  printTree(tree->right, depth, path, 1);

  if (depth > 1) {
    // set | draw map
    path[depth - 2] = 0;

    if (right)
      path[depth - 2] = 1;
  }

  if (tree->left)
    path[depth - 1] = 1;

  // print root after spacing
  printf("\n");

  for (int i = 0; i < depth - 1; i++) {
    if (i == depth - 2)
      printf("+");
    else if (path[i])
      printf("|");
    else
      printf(" ");

    for (int j = 1; j < 3; j++)
      if (i < depth - 2)
        printf(" ");
      else
        printf("-");
  }

  printf("%ld\n", tree->value);

  // vertical spacers below
  for (int i = 0; i < depth; i++) {
    if (path[i])
      printf("|");
    else
      printf(" ");

    for (int j = 1; j < 3; j++)
      printf(" ");
  }

  // go to left node
  printTree(tree->left, depth, path, 0);
}

template<typename K, typename V>
void BSTree<K, V>::printTree() {
  // should check if we don't exceed this somehow..
  char path[255] = {};

  //initial depth is 0
  printTree(this->root, 0, path, 0);
}
template<typename K, typename V>
Iterator<K, V> BSTree<K, V>::begin() {
  return Iterator<K, V>(root, 0);
}

template<typename K, typename V>
RIterator<K, V> BSTree<K, V>::rbegin() {
  return RIterator<K, V>(root, size - 1);
}

template<typename K, typename V>
Iterator<K, V> BSTree<K, V>::end() {
  return Iterator<K, V>(root, size - 1);
}

template<typename K, typename V>
RIterator<K, V> BSTree<K, V>::rend() {
  return RIterator<K, V>(root, 0);
}

template<typename K, typename V>
int BSTree<K, V>::CountNodes() {
  return nodes_counter;

}

template
class BSTree<int, int>;

template
class BSTree<int, double>;

template
class BSTree<int, char>;

template
class BSTree<int, unsigned int>;

template
class BSTree<int, long>;

template
class BSTree<int, long long>;

template
class BSTree<int, short>;

template
class BSTree<int, string>;

template
class BSTree<unsigned long long, int>;
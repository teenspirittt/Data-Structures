#include "../headers/BSTree.h"
template<typename K, typename V>
BSTree<K, V>::BSTree() {
  root = NULL;
  size = 0;
}

template<typename K, typename V>
BSTree<K, V>::~BSTree() {

}

template<typename K, typename V>
bool BSTree<K, V>::insert(K key, V value) {
  cout << "inserting\n";
  if (isEmpty()) {
    root = new Node<K, V>(key, value);
    size++;
    return true;
  }
  Node<K, V> *tmp = root;
  while (tmp) {
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
  }
  return sstr->str();
}

template<typename K, typename V>
V BSTree<K, V>::get(K key) {
  Node<K, V> *tmp = root;
  while (tmp != NULL && tmp->key != key) {
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
bool BSTree<K, V>::set(K key, V value) {
  Node<K, V> *tmp = root;
  while (tmp != NULL && tmp->key != key) {
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
bool BSTree<K, V>::clear() {
  Node<K, V> *tmp = root;
  stack<Node<K, V> *> st;
  st.push(tmp);
  while (!st.empty()) {
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

template<typename K, typename V>
void BSTree<K, V>::printTree(Node<K, V> *tree, int depth, char *path, int right) {
    // stopping condition
    if (!tree)
        return;

    // increase spacing
    depth++;

    // start with right node
    printTree(tree->right, depth, path, 1);

    if(depth > 1)
    {
        // set | draw map
        path[depth-2] = 0;

        if(right)
            path[depth-2] = 1;
    }

    if(tree->left)
        path[depth-1] = 1;

    // print root after spacing
    printf("\n");

    for(int i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<space; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }

    printf("%d\n", tree->value);

    // vertical spacers below
    for(int i=0; i<depth; i++)
    {
      if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<space; j++)
          printf(" ");
    }

    // go to left node
    printTree(tree->left, depth, path, 0);
}

template<typename K, typename V>
void BSTree<K, V>::printTree()
{
    // should check if we don't exceed this somehow..
    char path[255] = {};

    //initial depth is 0
    printTree(this->root, 0, path, 0);
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
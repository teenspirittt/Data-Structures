#include "../headers/BSTree.h"

template<typename K, typename V>
BSTree<K, V>::BSTree() {
  root = nullptr;
  size = 0;
}

template<typename K, typename V>
BSTree<K, V>::~BSTree() {
  clear();
}

/*template<typename K, typename V>
BSTree<K, V>::BSTree(const BSTree &copy) {
  root = nullptr;
  nodes_counter = 0;
  size = 0;
  auto nodeList = new list<Node<K, V> *>();
  Node<K, V> *top = copy.root;
  while (root != nullptr) {
    if (!nodeList->empty()) {
      top = nodeList->front();
      nodeList->pop_front();
    }
    while (top != nullptr) {
      insert(top->key, top->value);
      if (top->right != nullptr)
        nodeList->push_front(top->right);
      top = top->left;
    }
  }
}*/

template<typename K, typename V>
bool BSTree<K, V>::insert(K key, V value) {
  nodes_counter = 0;
  if (isEmpty()) {
    root = new Node<K, V>(key, value);
    size++;
    nodes_counter++;
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
  nodes_counter = 0;
  Node<K, V> *curr = root;
  Node<K, V> *prev = nullptr;
  // check if the key is actually present int tree
  while (curr != nullptr && curr->key != key) {
    prev = curr;
    if (key < curr->key)
      curr = curr->left;
    else
      curr = curr->right;
    nodes_counter++;
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
    if (curr == prev->left) {
      prev->left = newCurr;
      nodes_counter++;
    } else {
      prev->right = newCurr;
      nodes_counter++;
    }
    size--;
    free(curr);
    return true;
  } else {
    Node<K, V> *p = nullptr;
    Node<K, V> *tmp;

    tmp = curr->right;
    nodes_counter++;
    while (tmp->left != nullptr) {
      p = tmp;
      tmp = tmp->left;
      nodes_counter++;
    }

    if (p != nullptr) {
      p->left = tmp->right;
      nodes_counter++;
    } else {
      curr->right = tmp->right;
      nodes_counter++;
    }

    curr->key = tmp->key;
    curr->value = tmp->value;
    nodes_counter += 2;
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
  while (tmp != nullptr && tmp->key != key) {
    if (key < tmp->key)
      tmp = tmp->left;
    else
      tmp = tmp->right;
    nodes_counter++;
  }
  if (tmp == nullptr)
    return (V) 0;
  return tmp->value;
}

template<typename K, typename V>
bool BSTree<K, V>::set(K key, V value) {
  nodes_counter = 0;
  Node<K, V> *tmp = root;
  while (tmp != nullptr && tmp->key != key) {
    if (key < tmp->key)
      tmp = tmp->left;
    else
      tmp = tmp->right;
    nodes_counter++;
  }
  if (tmp == nullptr)
    return false;
  tmp->value = value;
  return true;
}

template<typename K, typename V>
void BSTree<K, V>::clear() {
  nodes_counter = 0;
  Node<K, V> *lnp = nullptr;
  Node<K, V> *peekn = nullptr;
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
  root = nullptr;
  size = 0;
}

template<typename K, typename V>
void BSTree<K, V>::printTree(Node<K, V> *_root, int space) {
  if (_root == nullptr) {
    return;
  }
  space += COUNT;
  printTree(_root->right, space);
  for (int i = COUNT; i < space; i++)
    cout << " ";
  cout << _root->key << " " << _root->value << "\n";
  printTree(_root->left, space);
}

template<typename K, typename V>
void BSTree<K, V>::printTree() {
  printTree(root, 0);
}

template<typename K, typename V>
Iterator<K, V> BSTree<K, V>::begin() {
  return Iterator<K, V>(root, 0, size);
}

template<typename K, typename V>
RIterator<K, V> BSTree<K, V>::rbegin() {
  return RIterator<K, V>(root, size - 1, size);
}

template<typename K, typename V>
Iterator<K, V> BSTree<K, V>::end() {
  return Iterator<K, V>(root, -1, size);
}

template<typename K, typename V>
RIterator<K, V> BSTree<K, V>::rend() {
  return RIterator<K, V>(root, -1, size);
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
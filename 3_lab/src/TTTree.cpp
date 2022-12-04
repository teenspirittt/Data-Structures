#include "TTTree.h"
#include "Node.h"

using namespace std;

template<typename K, typename V>
uint TTTree<K, V>::GetSize() {
  return size;
}

template<typename K, typename V>
bool TTTree<K, V>::IsEmpty() {
  return size == 0;
}

template<typename K, typename V>
V TTTree<K, V>::Get(K key) {
  Leaf<K, V> *node = Get(root, key);
  if (node)
    return node->value;
  return V(0);
}

template<typename K, typename V>
bool TTTree<K, V>::Set(K key, V value) {
  Leaf<K, V> *node = Get(root, key);
  if (node) {
    node->value = value;
    return true;
  }
  return false;
}

template<typename K, typename V>
Leaf<K, V> *TTTree<K, V>::Get(Internal<K, V> *node, K key) {
  nodes_counter++;
  if (node == nullptr)
    return nullptr;
  //throw TreeException();
  if (node->son1->inner() == 0) {
    if (((Leaf<K, V> *) node->son1)->key == key)
      return ((Leaf<K, V> *) node->son1);
    if (node->son2)
      if (((Leaf<K, V> *) node->son2)->key == key)
        return ((Leaf<K, V> *) node->son2);
    if (node->son3)
      if (((Leaf<K, V> *) node->son3)->key == key)
        return ((Leaf<K, V> *) node->son3);
    return V(0);
    //throw TreeException();
  }
  if (node->key1 > key)
    return Get(((Internal<K, V> *) node->son1), key);
  if (node->key2 > key)
    return Get(((Internal<K, V> *) node->son2), key);
  return Get(((Internal<K, V> *) node->son3), key);
}

template<typename K, typename V>
void TTTree<K, V>::Clear() {
  Clear(root);
  delete root;
  root = nullptr;
  size = 0;
}

template<typename K, typename V>
void TTTree<K, V>::Clear(Internal<K, V> *node) {
  if (node == nullptr) return;
  if (node->son1->inner() == 0) {
    if (node->son1) delete node->son1;
    if (node->son2) delete node->son2;
    if (node->son3) delete node->son3;
    return;
  }
  Clear(((Internal<K, V> *) node->son1));
  delete node->son1;
  Clear(((Internal<K, V> *) node->son2));
  delete node->son2;
  if (node->son3) {
    Clear(((Internal<K, V> *) node->son3));
    delete node->son3;
  }
}

template<typename K, typename V>
int TTTree<K, V>::CountNodes() {
  return nodes_counter;
}

template<typename K, typename V>
TTTree<K, V>::TTTree() {
  root = nullptr;
  nodes_counter = 0;
  size = 0;
}

template<typename K, typename V>
TTTree<K, V>::TTTree(const TTTree &copy) {

}

template<typename K, typename V>
TTTree<K, V>::~TTTree() {
  Clear();
}

template<typename K, typename V>
bool TTTree<K, V>::Insert(K key, V value) {
  Node<K, V> *lt = new Leaf<K, V>(key, value);  //создали листок
  if (root == nullptr)      //если дерево пустое
  {
    root = new Internal<K, V>();   //создаем дерево
    root->son1 = lt;  //создали листок
    root->son2 = root->son3 = nullptr;
    size++; //увеличили счетчик размера дерева

    return true;
  }
  if (root->son2 == nullptr) {
    if (((Leaf<K, V> *) root->son1)->key < key) {
      root->son2 = lt;
      root->key1 = key;
      size++; //увеличили счетчик размера дерева
      return true;
    } else {
      if (((Leaf<K, V> *) root->son1)->key > key) {
        root->son2 = root->son1;
        root->key1 = ((Leaf<K, V> *) root->son1)->key;
        root->son1 = lt;
        size++; //увеличили счетчик размера дерева

        return true;
      } else {
        delete lt;
        return false;
      }
    }

  }
  Node<K, V> *tbk = new Internal<K, V>();
  K lbk;
  bool inserted = Insert(root, lt, tbk, lbk); //вызов функции рекурсивной вставки в дерево
  if (!inserted) {
    delete lt;
    return false;
  }
  if (tbk != nullptr) //если появилось новое поддерево (произошло расщепление)
  {
    Node<K, V> *temp;
    temp = root; //то формируем итоговое дерево,
    root = new Internal<K, V>;   //создаем дерево
    root->son1 = temp;    //1-ым сыном которого будет корень "старого" дерева,
    root->son2 = tbk;    //а 2-ым сыном будет "новое" поддерево
    root->key1 = lbk;
    root->son3 = nullptr;
  }
  return true;
}

template<class K, class V>
bool TTTree<K, V>::Insert(Node<K, V> *t, Node<K, V> *lt, Node<K, V> *&tup, K &lup) {  //функция рекурсивной вставки в дерево
  nodes_counter++;
  int child = 0;
  tup = nullptr;
  if (t->inner() == false) {
    if (((Leaf<K, V> *) t)->key == ((Leaf<K, V> *) lt)->key)
      return false;
    else {
      tup = lt;
      if ((((Leaf<K, V> *) t)->key) < (((Leaf<K, V> *) lt)->key)) lup = ((Leaf<K, V> *) lt)->key;
      else {
        lup = ((Leaf<K, V> *) t)->key;
        K temp1;
        V temp2;
        temp1 = ((Leaf<K, V> *) t)->key;
        ((Leaf<K, V> *) t)->key = ((Leaf<K, V> *) lt)->key;
        ((Leaf<K, V> *) lt)->key = temp1;
        temp2 = ((Leaf<K, V> *) t)->value;
        ((Leaf<K, V> *) t)->value = ((Leaf<K, V> *) lt)->value;
        ((Leaf<K, V> *) lt)->value = temp2;
      }
    }
    size++;
    return true;
  }
  Node<K, V> *w;
  if ((((Leaf<K, V> *) lt)->key) < (((Internal<K, V> *) t)->key1)) {
    child = 1;
    w = ((Internal<K, V> *) t)->son1;
  } else {
    if ((((Internal<K, V> *) t)->son3 == nullptr)
        || (((((Internal<K, V> *) t)->son3) != nullptr) & (((Leaf<K, V> *) lt)->key < ((Internal<K, V> *) t)->key2))) {
      child = 2;
      w = ((Internal<K, V> *) t)->son2;
    } else {
      child = 3;
      w = ((Internal<K, V> *) t)->son3;
    }
  }
  K lbk;
  Node<K, V> *tbk = new Internal<K, V>;
  bool inserted = Insert(w, lt, tbk, lbk);

  if (inserted) {
    if (tbk != nullptr) {
      if (((Internal<K, V> *) t)->son3 == nullptr) {
        if (child == 2) {
          ((Internal<K, V> *) t)->son3 = tbk;
          ((Internal<K, V> *) t)->key2 = lbk;
        } else {
          ((Internal<K, V> *) t)->son3 = ((Internal<K, V> *) t)->son2;
          ((Internal<K, V> *) t)->key2 = ((Internal<K, V> *) t)->key1;
          ((Internal<K, V> *) t)->son2 = tbk;
          ((Internal<K, V> *) t)->key1 = lbk;
        }
      } else {
        nodes_counter++;
        tup = new Internal<K, V>;
        if (child == 3) {
          ((Internal<K, V> *) tup)->son1 = ((Internal<K, V> *) t)->son3;
          ((Internal<K, V> *) tup)->son2 = tbk;
          ((Internal<K, V> *) tup)->son3 = nullptr;
          ((Internal<K, V> *) tup)->key1 = lbk;
          ((Internal<K, V> *) t)->son3 = nullptr;
          lup = ((Internal<K, V> *) t)->key2;
        } else {
          ((Internal<K, V> *) tup)->son2 = ((Internal<K, V> *) t)->son3;
          ((Internal<K, V> *) tup)->key1 = ((Internal<K, V> *) t)->key2;
          ((Internal<K, V> *) tup)->son3 = nullptr;
          if (child == 2) {
            ((Internal<K, V> *) tup)->son1 = tbk;
            lup = lbk;
          }
          if (child == 1) {
            ((Internal<K, V> *) tup)->son1 = ((Internal<K, V> *) t)->son2;
            ((Internal<K, V> *) t)->son2 = tbk;
            lup = ((Internal<K, V> *) t)->key1;
            ((Internal<K, V> *) t)->key1 = lbk;
          }
        }
        ((Internal<K, V> *) t)->son3 = nullptr;
      }
    }

  }
  return inserted;
}

template
class TTTree<int, int>;
#include "TTTree.h"

template<typename K, typename V>
uint TTTree<K, V>::getSize() {
  return size;
}
template<typename K, typename V>
void clear() {
  //TODO:
}

template<typename K, typename V>
bool TTTree<K, V>::isEmpty() {
  return size == 0;
}

template<typename K, typename V>
V TTTree<K, V>::Get(K key) {
  Node *node = Get(root, k);
  if (node)
    return node->value;
  return V(0);
}

template<typename K, typename V>
bool TTTree<K, V>::Set(K key, V value) {
  Node *node = Get(root, k);
  if (node) {
    node->value = value;
    return true;
  }
  return false;
}

template<typename K, typename V>
Node *TTTree<K, V>::Get(Internal *t, K k) {
  cnt++;
  if (t == NULL)
    return null;
  //throw TreeException();
  if (t->son1->type() == 0) {
    if (((Leaf *) t->son1)->key == k)
      return ((Leaf *) t->son1);
    if (t->son2)
      if (((Leaf *) t->son2)->key == k)
        return ((Leaf *) t->son2);
    if (t->son3)
      if (((Leaf *) t->son3)->key == k)
        return ((Leaf *) t->son3);
    return V(0);
    //throw TreeException();
  }
  if (t->key1 > k)
    return Get(((Internal *) t->son1), k);
  if (t->key2 > k)
    return Get(((Internal *) t->son2), k);
  return Get(((Internal *) t->son3), k);
}

template<typename K, typename V>
TTTree<K, V>::TTTree() {
  root = nullptr;
  nodes_counter = 0;
  size = 0;
}
f

template<typename K, typename V>
TTTree<K, V>::TTTree(const TTTree &copy) {

}
template<typename K, typename V>
TTTree<K, V>::~TTTree() {
  Clear();
}

template<typename K, typename V>
bool TTTree<K, V>::Insert(K key, V value) {
  nodes_counter = 0;
  if (IsEmpty()) {
    root = new Node<K, V>(key, value);
    size++;
    nodes_counter++;
    return true;
  }
  Node<K, V> *tmp = root;

  if (!tmp->inner()) {
    tmp->store(key);
  } else {
    if (*tmp->firstkey > *key) {
      insert(tmp->less, key); //Insert to left subtree.
    } else if (*tmp->firstkey <= *key && tmp->is2node()) {
      insert(tmp->btwn, key); //Insert to mid-subtree.
    } else {
      if (*tmp->secondkey > *key) {
        insert(tmp->btwn, key); //Insert to mid-subtree.
      } else {
        insert(tmp->great, key); //Insert to right subtree.
      }
    }
  }
  split(tmp);
  return false;
}

template<typename K, typename V>
void split(Node<K, V> *root) {
  if (root->size < 3) return root;

  auto *x = new Node<K, V>(root->key[0],
                           root->first,
                           root->second,
                           nullptr,
                           nullptr,
                           root->parent); // Создаем две новые вершины,
  auto *y = new Node<K, V>(root->key[2],
                           root->third,
                           root->fourth,
                           nullptr,
                           nullptr,
                           root->parent);  // которые имеют такого же родителя, как и разделяющийся элемент.
  if (x->first) x->first->parent = x;    // Правильно устанавливаем "родителя" "сыновей".
  if (x->second) x->second->parent = x;   // После разделения, "родителем" "сыновей" является "дедушка",
  if (y->first) y->first->parent = y;    // Поэтому нужно правильно установить указатели.
  if (y->second) y->second->parent = y;

  if (root->parent) {
    root->parent->insert_to_node(root->key[1]);

    if (root->parent->first == root) root->parent->first = nullptr;
    else if (root->parent->second == root) root->parent->second = nullptr;
    else if (root->parent->third == root) root->parent->third = nullptr;

    // Дальше происходит своеобразная сортировка ключей при разделении.
    if (root->parent->first == nullptr) {
      root->parent->fourth = root->parent->third;
      root->parent->third = root->parent->second;
      root->parent->second = y;
      root->parent->first = x;
    } else if (root->parent->second == nullptr) {
      root->parent->fourth = root->parent->third;
      root->parent->third = y;
      root->parent->second = x;
    } else {
      root->parent->fourth = y;
      root->parent->third = x;
    }

    Node<K, V> *tmp = root->parent;
    delete root;
    return tmp;
  } else {
    x->parent = root;   // Так как в эту ветку попадает только корень,
    y->parent = root;   // то мы "родителем" новых вершин делаем разделяющийся элемент.
    root->become_node2(root->key[1], x, y);
  }
}



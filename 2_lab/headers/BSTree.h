#pragma once

typedef unsigned int uint;

template<typename V, typename K>
struct Node {
  V value;
  int key;
  Node *left;
  Node *right;
  Node(V value) { this->value = value; }
};

template<typename V, typename K>
class BSTree {
 public:
  BSTree();
  BSTree(const BSTree &copy);
  ~BSTree();
  uint getSize();
  void clear();
  bool isEmpty();
  V get(int key);
  V set(int key);
  bool insert(V value, K key);
  bool remove(int key);
  void printKeys();
  void printTree();

 private:
  uint size;
  Node<V, K> *root{};
};
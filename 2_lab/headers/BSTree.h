#pragma once
#include "Node.h"
#include "Iterator.h"
#include "RIterator.h"
#include <string>
#include <iostream>
#include <stack>
#include <sstream>
#include <list>

#define COUNT 10

template<typename K, typename V>
class BSTree {
 public:
  BSTree();
  BSTree(const BSTree &copy);
  ~BSTree();
  Iterator<K, V> begin();
  RIterator<K, V> rbegin();
  Iterator<K, V> end();
  RIterator<K, V> rend();
  uint getSize();
  void clear();
  bool isEmpty();
  V get(K key);
  bool set(K key, V value);
  bool insert(K key, V value);
  bool remove(K key);
  string printKeys();
  void printTree();
  void printTree(Node <K, V> *_root, int space);
  int CountNodes();

 private:
  int nodes_counter = 0;
  uint size;
  Node<K, V> *root;
};
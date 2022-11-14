#pragma once

#include <iostream>
#include <sstream>

typedef unsigned int uint;

using namespace std;

template <typename T>
struct Node {
  T value;
  Node* next;
  Node(T value) { this->value = value; }
};

template <typename T>
class CycList {
 public:
  class Iterator {
   public:
    Iterator() {currNode = NULL; } 

    Iterator(CycList* list) { currNode = list->head; }

    Iterator& operator=(Node<T>* pNode) {
      this->currNode = pNode;
      return *this;
    }

    Iterator& operator++() {
      if (currNode) currNode = currNode->next;
      return *this;
    }

    Iterator operator++(int) {
      Iterator iterator = *this;
      ++*this;
      return iterator;
    }

    bool operator!=(const Iterator& iterator) {
      return this->currNode != iterator.currNode;
    }

    bool operator==(const Iterator& iterator) {
      return this->currNode == iterator.currNode;
    }

    T operator*() { return this->currNode->value; }

   private:
    Node<T>* currNode;
  };
  CycList();
  CycList(const CycList& copy);
  int getSize();
  void clear();
  bool isEmpty();
  bool isExistValue(T value);
  T getByIndex(int index);
  bool editValue(int index, T value);
  int getIndex(T value);
  void addValue(T value);
  bool insertValue(int index, T value);
  bool removeValue(T value);
  bool removeValueByIndex(int index);
  int getLookedElemCount();
  string toString();
  template<class V>
  friend istream &operator>>(istream &is, CycList<V> &list);
  template<class V>
  friend ostream &operator<<(ostream &os, CycList<V> &list);
  ~CycList() {
    while (size != 0) {
      Node<T>* tmp = head->next;
      delete head;
      head = tmp;
      size--;
    }
  }

 private:
  uint size{};
  Node<T>* head{};
  Node<T>* tail{};
  int l_elem_c = 0;
};

template<class V>
istream &operator>>(istream &is, CycList<V> &list) {
  V* obj = new V;
  is >> *obj;
  list.add(obj);
  delete obj;
  return is;
}

template<class V>
ostream &operator<<(ostream &os, CycList<V> &list) {
  os << list.toString();
  return os;
}



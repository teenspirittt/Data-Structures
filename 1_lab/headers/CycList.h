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
  // badblues
  class Iterator {
   public:
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

  // badblues
  CycList();
  // teenspirit
  CycList(const CycList& copy);
  // badblues
  int getSize();
  // teenspirit
  void clear();
  // badblues
  bool isEmpty();
  // teenspirit
  bool isExistValue(T value);
  // badblues
  T getByIndex(int index);
  // teenspirit
  void editValue(int index, T value);
  // badblues
  int getIndex(T value);
  // teenspirit
  void addValue(T value);
  // badblues
  bool insertValue(int index, T value);
  void show();
  // teenspirit
  bool removeValue(T value);
  // teenspirit
  bool removeValueByIndex(int index);
  // teenspirit
  int getLookedElemCount();
  // badblues
  string toString();
  template<class V>
  friend istream &operator>>(istream &is, CycList<V> &list);
  template<class V>
  friend ostream &operator<<(ostream &os, CycList<V> &list);
  //operator=(const CycList& copy);
  // teenspirit
  ~CycList() {
    while (size != 0) {
      Node<T>* tmp = head->next;
      delete head;
      head = tmp;
      size--;
    }
  }

 private:
  uint size;
  Node<T>* head;
  Node<T>* tail;
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
  os << list.toString() << "\n";
  return os;
}



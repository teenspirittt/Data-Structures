#ifndef _HEADERS_LIST_H_
#define _HEADERS_LIST_H_

#include <iostream>

typedef unsigned int uint;

using namespace std;

template <typename T>
struct Node {
  T value;
  Node *next;
  Node(T value) { this->value = value; }
};

template <typename T>
class CycList {
 public:
  // badblues
  class Iterator {
    public:
      Iterator(CycList* list) {
        currNode = list->head;
      }
      
      Iterator& operator=(Node<T>* pNode) {
        this->currNode = pNode;
        return *this;
      }

      Iterator& operator++() {
        if (currNode)
          currNode = currNode->next;
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

      T operator*() {
        return this->currNode->value;
      }

    private:
      Node<T>* currNode;
  };

  // badblues
  CycList();
  // teenspirit
  CycList(const CycList &copy);
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
  bool addValue(T value);
  // badblues
  bool insertValue(int index, T value);

  // teenspirit
  bool removeValue(T value);

  // teenspirit
  bool removeValue(int index, T values);

  // teenspirit
  int getLookedElemCount();
  // badblues
  string toString();
  // teenspirit
  ~CycList() {}

 private:
  uint size;
  Node<T>* head;

};

#endif  //_HEADERS_LIST_H_
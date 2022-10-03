#ifndef _HEADERS_LIST_H_
#define _HEADERS_LIST_H_

#include <iostream>

typedef unsigned int uint;

using namespace std;

template <typename T>
struct Node {
  T *value;
  Node *next;
  Node(T value) { this.value = value; }
};

template <typename T>
class CycList {
 public:
  // badblues
  class Iterator {
    T &operator*();
    Iterator &operator++();
    Iterator &operator--();
    bool operator==(const Iterator &);
    bool operator!=(const Iterator &);
  };

  friend class Iterator;
  iterator begin();
  iterator end();

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
  int getByIndex(int index);
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
  ~CycList();

 private:
  uint size;
  Node* head;

};

#endif  //_HEADERS_LIST_H_
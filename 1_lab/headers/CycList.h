#ifndef _HEADERS_LIST_H_
#define _HEADERS_LIST_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


using namespace std;

template <typename T>
struct Node
{
  T *field;
  Node *next;
};

template <typename T>
class CycList
{
public:

  //badblues
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


  //badblues
  CycList();
  //teenspirit
  CycList(const List &copy);
  //badblues
  int getSize();
  //teenspirit
  void clear();
  //badblues
  bool isEmpty();
  //teenspirit
  bool isExistValue(T value);
  //badblues
  int getByIndex(int index);
  //teenspirit
  void editValue(int index, T value);
  //badblues
  int getIndex(T value);
  //teenspirit
  bool addValue(T value);
  //badblues
  bool insertValue(int index, T value);
  //teenspirit
  bool removeValue(T value);
  //badblues
  bool removeValue(int index, T values);
  //teenspirit
  int getLookedElemCount();
  //badblues
  string toString();
  //teenspirit
  ~CycList();

private:

  unsigned int size;
  Node<T>* head;
};

#endif //_HEADERS_LIST_H_
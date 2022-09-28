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


  CycList();
  CycList(const List &copy);
  int getSize();
  void clear();
  bool isEmpty();
  bool isExistValue(T value);
  int getByIndex(int index);
  void editValue(int index, T value);
  int getIndex(T value);
  void addValue(T value);
  void insertValue(int index, T value);
  void removeValue(T value);
  void removeValue(int index, T values);
  int getLookedElemCount();
  string toString();

  ~CycList();

private:



};

#endif //_HEADERS_LIST_H_
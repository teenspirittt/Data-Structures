#ifndef _HEADERS_LIST_H_
#define _HEADERS_LIST_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;


template<typename T>
struct Node {
  T **field;
  Node *next;
  unsigned int length;                                          // Максимальная  длина массива
  unsigned int c_size;                                          // Текущая длина массива
  explicit Node(unsigned int _length);
  Node(T *_field, unsigned int _length);
  ~Node();
};

template<typename T>
class List {
 public:
  List();
  ~List();

  
  void add(T *_field);                                          // Добавление нового элемента в свободное место


 private:

};




#endif //_HEADERS_LIST_H_
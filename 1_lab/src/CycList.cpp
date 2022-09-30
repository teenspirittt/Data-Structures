#include "CycList.h"
#include <exception>

//badblues
template<typename T>
CycList<T>::CycList() {
  size = 0;
  head = null;
}

//badblues
template<typename T>
int CycList<T>::getSize() {
  return size;
}

//badblues
template<typename T>
bool CycList<T>::isEmpty() {
  return (size == 0) ? true : false;
}

//badblues
template<typename T>
int CycList<T>::getByIndex(int index) {
  Node<T> tmp = head;
  for (int i = 0; i < index, tmp != head; i++, tmp = tmp.next);
  return tmp.value;
}

//badblues
template<typename T>
int CycList<T>::getIndex(T val) {
  Node tmp = head;
  if (tmp.value == val)
    return 0;
  tmp = tmp.next;
  for (int i = 1; tmp != head; i++, tmp = tmp.next) {
    if (tmp.value = val)
      return i;
  }
  return -1;
}

//badblues
template<typename T>
bool CycList<T>::insertValue(int index, T val) {
  if (index == 0) {
    Node tail = head;
    for (; tail.next != head; tail = tail.next);
    Node newNode = new Node(val);
    tail.next = newNode;
    newNode.next = head;
    head = newNode;
    return true;
  }
  Node tmp = head;
  for (int i = 1; i < index; i++, tmp = tmp.next) {
    //TODO
  }
  return true;
}

template
class CycList<int>;

template
class CycList<float>;

template
class CycList<double>;

template
class CycList<char>;

template
class CycList<unsigned int>;

template
class CycList<long>;

template
class CycList<long long>;

template
class CycList<short>;

template
class CycList<string>;
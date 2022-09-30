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
int getByIndex(int index) {
  Node<T> temp = jead;
  for (int i = 0; i < index; i++) {
    temp = temp.next;
  }
  return temp;
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
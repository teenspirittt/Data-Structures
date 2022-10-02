#include "../headers/CycList.h"

#include <exception>

template <typename T>
CycList<T>::CycList(const CycList &copy) {}

template <typename T>
void CycList<T>::addValue(T value) {
  Node *tmp = tail;
  Node *p = new Node;
  p = next;
  next = tmp;
  tmp->field = value;
  tmp->next = p;
}

template class CycList<int>;

template class CycList<float>;

template class CycList<double>;

template class CycList<char>;

template class CycList<unsigned int>;

template class CycList<long>;

template class CycList<long long>;

template class CycList<short>;

template class CycList<string>;
#include "../headers/List.h"
#include <exception>

template<typename T>
Node<T>::Node(T *_field, unsigned int _length) {
  field = new T *[_length];
  next = nullptr;
  length = _length;
  field[0] = _field;
  c_size = 1;
}

template<typename T>
Node<T>::Node(unsigned int _length) {
  field = new T *[_length];
  next = nullptr;
  length = _length;
  c_size = 0;
}

template<typename T>
Node<T>::~Node() {
  delete[] field;
}

template<typename T>
List<T>::List() {
  head = nullptr;
  size = 0;
}

template<typename T>
List<T>::~List() {
  while (size != 0) {
    Node<T> *tmp = head->next;
    delete head;
    head = tmp;
    size--;
  }
}


template
class List<int>;

template
class List<float>;

template
class List<double>;

template
class List<char>;

template
class List<unsigned int>;

template
class List<long>;

template
class List<long long>;

template
class List<short>;

template
class List<string>;
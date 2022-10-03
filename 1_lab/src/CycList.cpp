#include "../headers/CycList.h"

#include <exception>

// badblues
template <typename T>
CycList<T>::CycList() {
  this->size = 0;
  this->head = NULL;
}

// badblues
template <typename T>
int CycList<T>::getSize() {
  return size;
}

// badblues
template <typename T>
bool CycList<T>::isEmpty() {
  return (size == 0) ? true : false;
}

// badblues
template <typename T>
T CycList<T>::getByIndex(int index) {
  Node<T>* tmp = head;
  for (int i = 0; i < index, tmp != head; i++, tmp = tmp->next);
  return tmp->value;
}

// badblues
template <typename T>
int CycList<T>::getIndex(T val) {
  Node<T>* tmp = head;
  if (tmp->value == val) return 0;
  tmp = tmp->next;
  for (int i = 1; tmp != head; i++, tmp = tmp->next) {
    if (tmp->value == val) return i;
  }
  return -1;
}

// badblues
template <typename T>
bool CycList<T>::insertValue(int index, T val) {
  if (index == 0) {
    Node<T>* tail = head;
    for (; tail->next != head; tail = tail->next)
      ;
    Node<T>* newNode = new Node(val);
    tail->next = newNode;
    newNode->next = head;
    head = newNode;
    return true;
  }
  Node<T>* tmp = head;
  for (int i = 1; i < index; i++, tmp = tmp->next) {
    // TODO
  }
  return true;
}

template <typename T>
void CycList<T>::addValue(T value) {
  Node tmp = new Node(value);
  Node tail = head;
  while (tail.next != head) {
    tail = tail.next;
  }
  if (head == null) {
    head = tmp;
    tail = node;
    tail.next = head;
  } else {
    node.next = head;
    tail.next = tmp;
    tail = tmp;
  }
  size++;
}

template <typename T>
bool CycList<T>::removeValue(T value) {
  Node current = head;
  Node previous = nullptr;

  if (isEmpty()) return false;
  do {
    if (current.value == value) {
      if (previous != null) {
        previous.next = current.next;

        if (current == tail) tail = previous;
      } else {
        if (size == 1) {
          head = tail = null;
        } else {
          head = current.Next;
          tail.Next = current.Next;
        }
      }
      size--;
      return true;
    }

    previous = current;
    current = current.Next;
  } while (current != head);

  return false
}

template <typename T>
void CycList<T>::show(int size) {
  Node tmpHead = head;
  int tmp = size;
  while (tmp != 0) {
    std::cout << tmpHead.value << " ";
    tmpHead = tmpHead.next;
    tmp--;
  }
}

template class CycList<int>;

template class CycList<double>;

template class CycList<char>;

template class CycList<unsigned int>;

template class CycList<long>;

template class CycList<long long>;

template class CycList<short>;

template class CycList<string>;
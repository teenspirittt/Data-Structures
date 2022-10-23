#include "../headers/CycList.h"

#include <exception>

// badblues
template<typename T>
CycList<T>::CycList() {
  this->size = 0;
  this->head = nullptr;
  this->tail = nullptr;
}

// teenspirit
/*template<typename T>
CycList<T>::CycList(const CycList<T> &copy) {
  copy.head = head;

  while (current != head) {

  }

}*/

// teenspirit
template<typename T>
void CycList<T>::editValue(int index, T value) {

}

// badblues
template<typename T>
int CycList<T>::getSize() {
  return size;
}

// badblues
template<typename T>
bool CycList<T>::isEmpty() {
  return (size == 0);
}

// badblues
template<typename T>
T CycList<T>::getByIndex(int index) {
  Node<T> *tmp = head;
  if (index == 0)
    return tmp->value;
  tmp = tmp->next;
  for (int i = 1; i < index && tmp != head; i++, tmp = tmp->next);
  return tmp->value;
}

// badblues
template<typename T>
int CycList<T>::getIndex(T val) {
  Node<T> *tmp = head;
  if (tmp->value == val) return 0;
  tmp = tmp->next;
  for (int i = 1; tmp != head; i++, tmp = tmp->next) {
    if (tmp->value == val) return i;
  }
  return -1;
}

// badblues
template<typename T>
bool CycList<T>::insertValue(int index, T val) {
  Node<T>* new_node = new Node(val);
  if (index == 0) {
    if (head == nullptr) {
      head = new_node;
      tail = new_node;
      tail->next = new_node;
      head->next = new_node;
    } else {
      tail->next = new_node;
      new_node->next = head;
      head = new_node;
    }
  } else if (index == size) {
    tail->next = new_node;
    new_node->next = head;
    tail = new_node;
  } else {
    Node<T>* tmp = head;
    for (int i = 1; i <= index; i++, tmp = tmp->next) {}
    new_node->next = tmp->next;
    tmp->next = new_node;
  }
  size++;
  return true;
}

//badblues
template<typename T>
string CycList<T>::toString() {
  stringstream *sstr = new stringstream;
  Node<T> *tmp = head;
  do {
    if (tmp) {
      *sstr << tmp->value;
      if (tmp->next != head)
        *sstr << " ";
      tmp = tmp->next;
    }
  } while (tmp != head);
  //убрать позже
  if (head) *sstr << " head.v = " << head->value << " tail.v = " << tail->value;
  return sstr->str();
}


//badblues
template<typename T>
int CycList<T>::getLookedElemCount() {
  return 1234;
}

// teenspirit
template<typename T>
void CycList<T>::addValue(T value) {
  Node<T> *tmp = new Node(value);

  if (head == nullptr) {
    head = tmp;
    tail = tmp;
    tail->next = head;
  } else {
    tmp->next = head;
    tail->next = tmp;
    tail = tmp;
  }
  size++;
}

// teenspirit
template<typename T>
bool CycList<T>::removeValue(T value) {
  int startSize = size;
  Node<T> *current = head;
  Node<T> *previous = nullptr;
  if (isEmpty()) return false;
  do {
    if (current->value == value) {
      if (previous != nullptr) {
        previous->next = current->next;

        if (current == tail) tail = previous;
      } else {
        if (size == 1) {
          head = tail = nullptr;
        } else {
          head = current->next;
          tail = current->next;
        }
      }
      size--;
    }
    previous = current;
    current = current->next;
  } while (current != head);

  if (size < startSize)
    return true;
  else
    return false;
}

//teenspirit
template<typename T>
bool CycList<T>::removeValueByIndex(int index) {
  //hyu govno
  return true;
}

// teenspirit
template<typename T>
void CycList<T>::show() {
  Node<T> *tmpHead = head;
  int tmp = size;
  while (tmp != 0) {
    std::cout << tmpHead->value << " ";
    tmpHead = tmpHead->next;
    tmp--;
  }
  std::cout << std::endl;
}

// teenspirit
template<typename T>
void CycList<T>::clear() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}

// teenspirit
template<typename T>
bool CycList<T>::isExistValue(T value) {
  Node<T> *tmpHead = head;
  int tmp = size;
  while (tmp != 0) {
    if (value == tmpHead->value) return true;
    tmpHead = tmpHead->next;
    tmp--;
  }
  return false;
}

template
class CycList<int>;

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
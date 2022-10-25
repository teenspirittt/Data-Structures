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
template<>
CycList<int>::CycList(const CycList<int> &copy) {
  Node<int> *tmp = copy.head;
  head = copy.head;
  tail = copy.tail;
  size = copy.size;
  do {
    addValue(tmp->value);
    tmp = tmp->next;
  } while (tmp != copy.head);
}

// teenspirit
template<>
CycList<string>::CycList(const CycList<string> &copy) {
  Node<string> *tmp = copy.head;
  head = copy.head;
  tail = copy.tail;
  size = copy.size;
  do {
    addValue(tmp->value);
  } while (tmp != copy.head);
}

// teenspirit
template<typename T>
bool CycList<T>::editValue(int index, T value) {
  if (index >= size || index < 0) {
    return false;
  }
  Node<T> *tmp = head;
  if (index == 0) {
    tmp->value = value;
    return true;
  }

  tmp = tmp->next;
  for (int i = 1; i < index && tmp != head; i++, tmp = tmp->next);
  tmp->value = value;
  return true;
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
  if (index >= size || index < 0)
    return NULL;
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
  if (tmp->value == val)
    return 0;
  tmp = tmp->next;
  for (int i = 1; tmp != head; i++, tmp = tmp->next) {
    if (tmp->value == val) return i;
  }
  return -1;
}

// badblues
template<typename T>
bool CycList<T>::insertValue(int index, T val) {
  if (index >= size + 1 || index < 0)
    return false;
  l_elem_c = 1;
  Node<T> *new_node = new Node(val);
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
    Node<T> *tmp = head;
    for (int i = 1; i < index; i++, tmp = tmp->next, l_elem_c++) {cout << "i = " << i << "\n";}
    
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
  if (head) *sstr << " head.v = " << head->value << " tail.v = " << tail->value;
  return sstr->str();
}

//badblues
template<typename T>
int CycList<T>::getLookedElemCount() {
  return l_elem_c;
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
  Node<T> *current = head;
  Node<T> *previous = nullptr;
  if (isEmpty())
    return false;
  if (current->value == value) {
    head = head->next;
    tail->next = head;
    size--;
    delete current;
    return true;
  }  
  do {
    if (current->value == value) {
      if (!previous) {
        previous->next = current->next;
        if (current == tail)
         tail = previous;
      } else {
        if (size == 1) {
          head = tail = nullptr;
        } else {
          head = current->next;
          tail = current->next;
        }
      }
      size--;
      return true;
    }
    previous = current;
    current = current->next;
  } while (current != head);
  return false;
}

//teenspirit
template<typename T>
bool CycList<T>::removeValueByIndex(int index) {
  l_elem_c = 1;
  if (index >= size || index < 0)
    return false;
  int startSize = size;
  Node<T> *current = head;
  Node<T> *previous = nullptr;

  if (index == 0) {
    head = head->next;
    tail->next = head;
    delete current;
    size--;
    return true;
  }  

  for (int i = 0; i < index; i++, l_elem_c++) {
    previous = current;
    current = current->next;
  }
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

  if (size > startSize)
    return false;
  else
    return true;
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
  l_elem_c = 1;
  Node<T> *tmpHead = head;
  int tmp = size;
  while (tmp != 0) {
    if (value == tmpHead->value) return true;
    tmpHead = tmpHead->next;
    tmp--;
    l_elem_c++;
  }
  l_elem_c--;
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
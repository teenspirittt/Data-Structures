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

template<typename T>
bool List<T>::is_empty() {
  return head == nullptr;
}

template<typename T>
unsigned int List<T>::get_arr_size(unsigned int num) {
  return get_node(num)->c_size;
}

template<typename T>
unsigned int List<T>::get_list_size() {
  return size;
}

template<typename T>
Node<T> *List<T>::get_node(unsigned int num) {
  Node<T> *tmp = head;
  for (unsigned int i = 0; i < num && tmp; ++i) {
    tmp = tmp->next;
  }
  return tmp;
}

template<typename T>
T *List<T>::get_elem(unsigned int list_num, unsigned int arr_pos) {
  if (is_empty()) {
    throw out_of_range("n/a index");
  }
  Node<T> *tmp = head;
  for (int i = 0; i < list_num; ++i) {
    tmp = tmp->next;
  }
  return tmp->field[arr_pos];
}

template<typename T>
unsigned int List<T>::get_non_empty_nodes() {
  Node<T> *tmp = head;
  unsigned int node_count = 0;
  for (int i = 0; i < size; ++i) {
    if (tmp->c_size > 0)
      node_count++;
    tmp = tmp->next;
  }
  return node_count;
}

template<typename T>
unsigned int List<T>::get_elem_count() {
  Node<T> *tmp = head;
  unsigned int count = 0;
  for (int i = 0; i < size; ++i) {
    if (tmp->c_size > 0)
      count = count + tmp->c_size;
    tmp = tmp->next;
  }
  return count;
}

template<typename T>
unsigned int List<T>::get_arr_length(unsigned int num) {
  return get_node(num)->length;
}

template<typename T>
void List<T>::remove_arr(unsigned int pos) {
  if (pos > size) {
    throw out_of_range("n/a index");
  }
  if (pos == 0) {
    Node<T> *tmp1 = head->next;
    delete head;
    head = tmp1;
  } else {
    Node<T> *tmp1 = head;
    for (int i = 0; i < pos - 1; ++i)
      tmp1 = tmp1->next;
    Node<T> *tmp2 = tmp1->next;
    tmp1->next = tmp1->next->next;
    delete tmp2;
  }
  size--;
}

template<typename T>
void List<T>::remove(unsigned int pos) {
  if (pos > get_non_empty_nodes()) {
    throw out_of_range("n/a index");
  }
  Node<T> *tmp = head;
  unsigned int sz;
  unsigned int arr_num = 0;
  for (unsigned int i = 0; i < size
      && pos >= get_arr_size(i); ++i) {
    pos -= get_arr_size(i);
    arr_num++;
  }
  unsigned int node_count = get_non_empty_nodes();
  tmp = get_node(arr_num);
  for (unsigned int i = arr_num; i < node_count; ++i) {
    for (unsigned int j = pos; j < (tmp->c_size - 1)
        && (tmp->c_size != 0); ++j) {
      tmp->field[j] = tmp->field[j + 1];
      sz = j;
    }
    if (pos == tmp->c_size - 1 && tmp->next != nullptr
        && tmp->next->c_size != 0) {
      tmp->field[tmp->c_size - 1] = tmp->next->field[0];
      tmp = tmp->next;
    } else if (tmp != nullptr && sz < tmp->length && tmp->next != nullptr
        && tmp->next->c_size != 0) {
      tmp->field[sz + 1] = tmp->next->field[0];
      tmp = tmp->next;
    }
    if (i == node_count - 1) {
      tmp->c_size--;
      if (tmp->c_size == 0) {
        node_count--;
      }
    }
    pos = 0;
  }
}

template<typename T>
void List<T>::add_arr() {
  if (is_empty()) {
    head = new Node<T>(START_LENGTH);
  } else {
    Node<T> *tmp = head;
    while (tmp->next != nullptr) {
      tmp = tmp->next;
    }
    tmp->next = new Node<T>(tmp->length * FACTOR);
  }
  size++;
}

template<typename T>
void List<T>::add(T *_field) {
  if (is_empty()) {
    head = new Node<T>(_field, START_LENGTH);
    size++;
  } else {
    Node<T> *tmp = head;
    Node<T> *tmp2;
    while (tmp != nullptr && tmp->c_size == tmp->length) {
      tmp2 = tmp;
      tmp = tmp->next;
    }
    if (tmp == nullptr) {
      tmp = new Node<T>(_field, tmp2->length * FACTOR);
      tmp2->next = tmp;
      size++;
    } else {
      tmp->field[tmp->c_size] = _field;
      tmp->c_size++;
    }
  }
}

template<typename T>
void List<T>::insert_arr(unsigned int pos) {
  if (pos > size) {
    throw out_of_range("n/a index");
  }
  if (pos == 0) {
    Node<T> *tmp = head;
    head = new Node<T>(START_LENGTH);
    head->next = tmp;
  } else {
    Node<T> *tmp = head;
    for (int i = 0; i < pos - 1; ++i) {
      tmp = tmp->next;
    }
    Node<T> *tmp2 = tmp->next;
    tmp->next = new Node<T>(tmp->length * FACTOR);
    tmp->next->next = tmp2;
  }
  size++;
}

template<typename T>
void List<T>::insert(T *_field, unsigned int pos) {
  if (pos > get_elem_count()) {
    throw out_of_range("n/a index");
  }
  Node<T> *tmp = head;
  Node<T> *tmp2;
  unsigned int arr_num = 0;
  unsigned int sum = 0;
  for (unsigned int i = 0; i < size && pos >= get_arr_size(i) && sum != get_elem_count(); ++i, sum += get_arr_size(i)) {
    pos -= get_arr_size(i);
    arr_num++;
    tmp = tmp->next;
  }
  if (tmp->c_size == 0) {
    tmp = get_node(arr_num);
    tmp->field[pos];
  }

  while (tmp != nullptr && tmp->c_size == tmp->length) {
    tmp2 = tmp;
    tmp = tmp->next;
  }
  if (tmp == nullptr) {
    tmp = new Node<T>(tmp2->length * FACTOR);
    tmp2->next = tmp;
    size++;
  }
  tmp = get_node(arr_num);
  if (tmp->c_size < tmp->length - 1) {
    for (int i = tmp->c_size; i > pos; --i) {
      tmp->field[i] = tmp->field[i - 1];
    }
    tmp->field[pos] = _field;
    tmp->c_size++;
  } else {
    T *last_el = tmp->field[tmp->c_size - 1];
    for (int i = tmp->c_size - 1; i > pos; --i) {
      tmp->field[i] = tmp->field[i - 1];
    }
    tmp->field[pos] = _field;
    tmp = tmp->next;
    while (tmp->c_size == tmp->length) {
      T *last_el2 = tmp->field[tmp->c_size - 1];
      for (int i = tmp->c_size - 1; i > 0; --i) {
        tmp->field[i] = tmp->field[i - 1];
      }
      tmp->field[0] = last_el;
      last_el = last_el2;
      tmp = tmp->next;
    }
    for (int i = tmp->c_size; i > 0; --i) {
      tmp->field[i] = tmp->field[i - 1];
    }
    tmp->field[0] = last_el;
    tmp->c_size++;
  }
}

template<typename T>
void List<T>::write_bin(fstream &out) {
  if (out.is_open()) {
    cout << "File was successfully written";
    Node<T> *tmp = head;
    for (int i = 0; i < size; ++i) {
      out.write((char *) &(tmp->c_size), sizeof(unsigned int));
      for (int j = 0; j < tmp->c_size; ++j) {
        out.write((char *) tmp->field[j], sizeof(T));
      }
      tmp = tmp->next;
    }
  }
}

template<>
void List<string>::write_bin(fstream &out) {
  if (out.is_open()) {
    cout << "File was successfully written";
    Node<string> *tmp = head;
    for (int i = 0; i < size; ++i) {
      out.write((char *) &(tmp->c_size), sizeof(unsigned int));
      for (int j = 0; j < tmp->c_size; ++j) {
        unsigned int sz = tmp->field[j]->length() + 1;
        out.write((char *) &sz, sizeof(unsigned int));
        out.write((char *) tmp->field[j]->c_str(), sizeof(char) * sz);
      }
      tmp = tmp->next;
    }
  }
}

template<typename T>
void List<T>::read_bin(fstream &in) {
  while (size != 0) {
    Node<T> *tmp = head->next;
    delete head;
    head = tmp;
    size--;
  }
  unsigned int sz = 0;
  unsigned int el_sz = 0;
  Node<T> *tmp;
  head = nullptr;
  if (in.is_open()) {
    cout << "File was successfully read\n";
    if (in.peek() != EOF) {
      in.read((char *) &sz, sizeof(unsigned int));
      tmp = new Node<T>(sz);
      head = tmp;
    }
    while (in.peek() != EOF) {
      for (int i = 0; i < sz; ++i) {
        T *el_tmp = new T[el_sz];
        in.read((char *) el_tmp, sizeof(T));
        tmp->field[i] = el_tmp;
        tmp->c_size++;
      }
      sz = 0;
      in.read((char *) &sz, sizeof(unsigned int));
      if (sz > 0) {
        tmp->next = new Node<T>(sz);
        tmp = tmp->next;
        size++;
      } else {
        size++;
      }
    }
  }
}

template<>
void List<string>::read_bin(fstream &in) {
  while (size != 0) {
    Node<string> *tmp = head->next;
    delete head;
    head = tmp;
    size--;
  }
  unsigned int sz = 0;
  unsigned int el_sz = 0;
  Node<string> *tmp;
  head = nullptr;
  if (in.is_open()) {
    cout << "File was successfully read\n";
    if (in.peek() != EOF) {
      in.read((char *) &sz, sizeof(unsigned int));
      tmp = new Node<string>(sz);
      tmp->length = FACTOR;
      head = tmp;
    }
    int len = 2;
    while (in.peek() != EOF) {
      for (int i = 0; i < sz; ++i) {
        in.read((char *) &el_sz, sizeof(unsigned int));
        char *el_tmp = new char[el_sz];
        in.read(el_tmp, el_sz);
        string *str = new string(el_tmp);
        tmp->field[i] = str;
        tmp->c_size++;
      }
      sz = 0;
      in.read((char *) &sz, sizeof(unsigned int));
      if (sz > 0) {
        tmp->next = new Node<string>(sz);
        tmp = tmp->next;
        len = len * FACTOR;
        tmp->length = len;
        size++;
      } else
        size++;

    }
  }
}

template<typename T>
void List<T>::sort() {
  for (int i = 0; i < get_elem_count(); ++i) {
    unsigned int min_i = i;
    unsigned int min_n = 0;
    unsigned int cur_i = i;
    unsigned int cur_n = 0;
    for (int j = 0; j < size && cur_i >= get_arr_length(j); ++j, ++cur_n)
      cur_i -= get_arr_length(j);
    for (int j = 0; j < size && min_i >= get_arr_size(j); ++j, ++min_n)
      min_i -= get_arr_size(j);
    for (unsigned int j = min_i; j < get_arr_size(min_n); ++j) {
      if ((*get_elem(min_n, j)) < (*get_elem(min_n, min_i))) {
        min_i = j;
      }
    }
    for (unsigned int j = min_n + 1; j < size; ++j) {
      for (unsigned int k = 0; k < get_arr_size(j); ++k) {
        if ((*get_elem(j, k)) < (*get_elem(min_n, min_i))) {
          min_i = k;
          min_n = j;
        }
      }
    }
    if (get_arr_size(cur_n) > cur_i) {
      swap((*get_node(cur_n)->field[cur_i]), (*get_node(min_n)->field[min_i]));
    } else {
      (*get_node(cur_n)->field[cur_i]) = (*get_node(min_n)->field[min_i]);
      get_node(min_n)->c_size--;
      get_node(cur_n)->c_size++;
    }
  }
}

template<typename T>
void List<T>::balance() {
  Node<T> *tmp = head;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < tmp->length; ++j) {
      if (j == tmp->length / 2) {
        if (tmp->next == nullptr) {
          continue;
        }
        for (int k = tmp->c_size; k > tmp->length / 2; --k) {
          insert(tmp->field[k - 1], tmp->length);
          tmp->c_size--;
        }
      }
    }
    tmp = tmp->next;
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
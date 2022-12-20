#pragma once

#include "OANode.h"
#include "HashTableForm.h"
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

template <typename T> class OAHashTable : public HashTableForm<T> {
public:
  OAHashTable(unsigned int capacity_) {
    this->capacity = capacity_;
    this->size = 0;
    this->nodes = new OANode<T> *[this->capacity];
    for (int i = 0; i < this->capacity; ++i) {
      this->nodes[i] = new OANode<T>();
    }
  }

  ~OAHashTable() {
    for (int i = 0; i < this->capacity; i++) {
      if (nodes[i] != NULL) {
        delete nodes[i];
      }
      nodes[i] = NULL;
    }
  }

  bool Insert(string k, T data) override {
    this->nodes_counter = 0;
    for (int i = 0; i < k.size(); i++)
      if (k[i] < 'A' || k[i] > 'Z')
        k = k.substr(0, i);
    if (k.size() == 0)
      return false;
    int i = 0;
    int pos = -1;
    int j = HashFunction(k, i);
    for (; i != this->capacity && !IsFree(j); i++) {
      this->nodes_counter++;
      j = HashFunction(k, i);
      if (pos == -1 && IsDeleted(j)) {
        pos = j;
      }
      if (IsBusy(j) && this->nodes[j]->key == k) {

        return false;
      }
    }
    if (i == this->capacity && pos == -1) {
      return false;
    }
    if (pos == -1) {
      pos = j;
    }
    this->nodes_counter++;
    this->nodes[pos]->key = k;
    this->nodes[pos]->value = data;
    this->nodes[pos]->state = states::busy_;
    this->size++;
    return true;
  }

  bool Remove(string k) override {
    this->nodes_counter = 0;
    int i = 0;
    int j;
    do {
      this->nodes_counter++;
      j = HashFunction(k, i);
      if (IsBusy(j) && this->nodes[j]->key == k) {
        this->nodes[j]->state = states::deleted_;
        this->size--;
        return true;
      }
      i++;
    } while (i != this->capacity || !IsFree(j));
    return false;
  }

  T Get(string k) override {
    this->nodes_counter = 0;
    int i = 0;
    int j;

    do {
      this->nodes_counter++;
      j = HashFunction(k, i);
      if (IsBusy(j) && this->nodes[j]->key == k) {
        return this->nodes[j]->value;
      }
      i++;
    } while (i != this->capacity || !IsFree(j));

    throw "not found!";
  }

  int GetSize() override { return this->size; }

  int GetCapacity() override { return this->capacity; }

  bool IsEmpty() override { return this->size == 0; }

  void Clear() override {
    for (int i = 0; i < this->capacity; ++i) {
      if (this->nodes[i]->state == states::busy_)
        this->nodes[i]->state = states::deleted_;
    }
  }

  string ToString() override {
    stringstream *sstr = new stringstream();
    cout << "0 = FREE; 1 = BUSY; 2 = DELETED\n";
    for (int i = 0; i < this->capacity; ++i) {
      if (IsBusy(i)) {
        *sstr << i << ": [" << this->nodes[i]->key << ","
              << this->nodes[i]->value << "](" << this->nodes[i]->state
              << ")\n";
      } else {
        *sstr << i << ": (" << this->nodes[i]->state << ")\n";
      }
    }
    return sstr->str();
  }

  // class Iterator {
  //   OAHashTable *ptr;
  //   OANode<T> *cur;
  //   int i;

  // public:
  //   Iterator(OAHashTable *_p, bool begin = false) : ptr(_p), i(0) {
  //     if (!begin || ptr->GetSize() == 0) {
  //       cur = nullptr;
  //     } else {
  //       for (i = 0; i < ptr->capacity; i++) {
  //         if (ptr->nodes[i]->state == states::busy_) {
  //           cur = ptr->nodes[i];
  //           break;
  //         }
  //       }
  //     }
  //   }

  //   void next() {
  //     for (i++; i < ptr->capacity; i++) {
  //       if (ptr->IsBusy(i)) {
  //         cur = ptr->nodes[i];
  //         return;
  //       }
  //     }
  //     cur = nullptr;
  //   }

  //   bool operator==(Iterator it) { return this->cur == it.cur; }

  //   bool operator!=(Iterator it) { return this->cur != it.cur; }

  //   bool is_off() { return (!cur || cur->state != states::busy_); }

  //   T *operator*() {
  //     if (!cur || cur->state != states::busy_)
  //       throw "iterator is not setted";
  //     return &(cur->value);
  //   }

  //   string showkey() {
  //     if (!cur || cur->state != states::busy_)
  //       throw "iterator is not setted";
  //     return cur->key;
  //   }
  // };

  // Iterator Begin() { return OAHashTable<T>::Iterator(this, true); }

  // Iterator End() { return OAHashTable<T>::Iterator(this, false); }

private:
  OANode<T> **nodes;

  static const int default_size = 16;

  bool IsDeleted(int j) { return this->nodes[j]->state == states::deleted_; }

  bool IsBusy(int j) { return this->nodes[j]->state == states::busy_; }

  bool IsFree(int j) { return this->nodes[j]->state == states::free_; }

  int HashFunction(string str, int i) {
    return (HornerFunction(str) + i) % this->capacity;
  }

  int HornerFunction(string str) {
    unsigned k = 0;
    for (unsigned i = 0; i < str.size(); ++i) {
      k += pow(32, str.size() - 1 - i) * (str.at(i) - 'A' + 1);
    }

    double g_r = 0.6180339887;

    double X = g_r * k;
    X = X - (unsigned)X;
    return (unsigned)(X * this->capacity);
  }
};

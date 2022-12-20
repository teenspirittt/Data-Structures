#pragma once

#include "CLNode.h"
#include "HashTableForm.h"
#include "cmath"
#include "string"
#include <iostream>
#include <sstream>


using namespace std;

template <typename T> class CLHashTable : public HashTableForm<T> {
public:
  CLHashTable(unsigned int capacity_) {
    this->capacity = capacity_;
    this->size = 0;
    this->nodes = new CLNode<T> *[this->capacity];
    for (int i = 0; i < this->capacity; ++i) {
      this->nodes[i] = nullptr;
    }
  }

  ~CLHashTable() {
    for (int i = 0; i < this->capacity; i++) {
      if (nodes[i] != nullptr) {
        delete nodes[i];
      }
      nodes[i] = nullptr;
    }
  }

  bool Insert(string k, T data) override {
    this->nodes_counter = 0;
    for (int i = 0; i < k.size(); i++)
      if (k[i] < 'A' || k[i] > 'Z')
        k = k.substr(0, i);
    if (k.size() == 0)
      return false;
    int j = HornerFunction(k);
    if (this->nodes[j] == nullptr) {
      this->nodes_counter++;
      this->nodes[j] = new CLNode<T>(k, data);
    } else {
      CLNode<T> *p = this->nodes[j];
      this->nodes_counter++;
      if (p->key == k) {
        return false;
      }
      while (p->next != nullptr) {
        this->nodes_counter++;
        p = p->next;
        if (p->key == k) {
          return false;
        }
      }
      p->next = new CLNode<T>(k, data);
    }
    this->size++;
    return true;
  }

  bool Remove(string k) override {
    this->nodes_counter = 0;
    int j = HornerFunction(k);
    CLNode<T> *p = this->nodes[j];
    this->nodes_counter++;
    if (p == nullptr) {
      return false;
    }
    if (p->key == k) {
      this->nodes[j] = this->nodes[j]->next;
      delete p;
      this->size--;
      return true;
    }

    while (p->next != nullptr) {
      this->nodes_counter++;
      if (p->next->key == k)
        break;
      p = p->next;
    }
    if (p->next == nullptr) {
      return false;
    }
    CLNode<T> *t = p->next;
    p->next = p->next->next;
    delete t;
    this->size--;
    return true;
  }

  T Get(string k) override {
    this->nodes_counter = 0;
    int j = HornerFunction(k);
    CLNode<T> *t = this->nodes[j];
    while (t != nullptr) {
      this->nodes_counter++;
      if (t->key == k) {
        break;
      }
      t = t->next;
    }
    if (t == nullptr)
      throw "not found!";
    return t->value;
  }

  bool IsEmpty() override { return (this->size == 0); }

  void Clear() override {
    for (int i = 0; i < this->capacity; i++) {
      CLNode<T> *t = this->nodes[i];
      while (t != nullptr) {
        CLNode<T> *tmp = t->next;
        delete t;
        this->size--;
        t = tmp;
      }
      this->nodes[i] = nullptr;
    }
  }

  int GetSize() override { return this->size; }

  int GetCapacity() override { return this->capacity; }

  string ToString() override {
    stringstream *sstr = new stringstream();
    for (int i = 0; i < this->capacity; i++) {
      if (this->nodes[i] != nullptr) {
        *sstr << i << ": [" << this->nodes[i]->key << ","
              << this->nodes[i]->value << "]";
        CLNode<T> *t = this->nodes[i]->next;
        while (t != nullptr) {
          *sstr << ", [" << t->key << "," << t->value << "]";
          t = t->next;
        }
        *sstr << "\n";
      } else
        *sstr << i << ": []\n";
    }
    return sstr->str();
  }

  CLNode<T> **GetNodes() {
    return nodes;
  }


private:
  CLNode<T> **nodes;

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

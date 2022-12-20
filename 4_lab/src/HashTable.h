#pragma once

#include "CLHashTable.h"
#include "HashTableForm.h"
#include "OAHashTable.h"
#include <string>

using namespace std;

template <typename T> class HashTable {
public:
  HashTable(unsigned int capacity_, int clform_) {
    clform = clform_;
    if (clform)
      table = new CLHashTable<T>(capacity_);
    else
      table = new OAHashTable<T>(capacity_);
  }

  ~HashTable() {}

  bool Insert(string k, T data) { return table->Insert(k, data); }

  bool Remove(string k) { return table->Remove(k); }

  T Get(string k) { return table->Get(k); }

  bool IsEmpty() { return table->IsEmpty(); }

  int GetSize() { return table->GetSize(); }

  int GetCapacity() { return table->GetCapacity(); }

  void Clear() { table->Clear(); }

  void ChangeForm() {
    if (clform)
      ToOA();
    else
      ToCL();
  }

  bool IsCL() { return clform; }

  string ToString() { return table->ToString(); }

  int CountNodes() { return table->CountNodes(); }

private:
  void ToCL() {
    OAHashTable<T> *oatable = (OAHashTable<T> *)table;
    OANode<T> **nodes = oatable->GetNodes();
    CLHashTable<T> *cltable = new CLHashTable<T>(GetCapacity());
    for (int i = 0; i < GetCapacity(); i++) {
      if (nodes[i]->state==states::busy_)
        cltable->Insert(nodes[i]->key, nodes[i]->value);
    }
    table = cltable;
    clform = true;
    delete oatable;
  }

  void ToOA() {
    CLHashTable<T> *cltable = (CLHashTable<T> *)table;
    CLNode<T> **nodes = cltable->GetNodes();
    OAHashTable<T> *oatable = new OAHashTable<T>(GetCapacity());
    for (int i = 0; i < GetCapacity(); i++) {
      if (nodes[i] != nullptr) {
        oatable->Insert(nodes[i]->key, nodes[i]->value);
        CLNode<T> *t = nodes[i]->next;
        while (t != nullptr) {
          oatable->Insert(t->key, t->value);
          t = t->next;
        }
      }
    }
    table = oatable;
    clform = false;
    delete cltable;
  }

  bool clform;
  HashTableForm<T> *table;
};

template class HashTable<int>;

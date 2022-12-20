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

  class Iterator {
  public:
    Iterator(HashTable<T>* ptr) {
      this->ptr = ptr;
    }

    Iterator(HashTable<T> *ptr, int id) {
      this->ptr = ptr;
      this->id = id;
      if (id == 0) {
        if (ptr->clform) {
          CLHashTable<T> *cltable = (CLHashTable<T> *)ptr->table;
          for (; id < cltable->GetCapacity(); id++) {
            if (cltable->GetNodes()[id] != nullptr) {
              clcur = cltable->GetNodes()[id];
              return;
            }
          }
        } else {
          OAHashTable<T> *oatable = (OAHashTable<T> *)ptr->table;
          for (; id < oatable->GetCapacity(); id++) {
            if (oatable->GetNodes()[id]->state == states::busy_) {
              oacur = oatable->GetNodes()[id];
              return;
            }
          }
        }
      }
    }

    Iterator operator++() {
      if (ptr->clform)
        NextCLCur();
      else
        NextOACur();
      return *this;
    }

    T *operator*() {
      if (ptr->clform)
        return &(clcur->value);
      return &(oacur->value);
    }

    bool operator==(const Iterator it) {
      return ((ptr->clform && clcur == it.clcur) || (!ptr->clform && oacur == it.oacur));
    }

    bool operator!=(const Iterator it) {
      return ((ptr->clform && clcur != it.clcur) || (!ptr->clform && oacur != it.oacur));
    }

    void operator=(const Iterator it) {
      id = it.id;
      clcur = it.clcur;
      oacur = it.oacur;
    }

  private:
    void NextOACur() {
      OAHashTable<T> *oatable = (OAHashTable<T> *)ptr->table;
      for (id++; id < ptr->table->GetCapacity(); id++) {
        if (oatable->GetNodes()[id]->state == states::busy_) {
          oacur = oatable->GetNodes()[id];
          return;
        }
      }
      oacur = nullptr;
    }

    void NextCLCur() {
      CLHashTable<T> *cltable = (CLHashTable<T> *)ptr->table;
      if (!clcur || id == ptr->table->GetCapacity())
        return;
      if (clcur->next) {
        clcur = clcur->next;
        return;
      }
      do {
        clcur = cltable->GetNodes()[++id];
        if (clcur)
          break;
      } while (id != ptr->table->GetCapacity());
      if (!clcur || id == ptr->table->GetCapacity()) {
        clcur = nullptr;
        id = 0;
      }
    }

    HashTable<T>* ptr;
    int id = -1;
    CLNode<T> *clcur = nullptr;
    OANode<T> *oacur = nullptr;
  };

  Iterator Begin() { return Iterator(this, 0); }

  Iterator End() { return Iterator(this, -1); }

private:
  void ToCL() {
    OAHashTable<T> *oatable = (OAHashTable<T> *)table;
    OANode<T> **nodes = oatable->GetNodes();
    CLHashTable<T> *cltable = new CLHashTable<T>(GetCapacity());
    for (int i = 0; i < GetCapacity(); i++) {
      if (nodes[i]->state == states::busy_)
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

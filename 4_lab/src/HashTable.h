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
    // TODO:
  }

  bool IsCL() { return clform; }

  string ToString() { return table->ToString(); }

  int CountNodes() { return table->CountNodes(); }

private:
  bool clform;
  HashTableForm<T> *table;
};

template class HashTable<int>;

#pragma once

#include <string>

using namespace std;

template <typename T> class HashTableForm {
public:
  HashTableForm() {}

  ~HashTableForm() {}

  virtual bool Insert(string k, T data) = 0;

  virtual bool Remove(string k) = 0;

  virtual T Get(string k) = 0;

  virtual bool IsEmpty() = 0;

  virtual int GetSize() = 0;

  virtual int GetCapacity() = 0;

  virtual void Clear() = 0;

  virtual string ToString() = 0;

  int CountNodes() { return nodes_counter; }

protected:
  int size;
  unsigned int capacity;
  int nodes_counter = 0;
};
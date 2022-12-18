#pragma once

#include <algorithm>
#include <string>
#include <cmath>
#include "OANode.h"
#include <sstream>

using namespace std;

template<typename T>
class OAHashTable {
public:

    OAHashTable();

    OAHashTable(int capacity);

    ~OAHashTable();

    bool Insert(string k, T data);

    bool Remove(string k);

    T Get(string k);

    int GetSize() const;

    int GetCapacity() const;

    bool IsEmpty();

    bool Clear();

    string ToString();

    int CountNodes() {
        return nodes_counter;
    }


    class Iterator {
        OAHashTable *ptr;
        OANode<T> *cur;
        int i;
    public:
        Iterator(OAHashTable *_p, bool begin = false) : ptr(_p), i(0) {
            if (!begin || ptr->GetSize() == 0) {
                cur = nullptr;
            } else {
                for (i = 0; i < ptr->capacity; i++) {
                    if (ptr->nodes[i]->state == states::busy_) {
                        cur = ptr->nodes[i];
                        break;
                    }
                }
            }
        }

        void next() {
            for (i++; i < ptr->capacity; i++) {
                if (ptr->IsBusy(i)) {
                    cur = ptr->nodes[i];
                    return;
                }
            }
            cur = nullptr;
        }

        bool operator==(Iterator it) {
            return this->cur == it.cur;
        }

        bool operator!=(Iterator it) {
            return this->cur != it.cur;
        }

        bool is_off() {
            return (!cur || cur->state != states::busy_);
        }

        T* operator*() {
            if (!cur || cur->state != states::busy_)
                throw "iterator is not setted";
            return &(cur->value);
        }

        string showkey() {
            if (!cur || cur->state != states::busy_)
                throw "iterator is not setted";
            return cur->key;
        }
    };


    Iterator Begin() {
        return OAHashTable<T>::Iterator(this, true);
    }

    Iterator End() {
        return OAHashTable<T>::Iterator(this, false);
    }

private:
    int size;
    int capacity;
    OANode<T> **nodes;

    int nodes_counter = 0;

    static const int default_size = 16;

    bool IsDeleted(int j) const;

    bool IsBusy(int j) const;

    bool IsFree(int j) const;

    int HashFunction(string str, int i);

    int HornerFunction(string str);

};

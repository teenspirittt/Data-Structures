#pragma once

#include "CLNode.h"
#include "string"
#include <iostream>
#include "cmath"
#include <sstream>

using namespace std;

template<typename T>
class CLHashTable {
public:
    CLHashTable(int capacity);

    ~CLHashTable();

    bool Insert(string k, T data);

    bool Remove(string k);

    T Get(string k);

    bool IsEmpty();

    bool Clear();

    int GetSize() const;

    int GetCapacity() const;

    string ToString();

    int CountNodes() {
        return nodes_counter;
    }


    class Iterator {
        CLHashTable<T> *ptr;
        CLNode<T> *cur;
        int i;

    public:
        Iterator(CLHashTable<T> *_p, CLNode<T> *_c) : ptr(_p), cur(_c), i(0) {}

        void next() {
            if (!cur || i == ptr->GetCapacity()) return;
            if (cur->next) {
                cur = cur->next;
                return;
            }
            do {
                cur = ptr->GetNodes()[++i];
                if (cur)
                    break;
            } while (i != ptr->GetCapacity());
        }

        void first() {
            for (i = 0; i < ptr->GetCapacity(); i++) {
                cur = ptr->GetNodes()[i];
                if (cur)
                    break;
            }
            if (!cur)
                throw "empty table!";
        }

        bool operator==(Iterator it) {
            return this->cur == it.cur;
        }

        bool operator!=(Iterator it) {
            return this->cur != it.cur;
        }

        bool is_off() {
            if (!cur || i == ptr->GetCapacity())
                return true;
            return false;
        }

        T operator*() {
            if (!cur || i == ptr->GetCapacity())
                throw "Iterator is not setted!";
            return cur->value;
        }

        string showkey() {
            if (!cur || i == ptr->GetCapacity())
                throw "Iterator is not setted!";

            return cur->key;
        }
    };


public:
    Iterator begin() {
        CLNode<T> **test = this->nodes;
        CLNode<T> *_cur = nullptr;
        for (int i = 0; i < this->capacity; i++) {
            _cur = test[i];
            if (_cur)
                break;
        }
        return CLHashTable<T>::Iterator(this, _cur);
    }

    Iterator end() {
        return CLHashTable<T>::Iterator(this, nullptr);
    }

    CLNode<T> **GetNodes() const {
        return nodes;
    }

private:
    CLNode<T> **nodes;
    int size;
    int capacity;
    int nodes_counter = 0;
    int HornerFunction(string str);
};

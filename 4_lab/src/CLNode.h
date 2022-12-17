#pragma once

#include <string>

using namespace std;

template<typename T>
struct CLNode {
    string key;
    T value;
    CLNode<T> *next;
    CLNode() {
        this->next = nullptr;
    }
    CLNode(string key, T value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

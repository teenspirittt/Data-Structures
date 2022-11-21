#pragma once

using namespace std;
typedef unsigned int uint;

template <typename K, typename V>
struct Node {
    V value;
    K key;
    Node* left;
    Node* right;
    Node(K key, V value) {
        this->value = value;
        this->key = key;
        left = nullptr;
        right = nullptr;
    }
};
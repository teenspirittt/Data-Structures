#pragma once


typedef unsigned int uint;

template <typename T>
struct Node {
    T value;
    Node* left;
    Node* right;
    Node(T value) {this->value = value;}
};

template <typename T>
class BSTree {
    public:
    private:
};
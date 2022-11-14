#pragma once


typedef unsigned int uint;

template <typename T>
struct Node {
    T value;
    int key;
    Node* left;
    Node* right;
    Node(T value) {this->value = value;}
};

template <typename T>
class BSTree {
    public:
    BSTree() {}
    BSTree(const BSTree& copy);
    ~BSTree(){}
    uint size();
    void clear();
    boolean isEmpty();
    T get(int key);
    T set(int key);
    T insert(T value, int key);
    bool remove(int key);
    void printKeys();
    void printTree();
    
    private:
        uint size{};
        Node<T>* root{};
};
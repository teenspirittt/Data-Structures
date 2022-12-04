#pragma once

using namespace std;
typedef unsigned int uint;

template<typename K, typename V>
class Node {
    public:
    Node* child[3];
    K keys[2];
    V value = V(0);
    int length = int(0);
    Node() {}
};

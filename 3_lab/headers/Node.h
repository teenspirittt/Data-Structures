
template<typename K, typename V>
class Node {
}

template<typename K, typename V>
class Leaf: public Node {
    K key;
    V value;
    Leaf(K k, V v) {key = k; value = v;}
}

template<typename K, typename V>
class InnerNode: public Node{
    Node* child[3];
    K keys[2];
    int length;
    InnerNode() { }
}
#pragma once

#include <iostream>

using namespace std;
typedef unsigned int uint;

template<typename K, typename V>
class Node {
	public:
		virtual bool inner() = 0;
};

template<typename K, typename V>
class Internal: public Node<K,V> {
	public:
		Node<K,V> *son1, *son2, *son3; 
		K key1, key2; 
		bool inner(){ return 1; }
		Internal() {
			son1 = son2 = son3 = NULL; 
			key1 = key2 = INT_MAX;
		}
};



template<typename K, typename V>
class Leaf: public Node<K,V> {
	public:
		K key;
		V value;
		bool inner() { return 0; }
		Leaf(K key_, V value_) { key = key_; value = value_; }
};
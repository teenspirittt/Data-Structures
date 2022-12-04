#include "TTTree.h"
#include "Node.h"

using namespace std;

template<typename K, typename V>
uint TTTree<K,V>::GetSize() {
    return size;
}

template<typename K, typename V>
bool TTTree<K,V>::IsEmpty() {
    return size == 0;
}

template<typename K, typename V>
V TTTree<K,V>::Get(K key) {
    Leaf<K,V>* node = Get(root, key);
    if (node)
        return node->value;
    return V(0);
}

template<typename K, typename V>
bool TTTree<K,V>::Set(K key, V value) {
    Node<K,V>* node = Get(root, key);
    if (node) {
        node->value = value;
        return true;
    }
    return false;
}

template<typename K, typename V> 
Leaf<K,V>* TTTree<K,V>::Get(Internal<K,V> *node, K key) {
	nodes_counter++;
	if (node == nullptr)
        return nullptr;
		//throw TreeException();
	if (node->son1->type()==0) {
		if (((Leaf<K,V>*)node->son1)->key==key)
			return ((Leaf<K,V>*)node->son1);
		if (node->son2) 
			if(((Leaf<K,V>*)node->son2)->key==key)
				return ((Leaf<K,V>*)node->son2);
		if (node->son3) 
			if (((Leaf<K,V>*)node->son3)->key==key)
				return ((Leaf<K,V>*)node->son3);
		return V(0);
        //throw TreeException();
	}
	if(node->key1>key) 
		return Get(((Internal<K,V> *)node->son1),key);
	if(node->key2>key) 
		return Get(((Internal<K,V> *)node->son2),key);
	return Get(((Internal<K,V> *)node->son3),key);
}

template<typename K, typename V>
void TTTree<K,V>::Clear() {
    Clear(root);
    delete root;
    root = nullptr;
    size = 0;
}

template<typename K, typename V>
void TTTree<K,V>::Clear(Internal<K,V> *node) {
	if(node == NULL) return;
	if(node->son1->type() == 0) {
		if(node->son1) delete node->son1;
		if(node->son2) delete node->son2;
		if(node->son3) delete node->son3;
		return;
	}
	Clear(((Internal<K,V>*)node->son1)); 
	delete node->son1;
	Clear(((Internal<K,V>*)node->son2));
	delete node->son2;
	if(node->son3) {
		Clear(((Internal<K,V>*)node->son3));
		delete node->son3;
	}
}

template<typename K, typename V>
int TTTree<K,V>::CountNodes() {
    return nodes_counter;
}
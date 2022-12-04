#include "TTTree.h"

template<typename K, typename V>
uint TTTree<K,V>::getSize() {
    return size;
}
template<typename K, typename V>
void clear() {
    //TODO:
}

template<typename K, typename V>
bool TTTree<K,V>::isEmpty() {
    return size == 0;
}

template<typename K, typename V>
V TTTree<K,V>::Get(K key) {
    Node* node = Get(root, k);
    if (node)
        return node->value;
    return V(0);
}

template<typename K, typename V>
bool TTTree<K,V>::Set(K key, V value) {
    Node* node = Get(root, k);
    if (node) {
        node->value = value;
        return true;
    }
    return false;
}

template<typename K, typename V> 
Node* TTTree<K,V>::Get(Internal *t, K k) {
	cnt++;
	if (t == NULL)
        return null;
		//throw TreeException();
	if (t->son1->type()==0) {
		if (((Leaf *)t->son1)->key==k)
			return ((Leaf *)t->son1);
		if (t->son2) 
			if(((Leaf *)t->son2)->key==k)
				return ((Leaf *)t->son2);
		if (t->son3) 
			if (((Leaf *)t->son3)->key==k)
				return ((Leaf *)t->son3);
		return V(0);
        //throw TreeException();
	}
	if(t->key1>k) 
		return Get(((Internal *)t->son1),k);
	if(t->key2>k) 
		return Get(((Internal *)t->son2),k);
	return Get(((Internal *)t->son3),k);
}
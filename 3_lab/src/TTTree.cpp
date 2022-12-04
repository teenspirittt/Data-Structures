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
    Leaf<K,V>* node = Get(root, key);
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
	if (node->son1->inner() == 0) {
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
		return Get(((Internal<K,V>*)node->son1),key);
	if(node->key2>key) 
		return Get(((Internal<K,V>*)node->son2),key);
	return Get(((Internal<K,V>*)node->son3),key);
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
	if(node->son1->inner() == 0) {
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

template<typename K, typename V>
TTTree<K, V>::TTTree() {
  root = nullptr;
  nodes_counter = 0;
  size = 0;
}

template<typename K, typename V>
TTTree<K, V>::TTTree(const TTTree &copy) {

}
template<typename K, typename V>
TTTree<K, V>::~TTTree() {
  Clear();
}


template<typename K, typename V>
bool TTTree<K, V>::Insert(K key, V value) {
  if(candidate == nullptr) {
    root = new node(key);
    return false;
  }
  if(candidate->isleaf()) {
    candidate->store(key);
  }else {
    if(*candidate->firstkey > *key) {
      insert(candidate->less, key); //Insert to left subtree.
    }else if(*candidate->firstkey <= *key && candidate->is2node()) {
      insert(candidate->btwn, key); //Insert to mid-subtree.
    }else {
      if(*candidate->secondkey > *key) {
        insert(candidate->btwn, key); //Insert to mid-subtree.
      }else {
        insert(candidate->great, key); //Insert to right subtree.
      }
    }
  }
  split(candidate);
  return false;
}

template<typename K, typename V>
void split(Node<K,V> *root) {
  if (root->size < 3) return root;

  auto *x = new Node<K,V>(root->key[0], root->first, root->second, nullptr, nullptr, root->parent); // Создаем две новые вершины,
  auto *y = new Node<K,V>(root->key[2], root->third, root->fourth, nullptr, nullptr, root->parent);  // которые имеют такого же родителя, как и разделяющийся элемент.
  if (x->first)  x->first->parent = x;    // Правильно устанавливаем "родителя" "сыновей".
  if (x->second) x->second->parent = x;   // После разделения, "родителем" "сыновей" является "дедушка",
  if (y->first)  y->first->parent = y;    // Поэтому нужно правильно установить указатели.
  if (y->second) y->second->parent = y;

  if (root->parent) {
    root->parent->insert_to_node(root->key[1]);

    if (root->parent->first == root) root->parent->first = nullptr;
    else if (root->parent->second == root) root->parent->second = nullptr;
    else if (root->parent->third == root) root->parent->third = nullptr;

    // Дальше происходит своеобразная сортировка ключей при разделении.
    if (root->parent->first == nullptr) {
      root->parent->fourth = root->parent->third;
      root->parent->third = root->parent->second;
      root->parent->second = y;
      root->parent->first = x;
    } else if (root->parent->second == nullptr) {
      root->parent->fourth = root->parent->third;
      root->parent->third = y;
      root->parent->second = x;
    } else {
      root->parent->fourth = y;
      root->parent->third = x;
    }

    Node<K,V> *tmp = root->parent;
    delete root;
    return tmp;
  } else {
    x->parent = root;   // Так как в эту ветку попадает только корень,
    y->parent = root;   // то мы "родителем" новых вершин делаем разделяющийся элемент.
    root->become_node2(root->key[1], x, y);
  }
}


template
class TTTree<int, int>;
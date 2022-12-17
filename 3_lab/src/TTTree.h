#pragma once

#include "Node.h"
#include "Iterator.h"
#include <sstream>

/*
2-3-дерево. Алгоритмы операций вставки, удаления и поиска реа-
лизуются в рекурсивной форме.

teenspirit:
    конструктор [ok]
    конструктор копирования

    деструктор [ok]
    insert [ok]
    remove [ok]
    printTree [ok]
    предусмотреть запрет на дупликацию ключей


badblues:
    меню ☑
    тестирование трудоемкости ☑
    рандомное заполнение на 10 элементов ☑
    выводить принт подробнее ☑
    size ☑
    clear ☑
    isEmpty ☑
    get ☑
    set ☑
    итероторы ☑
    меню для итераторов ☑
*/

using namespace std;

template<typename K, typename V>
class TTTree {
    public:
        TTTree();
        TTTree(const TTTree &copy);
        ~TTTree();
        Iterator<K, V> Begin();
        RIterator<K, V> RBegin();
        Iterator<K, V> End();
        RIterator<K, V> REnd();
        uint GetSize();
        void Clear();
        bool IsEmpty();
        V Get(K key);
        bool Set(K key, V value);
        bool Insert(K key, V value);
        bool Remove(K key);
        string ToString();
        bool Remove(Internal<K, V> *t, K k, Leaf<K, V> *&tlow1, bool &one_son);
        int CountNodes();
        bool Insert(Node<K, V> *t, Node<K, V> *lt, Node<K, V> *&tup, K &lup);
        void Copy(Internal<K, V> *t);
    private:
        Leaf<K,V>* Get(Internal<K,V>*, K);
        void Clear(Internal<K,V> *node);
        void ToString(Node<K,V>* t, int level, stringstream* ss);
        int nodes_counter = 0;
        uint size;
        Internal<K, V> *root;
        TTTree<K,V>*  tree;
};

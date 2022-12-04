#pragma once

#include "Node.h"
#include "Iterator.h"
#include "RIterator.h"

/*
2-3-дерево. Алгоритмы операций вставки, удаления и поиска реа-
лизуются в рекурсивной форме.

teenspirit:
    конструктор [ok]
    конструктор копирования
    деструктор [ok]
    insert [ok]
    remove
    printTree [ok]
    предусмотреть запрет на дупликацию ключей


badblues:
    меню
    тестирование трудоемкости
    size ☑
    clear ☑
    isEmpty ☑
    get ☑
    set ☑
    итероторы
    меню
    меню для итераторов
    CountNodes 
*/

using namespace std;

template<typename K, typename V>
class TTTree {
    public:
        TTTree();
        TTTree(const TTTree &copy);
        ~TTTree();
        uint GetSize();
        void Clear();
        bool IsEmpty();
        V Get(K key);
        bool Set(K key, V value);
        bool Insert(K key, V value);
        void Split();
        bool Remove(K key);
        bool Remove(Internal<K, V> *t, K k, Leaf<K, V> *&tlow1, bool &one_son);
        int CountNodes();
        bool Insert(Node<K, V> *t, Node<K, V> *lt, Node<K, V> *&tup, K &lup);

    private:
        Leaf<K,V>* Get(Internal<K,V>*, K);
        void Clear(Internal<K,V> *node);
        int nodes_counter = 0;
        uint size;
        Internal<K, V> *root;


};

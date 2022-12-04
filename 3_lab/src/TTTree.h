#pragma once

#include "Node.h"
#include "Iterator.h"
#include "RIterator.h"
#include <sstream>

/*
2-3-дерево. Алгоритмы операций вставки, удаления и поиска реа-
лизуются в рекурсивной форме.

teenspirit:
    конструктор
    конструктор копирования
    деструктор
    insert
    remove
    предусмотреть запрет на дупликацию ключей


badblues:
    меню ☑
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
        string ToString();
        int CountNodes();
        bool Insert(Node<K, V> *t, Node<K, V> *lt, Node<K, V> *&tup, K &lup);
    private:
        Leaf<K,V>* Get(Internal<K,V>*, K);
        void Clear(Internal<K,V> *node);
        void ToString(Node<K,V>* t, int level, stringstream* ss);
        int nodes_counter = 0;
        uint size;
        Internal<K, V> *root;

};

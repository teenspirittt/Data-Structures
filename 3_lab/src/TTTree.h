#pragma once

#include "Node.h"
#include "Iterator.h"
#include "RIterator.h"

/*
2-3-дерево. Алгоритмы операций вставки, удаления и поиска реа-
лизуются в рекурсивной форме.

teenspirit:
    конструктор
    конструктор копирования
    деструктор
    insert
    remove
    printTree
    предусмотреть запрет на дупликацию ключей


badblues:
    меню
    тестирование трудоемкости
    size
    clear
    isEmpty
    get
    set
    итероторы
    меню
    меню для итераторов
    CountNodes 
*/

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
        bool Remove(K key);
        int CountNodes();
    private:
        T Get(Internal*, K);
        int nodes_counter = 0;
        uint size;
        Node<K, V> *root;
};

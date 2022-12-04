
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
class BalancedTree {
    public:
        BSTree();
        BSTree(const BSTree &copy);
        ~BSTree();
        Iterator<K, V> begin();
        RIterator<K, V> rbegin();
        Iterator<K, V> end();
        RIterator<K, V> rend();
        uint getSize();
        void clear();
        bool isEmpty();
        V get(K key);
        bool set(K key, V value);
        bool insert(K key, V value);
        bool remove(K key);
        void printTree();
        void printTree(Node <K, V> *_root, int space);
        int CountNodes();

    private:
        int nodes_counter = 0;
        uint size;
        Node<K, V> *root;
}

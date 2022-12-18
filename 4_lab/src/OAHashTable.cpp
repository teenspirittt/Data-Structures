#include "OAHashTable.h"

using namespace std;

template<typename T>
OAHashTable<T>::OAHashTable() {
    this->capacity = default_size;
    this->size = 0;
    this->nodes = new OANode<T> *[this->capacity];
    for (int i = 0; i < this->capacity; ++i) {
        this->nodes[i] = new OANode<T>();
    }
}

template<typename T>
OAHashTable<T>::OAHashTable(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->nodes = new OANode<T> *[this->capacity];
    for (int i = 0; i < this->capacity; ++i) {
        this->nodes[i] = new OANode<T>();
    }
}


template<typename T>
OAHashTable<T>::~OAHashTable() {
    for (int i = 0; i < this->capacity; i++) {
        if (nodes[i] != NULL) {
            delete nodes[i];
        }
        nodes[i] = NULL;
    }

}


template<typename T>
bool OAHashTable<T>::Insert(string k, T data) {
    nodes_counter = 0;
    for (int i = 0; i < k.size(); i++)
        if (k[i] < 'A' || k[i] > 'Z')
            k = k.substr(0, i);
    if (k.size() == 0)
        return false;
    int i = 0;
    int pos = -1;
    int j = HashFunction(k, i);
    for (;i != this->capacity && !IsFree(j); i++) {
        nodes_counter++;
        j = HashFunction(k, i);
        if (pos == -1 && IsDeleted(j)) {
            pos = j;
        }
        if (IsBusy(j) && this->nodes[j]->key == k) {

            return false;
        }
    }
    if (i == this->capacity && pos == -1) {
        return false;
    }
    if (pos == -1) {
        pos = j;
    }

    this->nodes[pos]->key = k;
    this->nodes[pos]->value = data;
    this->nodes[pos]->state = states::busy_;
    this->size++;
    return true;
}

template<typename T>
T OAHashTable<T>::Get(string k) {
    nodes_counter = 0;
    int i = 0;
    int j;

    do {
        nodes_counter++;
        j = HashFunction(k, i);
        if (IsBusy(j) && this->nodes[j]->key == k) {
            return this->nodes[j]->value;
        }
        i++;
    } while (i != this->capacity || !IsFree(j));

    throw "not found!";
}

template<typename T>
bool OAHashTable<T>::Remove(string k) {
    nodes_counter = 0;
    int i = 0;
    int j;
    do {
        nodes_counter++;
        j = HashFunction(k, i);
        if (IsBusy(j) && this->nodes[j]->key == k) {
            this->nodes[j]->state = states::deleted_;
            this->size--;
            return true;
        }
        i++;
    } while (i != this->capacity || !IsFree(j));
    return false;
}


template<typename T>
int OAHashTable<T>::HashFunction(string str, int i) {
    return (HornerFunction(str) + i) % this->capacity;
}

template<typename T>
int OAHashTable<T>::HornerFunction(string str) {
    unsigned k = 0;
    for (unsigned i = 0; i < str.size(); ++i) {
        k += pow(26, str.size() - 1 - i) * (str.at(i) - 'A' + 1);
    }

    double g_r = 0.6180339887;

    double X = g_r * k;
    X = X - (unsigned) X;
    return (unsigned) (X * this->capacity);

}


template<typename T>
bool OAHashTable<T>::IsDeleted(int j) const {
    return this->nodes[j]->state == states::deleted_;
}

template<typename T>
bool OAHashTable<T>::IsBusy(int j) const {
    return this->nodes[j]->state == states::busy_;
}

template<typename T>
bool OAHashTable<T>::IsFree(int j) const {
    return this->nodes[j]->state == states::free_;
}


template<typename T>
int OAHashTable<T>::GetSize() const {
    return size;
}

template<typename T>
int OAHashTable<T>::GetCapacity() const {
    return capacity;
}

template<typename T>
bool OAHashTable<T>::IsEmpty() {
    return size == 0;
}

template<typename T>
bool OAHashTable<T>::Clear() {
    for (int i = 0; i < this->capacity; ++i) {
        if (this->nodes[i]->state == states::busy_)
            this->nodes[i]->state = states::deleted_;
    }
    return true;
}


template<typename T>
string OAHashTable<T>::ToString() {
    stringstream* sstr = new stringstream();
    cout << "0 = FREE; 1 = BUSY; 2 = DELETED\n";
    for (int i = 0; i < this->capacity; ++i) {
        if (IsBusy(i)) {
            *sstr << i << ": [" << this->nodes[i]->key << "," << this->nodes[i]->value
            << "](" << this->nodes[i]->state << ")\n";
        } else {
            *sstr << i << ": (" << this->nodes[i]->state << ")\n";
        }
    }
    return sstr->str();
}

template
class OAHashTable<int>;

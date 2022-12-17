#pragma once

#include "OAHashTable.h"
#include "CCHashTable.h"

template<typename T>
class HashTable {

    public:

        HashTable(int capacity) {
            cc = true;
            oatable = new OAHashTable<T>();
            cctable = new CCHashTable<T>(capacity);
        }

        ~HashTable() {}

        bool Insert(string k, T data) {
            return cc ? cctable->Insert(k, data) : oatable->Insert(k, data);
        }

        bool Remove(string k) {
            return cc ? cctable->Remove(k) : oatable->Remove(k);
        }

        T Get(string k) {
            return cc ? cctable->Get(k) : oatable->Get(k);
        }

        bool IsEmpty() {
            return cc ? cctable->IsEmpty() : oatable->IsEmpty();
        }

        int GetSize() const {
            return cc ? cctable->GetSize() : oatable->GetSize();
        }

        int GetCapacity() const {
            return cc ? cctable->GetCapacity() : oatable->GetCapacity();
        }

        void Clear() {
            //return cc ? cctable->Clear() : oatable->Clear();
        }

        void SetForm(bool cc) {
            this->cc = cc;
        } 

        bool IsCC() {
            return cc;
        }

        string ToString() {
            return cc ? cctable->ToString() : oatable->ToString();
        }

    private:

    OAHashTable<T>* oatable;
    CCHashTable<T>* cctable;
    bool cc;
};
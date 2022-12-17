#include <iostream>
#include "src/HashTable.h"


using namespace std;

int main() {
    /*OAHashTable<int> hashTable;
    hashTable.Insert("ALPHA", 10);
    hashTable.Insert("BETA", 10);
    hashTable.Insert("GAMMA", 10);
    hashTable.Insert("EPSILON", 10);

    hashTable.ToString();
    cout << hashTable.GetSize() << endl;

    auto it = hashTable.begin();
    while (it != hashTable.end()) {
        cout << it.showkey() << endl;
        it.next();
    }*/

    HashTable<int> table(8);
    table.SetForm(false);
    cout << table.GetSize() << endl;
    table.Insert("ALPHA", 10);
    cout << table.GetSize() << endl;

    table.Insert("BETA", 10);
    cout << table.GetSize() << endl;

    table.Insert("GAMMA", 10);
    cout << table.GetSize() << endl;

    table.Insert("EPSILON", 10);
    cout << table.GetSize() << endl;

    // auto it = table.begin();
    // while (it != table.end()) {
    //     cout << it.showkey() << endl;
    //     it.next();
    // }

    table.Remove("BETA");
    cout << table.GetSize() << endl;


    cout << table.ToString();

    table.Remove("GAMMA");
    cout << table.GetSize() << endl;



    cout << table.ToString();

    return 0;
}
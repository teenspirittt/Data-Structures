#include "menu.h"
#include <stdlib.h>
#include <time.h> 

#ifdef __linux__
#define clear_console_ "clear"
#else
#define clear_console_ "cls"
#endif

using namespace std;

int GetNumber(int l_gap, int h_gap, const char* msg) {
    int number;
    cout << msg;
    while (true) {
        cin >> number;
        if ((number >= l_gap) && (number <= h_gap) && (cin.peek() == '\n')) 
            break;
        else {
            cout << "INVALID INPUT\n";
            cin.clear();
            while (cin.get() != '\n') {
            }
        }
    }
    cin.get();
    return number;
}

void ShowMainMenu() {
  cout << "\n===================\n"
          "    MENU:\n"
          "  1 ADD ELEMENT\n"
          "  2 REMOVE ELEMENT\n"
          "  3 GET BY KEY\n"
          "  4 GET CAPACITY\n"
          "  5 CLEAR\n"
          "  6 GET SIZE\n"
          "  7 IS EMPTY\n"
          "  8 NUMBER OF COUNTED NODES\n"
          "  9 TEST ITERATOR\n"
          " 10 FORM\n"
          " 11 CHANGE FORM\n"
          " 12 INSERT 10\n"
          "  0 EXIT\n"
          "===================\n";
}


void MainMenu() {
  int choice;
  int pos;
  uint list_size;
  bool flag = true;
  bool iterator_flag = false;
  bool cl_flag = true;
  string str;
  int val, val2;
  string key;
   HashTable<int>* table;

  cout << "1 - COLLISION LIST\n2 - OPEN ADDRESSING\n";
  val = GetNumber(1, 2, "");
  
  val2 = GetNumber(2, INT32_MAX, "ENTER TABLE SIZE:\n");
  if (val == 1)
   table = new HashTable<int>(val2, true);
  else
    table = new HashTable<int>(val2, false);

  while (flag) {
    system(clear_console_);
    cout << table->ToString();
    ShowMainMenu();
    choice = GetNumber(0, 12, "");
    switch (choice) {
      case 1: { // add element
        cout << "ENTER KEY (LATIN UPPERCASE STRING):\n";
        cin >> key;
        val = GetNumber(INT32_MIN, INT32_MAX, "ENTER VALUE:\n");
        table->Insert(key, val);
        break;
      }
      case 2: { // remove element
        cout << "ENTER KEY (LATIN UPPERCASE STRING):\n";
        cin >> key;
        if (table->Remove(key))
          cout << "DONE!\n";
        else 
          cout << "FAIL!\n";
        break;
      }
      case 3: { // get by key
        cout << "ENTER KEY (LATIN UPPERCASE STRING):\n";
        cin >> key;
        try {
          cout << table->Get(key) << "\n";
        } catch (...) {
          cout << "NOT FOUND\n";
        }
        cin.get();
        break;
      }
      case 4: { // set by key
        cout << table->GetCapacity() << "\n";
        cin.get();
        break;
      }
      case 5: { // clear
        table->Clear();
        cin.get();
        break;
      }
      case 6: { // get size
        cout << table->GetSize() << "\n";
        cin.get();
        break;
      }
      case 7: { // isempty
        cout << table->IsEmpty() << "\n";
        cin.get();
        break;
      }
      case 8: { // count nodes
        cout << table->CountNodes() << "\n";
        cin.get();
        break;
      }
      case 9: { // iterator
        iterator_flag = true;
        HashTable<int>::Iterator iter(table);
        while(iterator_flag) {
          system(clear_console_);
          cout << table->ToString();
          cout << "  1 BEGIN\n  2 ++\n  3 *\n  0 EXIT\n";
          choice = GetNumber(0, 3, "");
          switch(choice) {
            case 1: {
              iter = table->Begin();
              break;
            }
            case 2: {
              ++iter;
              break;
            }
            case 3: {
              if (iter != table->End())
                cout << "[" << **iter << "]\n";
              else
                cout << "LOST ITERATOR\n";
              cin.get();
              break;
            }
            case 0: {
              iterator_flag = false;
              break;
            }
          }
        }
        break;
      }
      case 10: {
        if (table->IsCL())
            cout << "FORM: COLLISION LIST\n";
        else
            cout << "FORM: OPEN ADDRESSING TABLE\n";
        cin.get();
        break;
      }
      case 11: {
        table->ChangeForm();
        break;
      }
      case 12: {
        srand (time(NULL));
        string str;
        for (int i = 0; i < 10; i++) {
          for (int i = 0; i < 5; i++)
            str += 'A' + rand() % 26;
          table->Insert(str, rand() % 100);
          str = "";
        }
        cout << "DONE!";
        cin.get();
        break;
      }
      case 0:
        flag = false;
        break;
    }
  }
}
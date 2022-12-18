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
  int val;
  string key;

  val = GetNumber(2, INT32_MAX, "ENTER COLLISION LIST SIZE:\n");
  CLHashTable<int> cltable(val);
  val = GetNumber(2, INT32_MAX, "ENTER OPEN ADDRESSING TABLE SIZE:\n");
  OAHashTable<int> oatable(val);

  while (flag) {
    system(clear_console_);
    if (cl_flag)
        cout << cltable.ToString();
    else
        cout << oatable.ToString();
    ShowMainMenu();
    choice = GetNumber(0, 12, "");
    switch (choice) {
      case 1: { // add element
        cout << "ENTER KEY (LATIN UPPERCASE STRING):\n";
        cin >> key;
        val = GetNumber(INT32_MIN, INT32_MAX, "ENTER VALUE:\n");
        cltable.Insert(key, val);
        oatable.Insert(key, val);
        break;
      }
      case 2: { // remove element
        cout << "ENTER KEY (LATIN UPPERCASE STRING):\n";
        cin >> key;
        if (cltable.Remove(key) && oatable.Remove(key))
          cout << "DONE!\n";
        else 
          cout << "FAIL!\n";
        break;
      }
      case 3: { // get by key
        cout << "ENTER KEY (LATIN UPPERCASE STRING):\n";
        cin >> key;
        try {
          if (cl_flag)
              cout << cltable.Get(key) << "\n";
          else
              cout << oatable.Get(key) << "\n";
        } catch (...) {
          cout << "NOT FOUND\n";
        }
        cin.get();
        break;
      }
      case 4: { // set by key
        if (cl_flag)
            cout << cltable.GetCapacity() << "\n";
        else
            cout << oatable.GetCapacity() << "\n";
        cin.get();
        break;
      }
      case 5: { // clear
        oatable.Clear();
        cltable.Clear();
        cin.get();
        break;
      }
      case 6: { // get size
        if (cl_flag)
            cout << cltable.GetSize() << "\n";
        else
            cout << oatable.GetSize() << "\n";
        cin.get();
        break;
      }
      case 7: { // isempty
        if (cl_flag)
            cout << cltable.IsEmpty() << "\n";
        else
            cout << oatable.IsEmpty() << "\n";
        cin.get();
        break;
      }
      case 8: { // count nodes
        if (cl_flag)
            cout << cltable.CountNodes() << "\n";
        else
            cout << oatable.CountNodes() << "\n";
        cin.get();
        break;
      }
      case 9: { // iterator
        iterator_flag = true;
        CLHashTable<int>::Iterator cliter = cltable.Begin();
        OAHashTable<int>::Iterator oaiter = oatable.Begin();
        while(cl_flag && iterator_flag) {
          system(clear_console_);
          cout << cltable.ToString();
          cout << "  1 BEGIN\n  2 Next\n  3 *\n  0 EXIT\n";
          choice = GetNumber(0, 3, "");
          switch(choice) {
            case 1: {
              cliter = cltable.Begin();
              break;
            }
            case 2: {
              cliter.next();
              break;
            }
            case 3: {
              if (cliter != cltable.End())
                cout << "[" << **cliter << "]\n";
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
        while(!cl_flag && iterator_flag) {
          system(clear_console_);
          cout << oatable.ToString();
          cout << "  1 BEGIN\n  2 Next\n  3 *\n  0 EXIT\n";
          choice = GetNumber(0, 3, "");
          switch(choice) {
            case 1: {
              oaiter = oatable.Begin();
              break;
            }
            case 2: {
              oaiter.next();
              break;
            }
            case 3: {
              if (oaiter != oatable.End())
                cout << "[" << **oaiter << "]\n";
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
        if (cl_flag)
            cout << "FORM: COLLISION LIST\n";
        else
            cout << "FORM: OPEN ADDRESSING TABLE\n";
        cin.get();
        break;
      }
      case 11: {
        val = GetNumber(1, 2, "1 - COLLISION LIST\n2 - OPEN ADDRESSING\n");
        if (val == 1)
            cl_flag = true;
        else
            cl_flag = false;
        break;
      }
      case 12: {
        srand (time(NULL));
        string str;
        for (int i = 0; i < 10; i++) {
          for (int i = 0; i < 5; i++)
            str += 'A' + rand() % 26;
          oatable.Insert(str, rand() % 100);
          cltable.Insert(str, rand() % 100);
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
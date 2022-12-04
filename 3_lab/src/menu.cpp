#include "menu.h"

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
          "  4 SET BY KEY\n"
          "  5 CLEAR\n"
          "  6 GET SIZE\n"
          "  7 IS EMPTY\n"
          "  8 COUNT NODES\n"
          "  9 TEST ITERATOR\n"
          " 10 TEST REVERSED ITERATOR\n"
          "  0 EXIT\n"
          "===================\n";
}


void MainMenu() {
  int choice;
  int pos;
  uint list_size;
  bool flag = true;
  bool iterator_flag = false;
  string str;
  int val;
  int key;

  TTTree<int, int> tree;

  while (flag) {
    system(clear_console_);
    //tree.printTree();
    ShowMainMenu();
    choice = GetNumber(0, 11, "");
    switch (choice) {
      case 1: { // add element
        // key = GetNumber(INT32_MIN, INT32_MAX, "ENTER KEY:\n");
        // val = GetNumber(INT32_MIN, INT32_MAX, "ENTER VALUE:\n");
        // tree.insert(key, val);
        break;
      }
      case 2: { // remove element
        // key = GetNumber(INT32_MIN, INT32_MAX, "ENTER KEY:\n");
        // if (tree.remove(key))
        //   cout << "DONE!\n";
        // else 
        //   cout << "FAIL!\n";
        break;
      }
      case 3: { // get by key
        // key = GetNumber(INT32_MIN, INT32_MAX, "ENTER KEY:\n");
        // cout << tree.get(key) << "\n";
        // cin.get();
        break;
      }
      case 4: { // set by key
        // key = GetNumber(INT32_MIN, INT32_MAX, "ENTER KEY:\n");
        // val = GetNumber(INT32_MIN, INT32_MAX, "ENTER VALUE:\n");
        // if (tree.set(key, val))
        //   cout << "DONE!\n";
        // else 
        //   cout << "FAIL!\n";
        // cin.get();
        break;
      }
      case 5: { // clear
        // tree.clear();
        // cin.get();
        break;
      }
      case 6: { // get size
        // cout << tree.getSize();
        // cin.get();
        break;
      }
      case 7: { // isempty
        // cout << tree.isEmpty();
        // cin.get();
        break;
      }
      case 8: { // count nodes
        // cout << tree.CountNodes();
        // cin.get();
        break;
      }
      case 9: { // iterator
        // iterator_flag = true;
        // Iterator<int, int> iter = tree.begin();
        // while(iterator_flag) {
        //   system(clear_console_);
        //   tree.printTree();
        //   cout << "  1 BEGIN\n  2 ++\n  3--\n  4 *\n  0 EXIT\n";
        //   choice = GetNumber(0, 4, "");
        //   switch(choice) {
        //     case 1: {
        //       iter = tree.begin();
        //       break;
        //     }
        //     case 2: {
        //       ++iter;
        //       break;
        //     }
        //     case 3: {
        //       if (iter != tree.begin())
        //       --iter;
        //       break;
        //     }
        //     case 4: {
        //       if (iter != tree.end())
        //         cout << "[" << (*iter)->key << "," << (*iter)->value << "]\n";
        //       else
        //         cout << "LOST ITERATOR\n";
        //       cin.get();
        //       break;
        //     }
        //     case 0: {
        //       iterator_flag = false;
        //       break;
        //     }
        //   }
        // }
        break;
      }
      case 10: { // reversed iterator
        // iterator_flag = true;
        // RIterator<int, int> iter = tree.rbegin();
        // while(iterator_flag) {
        //   system(clear_console_);
        //   tree.printTree();
        //   cout << "  1 BEGIN\n  2 ++\n  3 --\n  4 *\n  0 EXIT\n";
        //   choice = GetNumber(0, 4, "");
        //   switch(choice) {
        //     case 1: {
        //       iter = tree.rbegin();
        //       break;
        //     }
        //     case 2: {
        //       ++iter;
        //       break;
        //     }
        //     case 3: {
        //       if (iter != tree.rbegin())
        //         --iter;
        //       break;
        //     }
        //     case 4: {
        //       if (iter != tree.rend())
        //         cout << "[" << (*iter)->key << "," << (*iter)->value << "]\n";
        //       else
        //         cout << "LOST ITERATOR\n";
        //       cin.get();
        //       break;
        //     }
        //     case 0: {
        //       iterator_flag = false;
        //       break;
        //     }
        //   }
        // }
        break;
      }
      case 0:
        flag = false;
        break;
    }
  }
}
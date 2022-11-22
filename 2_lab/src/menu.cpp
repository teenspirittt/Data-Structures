#include "../headers/menu.h"

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
          "  6 PRINT KEYS\n"
          "  7 GET SIZE\n"
          "  8 IS EMPTY\n"
          "  9 COUNT NODES\n"
          " 10 TEST ITERATOR\n"
          " 11 TEST REVERSED ITERATOR\n"
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

  BSTree<int, int> tree;

  while (flag) {
    system(clear_console_);
    tree.printTree();
    ShowMainMenu();
    choice = GetNumber(0, 11, "");
    switch (choice) {
      case 1: { // add element
        key = GetNumber(INT16_MIN, INT16_MAX, "ENTER KEY:\n");
        val = GetNumber(INT16_MIN, INT16_MAX, "ENTER VALUE:\n");
        tree.insert(key, val);
        break;
      }
      case 2: { // remove element
        key = GetNumber(INT16_MIN, INT16_MAX, "ENTER KEY:\n");
        if (tree.remove(key))
          cout << "DONE!\n";
        else 
          cout << "FAIL!\n";
        break;
      }
      case 3: { // get by key
        key = GetNumber(INT16_MIN, INT16_MAX, "ENTER KEY:\n");
        cout << tree.get(key) << "\n";
        cin.get();
        break;
      }
      case 4: { // set by key
        key = GetNumber(INT16_MIN, INT16_MAX, "ENTER KEY:\n");
        val = GetNumber(INT16_MIN, INT16_MAX, "ENTER VALUE:\n");
        if (tree.set(key, val))
          cout << "DONE!\n";
        else 
          cout << "FAIL!\n";
        cin.get();
        break;
      }
      case 5: { // clear
        tree.clear();
        cin.get();
        break;
      }
      case 6: { //  print keys
        cout << tree.printKeys();
        cin.get();
        break;
      }
      case 7: { // get size
        cout << tree.getSize();
        cin.get();
        break;
      }
      case 8: { // isempty
        cout << tree.isEmpty();
        cin.get();
        break;
      }
      case 9: { // count nodes
        cout << tree.CountNodes();
        cin.get();
        break;
      }
      case 10: { // iterator
        iterator_flag = true;
        Iterator<int, int> iter = tree.begin();
        while(iterator_flag) {
          system(clear_console_);
          tree.printTree();
          cout << "  1 BEGIN\n  2 END\n  3 ++\n  4 --\n  5 *\n  0 EXIT\n";
          choice = GetNumber(0, 5, "");
          switch(choice) {
            case 1: {
              iter = tree.begin();
              break;
            }
            case 2: {
              iter = tree.end();
              break;
            }
            case 3: {
              if (iter!= tree.end())
                ++iter;
              break;
            }
            case 4: {
              if (iter != tree.begin())
              --iter;
              break;
            }
            case 5: {
              cout << "[" << (*iter)->key << "," << (*iter)->value << "]\n";
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
      case 11: { // reversed iterator
        iterator_flag = true;
        RIterator<int, int> iter = tree.rbegin();
        while(iterator_flag) {
          system(clear_console_);
          tree.printTree();
          cout << "  1 BEGIN\n  2 END\n  3 ++\n  4 --\n  5 *\n  0 EXIT\n";
          choice = GetNumber(0, 5, "");
          switch(choice) {
            case 1: {
              iter = tree.rbegin();
              break;
            }
            case 2: {
              iter = tree.rend();
              break;
            }
            case 3: {
              if (iter!= tree.rend())
                ++iter;
              break;
            }
            case 4: {
              if (iter != tree.rbegin())
              --iter;
              break;
            }
            case 5: {
              cout << "[" << (*iter)->key << "," << (*iter)->value << "]\n";
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
      case 0:
        flag = false;
        break;
    }
  }
}
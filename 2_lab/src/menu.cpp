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
          "  0 EXIT\n"
          "===================\n";
}

void ShowTree(BSTree<int, int> tree) {
  tree.printTree();
}


void MainMenu() {
  int choice;
  int pos;
  uint list_size;
  bool flag = true;
  string str;
  int val;
  int key;

  BSTree<int, int> tree;

  while (flag) {
    system(clear_console_);
    cout <<"huy";
    tree.printTree();
    ShowMainMenu();
    choice = GetNumber(0, 13, "");
    switch (choice) {
      case 1: { // add element
        val = GetNumber(INT16_MIN, INT16_MAX, "ENTER VALUE:\n");
        key = GetNumber(INT16_MIN, INT16_MAX, "ENTER KEY:\n");
        tree.insert(val, key);
        break;
      }
      case 2: { // remove element
       /* key = GetNumber(INT16_MIN, INT16_MAX, "ENTER KEY:\n");
        tree.remove(key);*/
        break;
      }
      case 3: { // get by key
        key = GetNumber(INT16_MIN, INT16_MAX, "ENTER KEY:\n");
        cout << tree.get(key) << "\n";
        cin.get();
        break;
      }
      case 4: { // set by key
        val = GetNumber(INT16_MIN, INT16_MAX, "ENTER VALUE:\n");
        key = GetNumber(INT16_MIN, INT16_MAX, "ENTER KEY:\n");
        tree.set(val, key);
        break;
      }
      case 5: { // clear
        tree.clear();
        break;
      }
      case 6: { //  print keys
        tree.printKeys();
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

      case 0:
        flag = false;
        break;
    }
  }
}
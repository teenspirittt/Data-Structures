#include "menu.h"

#ifdef __linux__
#define clear_console_ "clear"
#else
#define clear_console_ "cls"
#endif

uint GetChoice(uint l_gap, uint h_gap, const char* msg) {
  uint num;
  do {
    cout << msg;
    cin >> num;
  } while ((num < l_gap) || (num > h_gap));
  return num;
}

void ShowMainMenu() {
  cout << "\n===================\n"
          "MENU\n"
          "  1 ADD ELEMENT\n"
          "  2 INSERT ELEMENT\n"
          "  3 REMOVE ELEMENT\n"
          "  4 ORDERED ADD\n"
          "  5 ORDERED INSERT\n"
          "  0 EXIT\n"
          "===================\n";
}

void MainMenu( &object) {
  int choice;
  uint selected_elem;
  bool flag = true;
  string* str;
  while (flag) {
    system(clear_console_);
    ShowMainMenu();
    choice = GetChoice(0, 15, "");
    switch (choice) {
      case 0:
      flag = false;
      break;
    }
  }
}
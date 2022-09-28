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
          //temporary names, must be changed
          "MENU\n"
          "   ADD ELEMENT\n"
          "   INSERT ELEMENT\n"
          "   REMOVE ELEMENT\n"
          "   ORDERED ADD\n"
          "   ORDERED INSERT\n"
          "   LIST SIZE\n"
          "   CLEAR LIST\n"
          "   IS EMPTY\n"
          "   CHECK FOR VALUE\n"
          "   ORDERED INSERT\n"
          "   READ BY INDEX\n"
          "   UPDATE BY INTEX\n"
          "   GET INDEX OF VALUE\n"
          "   ADD VALUE\n"
          "   ADD VALUE BY INDEX\n"
          "   REMOVE VALUE\n"
          "   RENOVE VALUE BY INDEX\n"
          //"запрос числа элементов списка просмотренных предыдущей операцией"
          "   GET NUMBER OF ELEMENTS LOOKED\n"
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
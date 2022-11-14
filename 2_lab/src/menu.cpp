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
          "  0 EXIT\n"
          "===================\n";
}


void AskForDataType(bool &isTypeInt) {
  char c;
  do {
    cout << "\nWHAT DATA TYPE TO USE (INT/STRING)? I/S\n";
    cin >> c;
    if (c == 'S' || c == 's')
      isTypeInt = false;
  } while (c != 'S' && c != 's' && c != 'I' && c != 'i');
}

void MainMenu() {
  int choice;
  int pos;
  uint list_size;
  bool flag = true;
  bool iter_flag = true;
  string str;
  int val;
  bool isTypeInt = true;
  
  AskForDataType(isTypeInt);
    

  while (flag) {
    system(clear_console_);
    ShowMainMenu();
    choice = GetNumber(0, 13, "");
    switch (choice) {
      case 0:
        flag = false;
        break;
    }
  }
}
#include "../headers/menu.h"

#ifdef __linux__
#define clear_console_ "clear"
#else
#define clear_console_ "cls"
#endif

int GetNumber(int l_gap, int h_gap, const char* msg) {
    int number;
    cout << msg;
    while (true) {
        cin >> number;
        if ((number >= l_gap) && (number <= h_gap) && (cin.peek() == '\n')) 
            break;
        else {
            cout << "ENTER VALID VALUE\n";
            cin.clear();
            while (cin.get() != '\n') {
            }
        }
    }
    return number;
}

void ShowMainMenu() {
  cout << "\n===================\n"
          //temporary names, must be changed
          "MENU\n"
          " 1 ADD ELEMENT\n"
          " 2 INSERT ELEMENT\n"
          " 3 REMOVE ELEMENT\n"
          " 4 ORDERED ADD\n"
          " 5 ORDERED INSERT\n"
          " 6 LIST SIZE\n"
          " 7 CLEAR LIST\n"
          " 8 IS EMPTY\n"
          //опрос наличия заданного значения
          " 9 CHECK FOR VALUE\n"
          " 10 READ BY INDEX\n"
          " 11 UPDATE BY INDEX\n"
          " 12 GET INDEX OF VALUE\n"
          // "   ADD VALUE\n"
          // "   ADD VALUE BY INDEX\n"
          // "   REMOVE VALUE\n"
          // "   RENOVE VALUE BY INDEX\n"
          // //"запрос числа элементов списка просмотренных предыдущей операцией"
          // "   GET NUMBER OF ELEMENTS LOOKED\n"
          "  0 EXIT\n"
          "===================\n";
}

template<typename T>
void ShowList(CycList<T>* obj) {
  cout << "\n" << *obj;
}

bool AskForDataType(bool &isTypeInt) {
  cout << "DO YOU WANT DATA TYPE AS INT? Y/N (OTHERWISE IT WILL BE STRING)\n";
  char c;
  cin >> c;
  if (c == 'N')
    isTypeInt = false;
  else if (c != 'Y')
    return false;
  return true;
}

void MainMenu() {
  int choice;
  uint selected_elem;
  bool flag = true;
  string* str;
  bool isTypeInt = true;
  
  if (!AskForDataType(isTypeInt))
    flag = false;

  CycList<int> intObject;
  CycList<string> stringObject;

  while (flag) {
    system(clear_console_);
    if (isTypeInt)
      ShowList(&intObject);
    else
      ShowList(&stringObject);
    ShowMainMenu();
    choice = GetNumber(0, 12, "");
    switch (choice) {
      case 0:
        flag = false;
        break;
      case 1:
        system(clear_console_);
        if (isTypeInt) {
          int val = GetNumber(INT_MIN, INT_MAX, "ENTER VALUE\n");
          intObject.addValue(val);
        } else {
          string str;
          cin >> str;
          stringObject.addValue(str);
        }
      break;
        case 2:
      break;
        case 3:
      break;
        case 4:
      break;
        case 5:
      break;
        case 6:
      break;
        case 7:
      break;
        case 8:
      break;
        case 9:
      break;
        case 10:
      break;
        case 11:
      break;
        case 12:
      break;
    }
  }
}
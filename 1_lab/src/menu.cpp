#include "../headers/menu.h"

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
  std::cout << "\n" << *obj;
}

bool AskForDataType(bool &isTypeInt) {
  std::cout << "DO YOU WANT DATA TYPE AS INT? Y/N (OTHERWISE IT WILL BE STRING)\n";
  char c;
  std::cin >> c;
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
  bool isTypeInt;
  
  if (!AskForDataType(isTypeInt))
    flag = false;

  
  
  if (isTypeInt)
   CycList<int> intObject = new CycList<int>();
  else
    CycList<string> stringObject = new CycList<string>();

  while (flag) {
    system(clear_console_);
    ShowList(&object);
    ShowMainMenu();
    choice = GetChoice(0, 12, "");
    switch (choice) {
      case 0:
        flag = false;
        break;
      case 1:
        system(clear_console_);
        std::cout << "ENTER VALUE\n";
        if (isTypeInt) {
          
        }
        //object.addValue();

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
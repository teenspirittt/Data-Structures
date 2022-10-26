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
          " 1  ADD ELEMENT\n"
          " 2  INSERT ELEMENT\n"
          " 3  REMOVE BY VALUE\n"
          " 4  REMOVE BY INDEX\n"
          " 5  LIST SIZE\n"
          " 6  CLEAR LIST\n"
          " 7  IS EMPTY\n"
          " 8  CHECK FOR ELEMENT\n"
          " 9  READ BY INDEX\n"
          " 10 EDIT BY INDEX\n"
          " 11 GET INDEX OF ELEMENT\n"
          " 12 TEST ITERATORS\n"
          " 13 GET NUMBER OF ELEMENTS LOOKED\n"
          "  0 EXIT\n"
          "===================\n";
}

template<typename T>
void ShowList(CycList<T>* obj) {
  cout << "List: ["<< *obj << "]\n";
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
    
  CycList<int> intObject;
  CycList<string> stringObject;

  while (flag) {
    system(clear_console_);
    if (isTypeInt)
      ShowList(&intObject);
    else
      ShowList(&stringObject);
    ShowMainMenu();
    choice = GetNumber(0, 13, "");
    switch (choice) {
      case 0:
        flag = false;
        break;
      case 1: // add
        if (isTypeInt) {
          val = GetNumber(INT16_MIN, INT16_MAX, "ENTER VALUE:\n");
          intObject.addValue(val);
        } else {
          cout << "ENTER STRING:\n";
          cin >> str;
          stringObject.addValue(str);
        }
        break;
      case 2: { // insert
        list_size = isTypeInt ? intObject.getSize() : stringObject.getSize();
        if (list_size == 0) list_size = 1;
        pos = GetNumber(0, list_size,"ENTER POSITION:\n");
        if (isTypeInt) {
          val = GetNumber(INT16_MIN, INT16_MAX, "ENTER VALUE:\n");
          intObject.insertValue(pos, val);
        } else {
          cout << "ENTER STRING\n";
          cin >> str;
          stringObject.insertValue(pos, str);
        } 
        cin.get();
        break;
      }
      case 3: { // remove by val
        if (isTypeInt) {
          val = GetNumber(INT16_MIN, INT16_MAX, "ENTER VALUE:\n");
          intObject.removeValue(val);
        } else {
          cout << "ENTER STRING\n";
          cin >> str;
          stringObject.removeValue(str);
        }
        break;
      }
      case 4: { // remove by index
        list_size = isTypeInt ? intObject.getSize() : stringObject.getSize();
        if (list_size == 0) {
          cout << "LIST IS EMPTY\n";
          continue;
        }
        pos = GetNumber(0, list_size - 1,"ENTER POSITION:\n");
        isTypeInt ? intObject.removeValueByIndex(pos) : stringObject.removeValueByIndex(pos);
        break;
      }
      case 5: { // list size
        list_size = isTypeInt ? intObject.getSize() : stringObject.getSize();
        cout << "SIZE = " << list_size << "\n";
        cin.get();
        break;
      }
      case 6: { // clear
        isTypeInt ? intObject.clear() : stringObject.clear();
        break;
      }
      case 7: { // isempty
        bool isempty = isTypeInt ? intObject.isEmpty() : stringObject.isEmpty();
        cout << "isEmpty = " << isempty << "\n"; 
        cin.get();
        break;
      }
      case 8: { // check for
        bool res;
        if (isTypeInt) {
          val = GetNumber(INT16_MIN, INT16_MAX, "ENTER VALUE:\n");
          res = intObject.isExistValue(val);
        } else {
          cout << "ENTER STRING:\n";
          cin >> str;
          res = stringObject.isExistValue(str);
        }
        res ? cout << "VALUE EXISTS\n" : cout << "VALUE DOESN'T EXIST\n";
        cin.get();
        cin.get();
        break;
      }
      case 9: { // read by index
        list_size = isTypeInt ? intObject.getSize() : stringObject.getSize();
        if (list_size == 0) {
          cout << "LIST IS EMPTY\n";
          continue;
        }
        pos = GetNumber(0, list_size - 1,"ENTER POSITION:\n");
        if (isTypeInt) {
          cout << "ELEMENT: " << intObject.getByIndex(pos) << "\n";
        } else {
          cout << "ELEMENT: " << stringObject.getByIndex(pos) << "\n";
        }
        cin.get();
        break;
      }
      case 10: { // update by index
        list_size = isTypeInt ? intObject.getSize() : stringObject.getSize();
        if (list_size == 0) {
          cout << "LIST IS EMPTY\n";
          continue;
        }
        pos = GetNumber(0, list_size - 1,"ENTER POSITION:\n");
        if (isTypeInt) {
          val = GetNumber(INT16_MIN, INT16_MAX, "ENTER VALUE:\n");
          intObject.editValue(pos, val);
        } else {
          cout << "ENTER STRING:\n";
          cin >> str;
          stringObject.editValue(pos, str);
        }
        break;
      }
      case 11: { // get index by element
        if (isTypeInt) {
          val = GetNumber(INT16_MIN, INT16_MAX, "ENTER VALUE:\n");
          pos = intObject.getIndex(val);
        } else {
          cout << "ENTER STRING:\n";
          cin >> str;
          pos = stringObject.getIndex(str);
        }
        cout << "POS = " << pos << "\n";
        cin.get();
        break;
      }
      case 12: { // test iterators
        CycList<int>::Iterator intIter = CycList<int>::Iterator(&intObject);
        CycList<string>::Iterator stringIter = CycList<string>::Iterator(&stringObject);
        iter_flag = true;
        while (iter_flag) {
          system(clear_console_);
          isTypeInt ? ShowList(&intObject) : ShowList(&stringObject);
          cout << "1 = SET ITERATOR\n2 = ++\n3 = *\n0 = EXIT\n";
          choice = GetNumber(0, 3, "");
          if (isTypeInt) {
            switch(choice) {
                case 1: {
                  intIter = CycList<int>::Iterator(&intObject);
                  cout << "SET\n";
                  cin.get();
                  break;
                }
                case 2: {
                  intIter++;
                  break;
                }
                case 3: {
                  cout << "iter* = " << *intIter << "\n";
                  cin.get();
                  break;
                }
                case 0: {
                  iter_flag = false;
                  break;
                }
            }  
          }
          else {
            switch(choice) {
                 case 1: {
                  stringIter = CycList<string>::Iterator(&stringObject);
                  cout << "SET\n";
                  break;
                }
                case 2: {
                  stringIter++;
                  cout << "++\n";
                  break;
                }
                case 3: {
                  cout << "iter* = " << *stringIter << "\n";
                  cin.get();
                  break;
                }
                case 0: {
                  iter_flag = false;
                  break;
                }
            }  
          }
        }
        break;
      }
      case 13: { // get number of looked elements
        if (isTypeInt) {
          cout << "NUM = " << intObject.getLookedElemCount() << "\n";
        } else {
          cout << "NUM = " << stringObject.getLookedElemCount() << "\n";
        }
        cin.get();
        break;
      }
    }
  }
}
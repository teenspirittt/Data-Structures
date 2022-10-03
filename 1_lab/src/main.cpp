#include "../headers/menu.h"

/* TODO :
  teenspirit list:
    copy constructor
    getLookedElemCount();
    editValue();
    CycList(copy);


  badblues list:
 */

int main() {
  CycList<int> obj;
  obj.addValue(1);
  obj.addValue(2);
  obj.addValue(3);
  obj.addValue(4);
  std::cout << obj.isExistValue(3);
  std::cout << obj.isExistValue(99);
  // ask about remove
  obj.addValue(5);
  obj.removeValue(4);
  obj.show();
  // obj.show();
  // MainMenu(obj);
  return 0;
}
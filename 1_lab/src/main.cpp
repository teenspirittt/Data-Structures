#include "../headers/menu.h"

/* TODO :
  teenspirit list:

    removeVal(by index)

  badblues list:
    iteratory ебучие
 */

int main() {
  //MainMenu();
  CycList<int> obj;
  obj.addValue(1);
  obj.addValue(2);
  obj.addValue(4);
  obj.addValue(3);
  obj.addValue(5);
  obj.addValue(6);
  obj.addValue(8);
  obj.addValue(9);

  obj.removeValueByIndex(5);
  obj.show();
  std::cout << "\n" << obj;
  return 0;
}
#include "../headers/menu.h"

/* TODO :
  teenspirit list:
    copy constructor
    getLookedElemCount();
    editValue();
    CycList(copy);
    removeVal(by index)

  badblues list:
    выбор типа данных в меню (при запуске программы? )
 */

int main() {
  CycList<int> obj;
  obj.addValue(1);
  obj.addValue(2);
  obj.addValue(4);
  obj.addValue(3);
  obj.addValue(5);
  obj.addValue(4);
  obj.addValue(4);
  obj.addValue(4);


  obj.removeValue(4);
  obj.show();

  return 0;
}
#include "../headers/menu.h"

/* TODO :
  teenspirit list:
    copy constructor
    getLookedElemCount();
    editValue();
    CycList(copy);
    removeVal(by index)
    remove()

  badblues list:
    выбор типа данных в меню (при запуске программы? )
 */

int main() {
<<<<<<< HEAD
  MainMenu();
=======
  CycList<int> obj;
  obj.addValue(1);
  obj.addValue(2);
  obj.addValue(3);

  // ask about remove
  obj.addValue(5);
  obj.removeValue(4);
  obj.show();
  // MainMenu(obj);
>>>>>>> vshabunin
  return 0;
}
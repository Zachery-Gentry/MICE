#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "emporium.h"
#include "view.h"

class Controller {
  public:
    Controller();
    Controller (Emporium& emporium) : _emporium(emporium), view(View(emporium)) { }
    void cli();
    void execute_cmd(int cmd);
  private:
    Emporium& _emporium;
    View view;
};

#endif // CONTROLLER_H

#ifndef VIEW_H
#define VIEW_H

#include "emporium.h"
#include <gtkmm.h>
#include "serving.h"

class View {
  public:
    View(Emporium& emp) : emporium(emp) { }
    int select_from_menu();
    string get_scoops();
    string get_toppings();
    string get_containers();

    void list_scoops();
    void select_choices();
    void help();
  private:
    Emporium& emporium;
};

#endif // VIEW_H

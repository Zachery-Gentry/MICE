#include "controller.h"
#include <string>
#include "view.h"
#include "emporium.h"
#include "scoop.h"
#include "topping.h"
#include "container.h"
//#include "item.h"
#include "dialogs.h"
#include <iostream>
#include <sstream>

using namespace std;

void Controller::cli() {
  int cmd = -1;
  while (cmd != 0) {
    cmd = view.select_from_menu();
    execute_cmd(cmd);
  }
}

void Controller::execute_cmd(int cmd) {
    if(cmd == 1){ //Create item
        string name, description;
        double cost, price;
        int quantity, type;
        bool cancel = false;

        Gtk::Dialog *dialogC = new Gtk::Dialog();
        dialogC->set_title("Create Item");

        // Type
        Gtk::HBox b_type;

        Gtk::Label l_type{"Type:"};
        l_type.set_width_chars(15);
        b_type.pack_start(l_type, Gtk::PACK_SHRINK);

        Gtk::ComboBoxText c_type;
        c_type.set_size_request(160);
        c_type.append("Ice Cream Flavor");
        c_type.append("Topping");
        c_type.append("Container");
        b_type.pack_start(c_type, Gtk::PACK_SHRINK);
        dialogC->get_vbox()->pack_start(b_type, Gtk::PACK_SHRINK);

        // Show dialog
        dialogC->add_button("Cancel", 0);
        dialogC->add_button("OK", 1);
        dialogC->show_all();

        int result = dialogC->run();

        dialogC->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();

        type = c_type.get_active_row_number();
        // 0 - ice cream flavor
        // 1 - topping
        // 2 - container

        if(result == 0){
            return;
        }

        Gtk::Dialog *dialog = new Gtk::Dialog();

        // Title
        Gtk::HBox b_name;

        Gtk::Label l_name;
        if(type == 0)
            l_name.set_text("Flavor");
        else
            l_name.set_text("Name:");
        l_name.set_width_chars(15);
        b_name.pack_start(l_name, Gtk::PACK_SHRINK);

        Gtk::Entry e_name;
        e_name.set_max_length(50);
        b_name.pack_start(e_name, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

        // Author
        Gtk::HBox b_descr;

        Gtk::Label l_descr{"Description:"};
        l_descr.set_width_chars(15);
        b_descr.pack_start(l_descr, Gtk::PACK_SHRINK);

        Gtk::Entry e_descr;
        e_descr.set_max_length(50);
        b_descr.pack_start(e_descr, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_descr, Gtk::PACK_SHRINK);

        // Cost
        Gtk::HBox b_cost;

        Gtk::Label l_cost{"Cost($):"};
        l_cost.set_width_chars(15);
        b_cost.pack_start(l_cost, Gtk::PACK_SHRINK);

        Gtk::Entry e_cost;
        e_cost.set_max_length(50);
        b_cost.pack_start(e_cost, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);

        // Price
        Gtk::HBox b_price;

        Gtk::Label l_price{"Price($):"};
        l_price.set_width_chars(15);
        b_price.pack_start(l_price, Gtk::PACK_SHRINK);

        Gtk::Entry e_price;
        e_price.set_max_length(50);
        b_price.pack_start(e_price, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);

        // Quantity
        Gtk::HBox b_quantity;

        Gtk::Label l_quantity{"Quantity:"};
        l_quantity.set_width_chars(15);
        b_quantity.pack_start(l_quantity, Gtk::PACK_SHRINK);

        Gtk::Entry e_quantity;
        e_quantity.set_max_length(50);
        b_quantity.pack_start(e_quantity, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_quantity, Gtk::PACK_SHRINK);

        // Number of scoops (if type is container)
        Gtk::Entry e_num_scoops;
        Gtk::HBox b_num_scoops;
        Gtk::Label l_num_scoops;
        if(type == 2){
            l_num_scoops.set_text("Number of scoops:");
            l_num_scoops.set_width_chars(15);
            b_num_scoops.pack_start(l_num_scoops, Gtk::PACK_SHRINK);

            e_num_scoops.set_max_length(50);
            b_num_scoops.pack_start(e_num_scoops, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_num_scoops, Gtk::PACK_SHRINK);
        }

        // Show dialog
        dialog->add_button("Cancel", 0);
        dialog->add_button("OK", 1);
        dialog->show_all();
        result = dialog->run();

        dialog->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();

        if(result == 0){
            return;
        }

        name = e_name.get_text();
        description = e_descr.get_text();

        string temp = e_cost.get_text();
        cost = stod(temp);
        temp = e_price.get_text();
        price = stod(temp);
        temp = e_quantity.get_text();
        quantity = stoi(temp);

        if(result == 1){
            if(type == 0)
                _emporium.add_item(Scoop(name, description, cost, price));
            else if(type == 1)
                _emporium.add_item(Topping(name, description, cost, price, quantity));
            else if (type == 2){
                temp = e_num_scoops.get_text();
                int num_scoops = stoi(temp);
                _emporium.add_item(Container(name, description, cost, price, num_scoops));
            }
        }
    }

    else if(cmd == 2){ //Create serving
        view.select_choices();
    }
}

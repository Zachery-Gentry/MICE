#include "view.h"
#include "dialogs.h"
#include <string>
#include "serving.h"

using namespace std;

int View::select_from_menu() {
  string menu = R"(
<span font='18' weight='bold'>                     CSE1325
Library Management System<sup><small>TM</small></sup></span>

<span weight='bold' underline='double'>Publications</span>
(1) Add publication
(2) List all publications
(3) Check out publication
(4) Check in publication

<span weight='bold' underline='double'>Patrons</span>
(5) Add patron
(6) List all patrons

<span weight='bold' underline='double'>Utility</span>
<span color='#007f00'><b>(9) Help</b></span>
(0) Exit

)";

  string result = Dialogs::input(menu, "Main Menu");
  try {
    return (result == "CANCEL") ? 0 : stoi(result);
  } catch (...) {
    return -1;
  }
}

string View::get_scoops(){
    string scoops;
    for(int i = 0; i < emporium.number_of_scoops(); i++){
            scoops += to_string(i) + ") " + emporium.get_scoop(i).name() + "\n";
    }
    return scoops;
}

string View::get_containers(){
    string containers;
    for(int i = 0; i < emporium.number_of_containers(); i++){
            containers += to_string(i) + ") " + emporium.get_container(i).name() + " - holds " + to_string(emporium.get_container(i).max_scoops()) + "\n";
    }
    return containers;
}

string View::get_toppings(){
    string topping;
    for(int i = 0; i < emporium.number_of_toppings(); i++){
            topping += to_string(i) + ") " + emporium.get_topping(i).name() + "\n";
    }
    return topping;
}

void View::list_scoops(){
    Dialogs::message(get_scoops(), "List of flavors available");
}

void View::select_choices(){
    //Serving serving;
    int scoop, topping, container;
    string result = Dialogs::input(get_containers(), "Select a container");
    try {
        (result == "CANCEL") ? -1 : stoi(result);
        }
        catch (...){
        Dialogs::message("Invalid entry - please type an integer");
        }
    container = stoi(result);
   // serving.select_container(emporium.get_container(container));

    //int temp = serving.get_container().max_scoops();
    while(1){
        //if(temp == 0)
           // break;
        result = Dialogs::input(get_scoops(), "Select your flavors --- enter -1 to move to toppings");
        if(stoi(result) == -1 )
            break;
    try {
        (result == "CANCEL") ? -1 : stoi(result);
        //temp--;
        }
        catch (...){
        Dialogs::message("Invalid entry - please type an integer");
        }
        scoop = stoi(result);
        //serving.add_scoop(emporium.get_scoop(stoi(result)));
    }

    while(1){

        result = Dialogs::input(get_toppings(), "Select your toppings --- enter -1 to stop");
        if(stoi(result) == -1)
            break;
    try {
        (result == "CANCEL") ? -1 : stoi(result);
        //temp--;
        }
        catch (...){
        Dialogs::message("Invalid entry - please type an integer");
        }
        topping = stoi(result);
        //serving.add_scoop(emporium.get_scoop(stoi(result)));
    }
}

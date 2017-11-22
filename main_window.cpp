#include "main_window.h"

Emporium emporium;
Controller c(emporium);

Main_window::Main_window()
{
    //GUI SETUP HERE
    set_default_size(800,600);

    // Puts a vertical box container as the window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    //Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    // Append Add Publication to the File menu..
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_click));
    filemenu->append(*menuitem_new);

    // Append Add Patron to the file menu..
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_open_click));
    filemenu->append(*menuitem_open);

    //Append Save to file menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_save_click));
    filemenu->append(*menuitem_save);

    //Append Save as to file menu
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("Save As", true));
    menuitem_save_as->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_save_as_click));
    filemenu->append(*menuitem_save_as);

    //Append properties
    Gtk::MenuItem *menuitem_properties = Gtk::manage(new Gtk::MenuItem("_Properties", true));
    menuitem_properties->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_properties_click));
    filemenu->append(*menuitem_properties);

    //Append Quit to the file menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);


    //Create Edit menu and add to menu bar
    Gtk::MenuItem *menuitem_edit = Gtk::manage(new Gtk::MenuItem("_Edit", true));
    menubar->append(*menuitem_edit);
    Gtk::Menu *editmenu = Gtk::manage(new Gtk::Menu());
    menuitem_edit->set_submenu(*editmenu);

    //Append undo
    Gtk::MenuItem *menuitem_undo = Gtk::manage(new Gtk::MenuItem("_Undo", true));
    menuitem_undo->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_undo_click));
    editmenu->append(*menuitem_undo);

        //Create Create menu and add to menu bar
    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
    menubar->append(*menuitem_create);
    Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*createmenu);

    //Append create item
    Gtk::MenuItem *menuitem_createItem = Gtk::manage(new Gtk::MenuItem("_Item", true));
    menuitem_createItem->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_create_item_click));
    createmenu->append(*menuitem_createItem);

    // T E S T I N G
    //
    // APPEND TEST SERVING CREATION
    Gtk::MenuItem *menuitem_createServing = Gtk::manage(new Gtk::MenuItem("Serving", true));
    menuitem_createServing->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_create_serving_click));
    createmenu->append(*menuitem_createServing);

    //Create Process menu and add to menu bar
    Gtk::MenuItem *menuitem_process = Gtk::manage(new Gtk::MenuItem("_Process", true));
    menubar->append(*menuitem_process);
    Gtk::Menu *processmenu = Gtk::manage(new Gtk::Menu());
    menuitem_process->set_submenu(*processmenu);

    //Create Report menu and add to menu bar
    Gtk::MenuItem *menuitem_report = Gtk::manage(new Gtk::MenuItem("_Report", true));
    menubar->append(*menuitem_report);
    Gtk::Menu *reportmenu = Gtk::manage(new Gtk::Menu());
    menuitem_report->set_submenu(*reportmenu);

    //Create Role menu and add to menu bar
    Gtk::MenuItem *menuitem_role = Gtk::manage(new Gtk::MenuItem("Role", true));
    menubar->append(*menuitem_role);
    Gtk::Menu *rolemenu = Gtk::manage(new Gtk::Menu());
    menuitem_role->set_submenu(*rolemenu);

    // Create a help menu and add to menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //Append about to help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    helpmenu->append(*menuitem_about);

    //Add a toolbar to vertical box, right below menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);


    //Append add_publication button to toolbar
    Gtk::ToolButton *add_publication_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    //add_publication_button->set_tooltip_markup("Add a publication to the library");
    //add_publication_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_addPublication_click));
    toolbar->append(*add_publication_button);

    //Append list_publication button to toolbar
    Gtk::ToolButton *list_publication_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::FIND));
    //list_publication_button->set_tooltip_markup("List the publications currently in the library.");
    //list_publication_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_showPublications_click));
    toolbar->append(*list_publication_button);

    //Append checkout publication button to toolbar
    Gtk::ToolButton *checkout_publication_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::APPLY));
    //checkout_publication_button->set_tooltip_markup("Check a publication out from the library");
    //checkout_publication_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_checkOut_click));
    toolbar->append(*checkout_publication_button);

    //Append checkin publication button to toolbar
    Gtk::ToolButton *checkin_publication_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::UNDO));
    //checkin_publication_button->set_tooltip_markup("Checkin a publication to the library");
    //checkin_publication_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_checkIn_click));
    toolbar->append(*checkin_publication_button);

    //Append Add patron to toolbar
    Gtk::ToolButton *add_patron_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::DIRECTORY));
    //add_patron_button->set_tooltip_markup("Add a patron to the database");
    //add_patron_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_addPatron_click));
    toolbar->append(*add_patron_button);

    //Append help button to toolbar
    Gtk::ToolButton *about_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ABOUT));
    //about_button->set_tooltip_markup("Get help");
    //about_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    toolbar->append(*about_button);

    vbox->show_all();
}

void Main_window::on_create_item_click(){
    c.execute_cmd(1);
}

void Main_window::on_create_serving_click(){
    c.execute_cmd(2);
}

void Main_window::on_new_click(){}

void Main_window::on_open_click(){}

void Main_window::on_quit_click(){}

void Main_window::on_save_click(){}

void Main_window::on_save_as_click(){}

void Main_window::on_properties_click(){}

void Main_window::on_undo_click(){}

void Main_window::on_about_click(){}


Main_window::~Main_window(){

}

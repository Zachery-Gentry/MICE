#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include "controller.h"
#include "emporium.h"

class Main_window : public Gtk::Window
{
    public:
        Main_window();
        virtual ~Main_window();
        void on_new_click();
        void on_open_click();
        void on_quit_click();
        void on_save_click();
        void on_save_as_click();
        void on_properties_click();
        void on_undo_click();
        void on_create_item_click();
        void on_about_click();
        void on_create_serving_click();
    private:
};

#endif // MAIN_WINDOW_H

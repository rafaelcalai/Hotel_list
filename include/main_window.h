//
// Created by rcala on 24-07-2023.
//

#ifndef HOTEL_LIST_MAIN_WINDOW_H
#define HOTEL_LIST_MAIN_WINDOW_H
#include "columns.h"
#include <fstream>

using namespace Gtk;

class MainWindow: public Window
{
private:
    ScrolledWindow scroll;
    TreeView tree;
    Columns columns;
    Glib::RefPtr<ListStore> model;
    int error;
public:
    MainWindow();
    int get_error();
    void set_error(int _error);
};
#endif //HOTEL_LIST_MAIN_WINDOW_H

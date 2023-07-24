//
// Created by rcala on 24-07-2023.
//

#ifndef HOTEL_LIST_COLUMNS_H
#define HOTEL_LIST_COLUMNS_H
#include <gtkmm-3.0/gtkmm.h>
using namespace Gtk;

class Columns : public TreeModel::ColumnRecord
{
public:
    TreeModelColumn<unsigned int> col_id;
    TreeModelColumn<std::string> col_name;
    TreeModelColumn<Glib::RefPtr<Gdk::Pixbuf>> col_stars;
    Columns();

};
#endif //HOTEL_LIST_COLUMNS_H

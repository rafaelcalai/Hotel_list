//
// Created by rcala on 24-07-2023.
//
#include <iostream>
#include "../include/main_window.h"
#include <unistd.h>

using namespace Gtk;


MainWindow::MainWindow() {

    error = 0;
    set_size_request(500, 500);
    set_resizable(false);
    set_border_width(10);
    set_position(WIN_POS_CENTER);
    set_title("Hotel List");

    model = ListStore::create(columns);
    tree.set_model(model);
    std::string line, fich_image;
    Glib::RefPtr<Gdk::Pixbuf> original_image;

    std::ifstream input_file;
    input_file.open("../data/lista.txt");

    if(input_file.is_open())
    {
        while(getline(input_file, line))
        {
            if(line.substr(0, 1) == "#")
            {
                break;
            }
            std::cout << line << std::endl;
            TreeModel::Row row = *(model->append());

            row[columns.col_id] = stoi(line.substr(0,3));
            auto num_char = line.length();
            row[columns.col_name] = line.substr(6, num_char - 7);
            fich_image = "../data/stars/" + line.substr(4,1) + ".png";
            original_image = Gdk::Pixbuf::create_from_file(fich_image);
            row[columns.col_stars] = original_image->scale_simple(200,40,Gdk::INTERP_BILINEAR);
        }
        input_file.close();
        tree.append_column("ID", columns.col_id);
        tree.append_column("Name", columns.col_name);
        tree.append_column("Stars", columns.col_stars);
        tree.set_headers_clickable(true);
        std::cout << tree.get_n_columns() << std::endl;
        scroll.add(tree);
        add(scroll);
        show_all_children();
    }
    else
    {
        MessageDialog m_dialog("Error, when tryed to open the file!", false, MESSAGE_ERROR, BUTTONS_OK);
        m_dialog.set_transient_for(*this);
        auto response = m_dialog.run();
        if(response == BUTTONS_OK)
        {
            set_error(1);
            exit(0);
        }
    }
}

int MainWindow::get_error()
{
    return error;
}

void MainWindow::set_error(int _error)
{
 error = _error;
}

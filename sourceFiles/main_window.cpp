//
// Created by rcala on 24-07-2023.
//
#include <iostream>
#include "../include/main_window.h"

using namespace Gtk;


MainWindow::MainWindow() {

    set_size_request(500, 500);
    set_resizable(false);
    set_border_width(10);
    set_position(WIN_POS_CENTER);
    set_title("Hotel List");

    model = ListStore::create(columns);
    tree.set_model(model);

    std::ifstream input_file;
    input_file.open("../data/lista.txt");

    if(input_file.is_open())
    {
        std::string line, fich_image;
        while(getline(input_file, line))
        {
            if(line.substr(0, 1) == "#")
            {
                break;
            }
            std::cout << line << std::endl;
        }
        input_file.close();
    }
}

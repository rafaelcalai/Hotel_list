#include <iostream>

#include "include/main_window.h"

int main(int argc, char *argv[]) {
    std::cout << "Hotel List" << std::endl;
    Main main(argc, argv);
    MainWindow main_window;
    if(main_window.get_error() == 0)
    {
        main.run(main_window);
    }

    return 0;
}

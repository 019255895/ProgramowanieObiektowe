#include "menu.h"
#include "table.h"
#include <string>

using namespace UserTable;

namespace UserMenu
{   
    // initialize table (read data from data.dat path)
    Table tab("data.dat");

    // quit from programm
    void quit(){
        exit(0);
    }
    
    // display table content
    void dispayTable(){
        tab.display();
    }

    // set table value by position
    void setValue(){
        std::string choice;
        int x, y, i_val;
        std::string s_val;

        std::cout << "1. Set integer value." << '\n' 
                  << "2. Set string value."  << '\n';
        
        std::cin >> choice;
        std::cout << "Put x position:\n";
        std::cin >> x; 
        std::cout << "Put y position:\n";
        std::cin >> y;

        if (choice == "1"){
            std::cin >> i_val;
            tab.setIntValue(i_val, x, y);
        } else 
        if (choice == "2"){
            std::cin >> s_val;
            tab.setStringValue(s_val, x, y);
        }
    }


    // Contain menu components
    Component menu[] =
    {
        {"Display", dispayTable}, // display table content
        {"Set cell value", setValue},
        {"Quit", quit}            // close programm
    };

    // calculate menu size
    static const unsigned int menu_size = sizeof(menu) / sizeof(menu[0]);

    /**
     * @brief run writing menu
     */
    void run(){
        // display selections list
        for (int i = 0; i < menu_size; i ++){
            std::cout << i << ". " << menu[i].selectionText << std::endl;
        }

        // read user input
        std::string selection;
        std::cout << "Write selection number:" << std:: endl;
        std::cin >> selection;

        // check for selection existance 
        try
        {   
            int selected = stoi(selection);
            if (selected > menu_size - 1 || selected < 0){
                throw selection;
            } else {
                // call action
                (menu[selected].processingFunction)();
                getchar();
                getchar();
            }
        }
        catch(std::string selection)
        {
            std::cout << "Error: fail exception." << std::endl;
        }
    }
} // namespace UserMenu

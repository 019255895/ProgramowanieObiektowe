#include <iostream>
#include "menu.h"

/*!
    \warning this is only a late version of the class for rendering the menu, 
             at the moment I am composing a model for using this class, 
             but the execution model will remain the same.
    \warning I also plan to use the "Command" pattern in the future writing the program.
*/

namespace UserMenu{
    void hello(){
        std::cout << "Hello worls\n";
    }

    ItemMenu mianMenu[] = {
        {'1', "Change size.", NULL, NULL},
        {'2', "Change data.", NULL, NULL},
        {'3', "Calculations.", NULL, NULL},
        {'4', "Display.", NULL, NULL},
        {'Q', "quit program.", NULL, NULL},
    };

    void Draw(ItemMenu * menu){
        static const size_t quantity_selections = sizeof(mianMenu) / sizeof(mianMenu[0]);

        for (size_t i = 0; i < quantity_selections; i ++){
            std::cout << "(" << menu[i].choice << ") " << menu[i].selectionText << std::endl;
            
            // if (menu[i].SubMenu != NULL){
            //     Draw(menu[i].SubMenu);
            // }
        }
    }

    void Action(char * choice){

    }

    void Run(){
        char choice;
        Draw(mianMenu);
    }
}
#include <iostream>
#include "table.h"
#include "menu.h"

using namespace std;

int main(int argc, char const *argv[])
{   
    Table tab(2, 2);

    while (userMenu::isMenu(tab));
    
    // Table tab(3, 2);

    // for (int i = 0; i < tab.width; i ++){
    //     for(int j = 0; j < tab.height; j ++){
    //         set(tab, i, j, j + 1);
    //     }
    // }

    // resize(tab, 4, 4);

    // display(tab);    
    return 0;
}

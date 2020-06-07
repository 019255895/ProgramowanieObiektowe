#include <iostream>
#include "table.h"
#include "menu.h"

int main(int argc, char const *argv[])
{
    while(true){
        UserMenu::run();
    }
    return 0;
}

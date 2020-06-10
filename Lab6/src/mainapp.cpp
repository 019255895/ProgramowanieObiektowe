#include <iostream>
#include "table.h"
#include "menu.h"

using namespace UserMenu;

int main(int argc, char const *argv[])
{
    _initDataTable();
    _initMenu();

    while(true) _Run();    
    return 0;
}

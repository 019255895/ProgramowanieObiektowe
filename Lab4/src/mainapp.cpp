#include <iostream>
#include "table.h"

int main(int argc, char const *argv[])
{   
    UserTable::Table tab(1, 3);
    // tab.setValue(0, 0, 1);
    tab.resize(1, 2);
    tab.display();
    return 0;
}

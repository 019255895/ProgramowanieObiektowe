#include <iostream>
#include "table.h"

int main(int argc, char const *argv[])
{   
    UserTable::Table tab("data.dat");
    // UserTable::Table tab(1, 3);
    tab.setValue(0, 0, 101);
    tab.display();
    return 0;
}

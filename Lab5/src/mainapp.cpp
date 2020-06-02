#include <iostream>
#include "cell.h"
#include "table.h"

using namespace UserTable;

int main(int argc, char const *argv[])
{   
    Table tab(2, 2);
    tab.setIntValue(1, 0, 0);
    tab.setStringValue("Example", 1, 1);
    tab.display();
    
    return 0;
}

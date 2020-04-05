#include <iostream>
#include "table.h"

int main(int argc, char const *argv[])
{
    Table tab(2, 3);
    add(tab, 0, 0, 1);
    add(tab, 1, 1, 1);

    display(tab);

    return 0;
}

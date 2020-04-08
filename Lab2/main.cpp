#include <iostream>
#include "table.h"
#include "menu.h"

int main(int argc, char const *argv[])
{
    Table tab(2, 2);

    while (userMenu::isMenu(tab));
}

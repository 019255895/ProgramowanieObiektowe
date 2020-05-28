#include <iostream>
#include "cells.h"

int main(int argc, char const *argv[])
{   
    UserCell::Cell cell;
    cell._initInt(1);

    std::cout << cell._type() << " " << cell.cell.value.iVal << std::endl;
    return 0;
}

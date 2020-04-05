#include <iostream>
#include <stdlib.h>
#include <vector>
#include "table.h"

int main(int argc, char const *argv[])
{   
    std::vector<std::vector<int>> table{{1, 2, 3},
                                        {1, 2, 3},
                                        {1, 2, 3}};

    userTable::changeData(table, 0, 0, 100);
    userTable::display(table);
    return 0;
}

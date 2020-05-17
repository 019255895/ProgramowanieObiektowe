#pragma once
#include "table.h"

namespace UserCalc{
    int sumInColl(Table &tab, int col);
    int sumInRow(Table &tab, int row);
    int maxInColl(Table &tab, int col);
    int maxInRow(Table &tab, int row);
    int meanInColl(Table &tab, int col);
    int meanInRow(Table &tab, int col);
}
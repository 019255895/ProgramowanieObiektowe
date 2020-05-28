#include <iostream>
#include "table.h"

namespace UserTable
{
    void Cell::_initInt(int number){
        cell.type = v_int;
        cell.value.iVal = number;
    }
    
    void Cell::_initChar(char character){
        cell.type = v_char;
        cell.value.cVal = character;
    }

    std::string Cell::_type(){
        switch (cell.type)
        {
        case v_int:
            return "Int";
            break;
        case v_char:
            return "Char";
            break;
        default:
            return "None";
            break;
        }
    }
} // namespace UserTable

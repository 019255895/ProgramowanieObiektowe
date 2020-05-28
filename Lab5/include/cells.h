#pragma once
#include <iostream>

namespace UserCell
{   
    typedef enum { v_int, v_char } Type;

    typedef struct MultipleType
    {   
        Type type;
        union
        {
            int iVal;
            char cVal;
        } value;   
    } MultipleType;

    class Cell
    {
    public:
        MultipleType cell;
        void _initInt(int number);
        void _initChar(char character);
        std::string _type();
    };
    
} // namespace UserTable

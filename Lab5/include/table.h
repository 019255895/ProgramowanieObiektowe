/**
 * @file table.h
 * @author Andrii Torulia
 * @brief Table class
 * @date 2020-06-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include <iostream>
#include "cell.h"

namespace UserTable
{   
    class Table
    {
    private:
        Cell ** data; ///< 2D dynamic data cells array 

        int width, height; ///< table size
    public:
        /// Constructor
        Table(int rows, int cols);
        /// Destructor
        ~Table();

        /// Draw table capacity
        void display();
        /// Set integer value on cell
        void setIntValue(int value, int xPosition, int yPosition);
        /// Set string value on cell
        void setStringValue(std::string value, int xPosition, int yPosition);
    };
    
    
} // namespace UserTable

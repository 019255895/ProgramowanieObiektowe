#pragma once
#include <string>
#include "cell.h"

namespace UserTable
{   
    class Table
    {
    private:
        Cell ** data;
        int width, height;        
        std::string path;
    public:
        ~Table();

        void _init(std::string filePath);
        /// Draw table capacity
        void display();
        /// Set integer value on cell
        void setIntValue(int value, int xPosition, int yPosition);
        /// Set string value on cell
        void setStringValue(std::string value, int xPosition, int yPosition);
    };   
} // namespace UserTable


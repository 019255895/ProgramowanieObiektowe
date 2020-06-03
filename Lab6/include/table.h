#pragma once
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
        Table(std::string filePath);
        ~Table();

        /// Draw table capacity
        void display();
        /// Set integer value on cell
        void setIntValue(int value, int xPosition, int yPosition);
        /// Set string value on cell
        void setStringValue(std::string value, int xPosition, int yPosition);
    };   
} // namespace UserTable


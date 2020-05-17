#include <iostream>
#include "table.h"

namespace UserTable
{
    Table::Table(int rows, int cols) : width(rows), height(cols)
    {
        data = new int* [rows]();
        
        for (int i = 0; i < rows; i++){
            data[i] = new int[cols]();
        }
    }
    
    Table::~Table()
    {
        for (auto i = 0; i < height; i++) 
            delete[] data[i];
        
        delete[] data; 
    }

    void Table::display(){
        for (size_t i = 0; i < height; i++){
            for (size_t j = 0; j < width; j++){
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void Table::setValue(int xPos, int yPos, int newValue){
        if (xPos <= width && yPos <= height){
            data[xPos][yPos] = newValue;
        } else {
            std::cout << "Error: Out of size" << std::endl;
        }
    }

    void Table::resize(int new_width, int new_height){
    } 
} // namespace UserTable

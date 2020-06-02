#include <iostream>
#include "table.h"
#include "cell.h"

namespace UserTable
{
    /**
     * @brief Construct a new Table:: Table object
     * 
     * @param rows table width
     * @param cols table height
     */
    Table::Table(int rows, int cols) : width(rows), height(cols)
    {
        data = new Cell * [rows];

        for (size_t i = 0; i < rows; i ++){
            data[i] = new Cell [cols];
        }
    }
    
    /**
     * @brief Destroy the Table:: Table object
     * 
     */
    Table::~Table()
    {
        for (auto i = 0; i < height; i++) 
            delete[] data[i];
        
        delete[] data; 
    }

    /**
     * @brief Drawing table capacity
     * 
     */
    void Table::display(){
        for (size_t i = 0; i < height; i++){
            for (size_t j = 0; j < width; j ++){
                // Check if cell is empty 
                if (data[i][j].type == empty){
                    std::cout << "Empty cell" << " ";
                } else {
                    if (data[i][j].type == v_int){
                        std::cout << data[i][j].number << " ";
                    } else {
                        std::cout << data[i][j].line << " ";
                    }
                }
            }
            std::cout << '\n';
        }
    }

    /**
     * @brief Set cell as integer
     * 
     * @param value new cell value
     * @param xPosition cell position in array
     * @param yPosition cell position in array
     */
    void Table::setIntValue(int value, int xPosition, int yPosition){
        data[xPosition][yPosition].type = v_int;
        data[xPosition][yPosition].number = value;    
    }

    /**
     * @brief Set cell as string
     * 
     * @param value new cell value
     * @param xPosition cell position in array
     * @param yPosition cell position in array
     */
    void Table::setStringValue(std::string value, int xPosition, int yPosition){
        data[xPosition][yPosition].type = v_string;
        data[xPosition][yPosition].line = value;    
    }
} // namespace UserTable

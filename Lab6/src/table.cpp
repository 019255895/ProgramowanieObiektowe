#include <iostream>
#include <fstream>
#include <string>
#include "cell.h"
#include "table.h"

namespace UserTable
{   
    bool is_number(const std::string& s)
    {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }

    Table::Table(std::string filePath) : path(filePath){
        std::ifstream fp(filePath);
        
        if (fp.is_open()){
            fp >> width;
            fp >> height;

            data = new Cell * [width];
            for (size_t i = 0; i < width; i ++){
                data[i] = new Cell [height];
            }

            for (size_t i = 0; i < width; i ++){
                std::string line;
                
                for (size_t j = 0; j < height; j ++){
                    fp >> line;
                        
                    std::string val;
                    val.reserve(line.size()); // optional, avoids buffer reallocations in the loop
                    for(size_t i = 0; i < line.size(); ++i){
                        if(line[i] != ',') val += line[i];
                    }
                    
                    if (is_number(val)){
                        data[i][j].type = v_int;
                        data[i][j].number = stoi(val);
                    } else {
                        data[i][j].type = v_string;
                        data[i][j].line = val;
                    }
                }
            }
        } else {
            std::cout << "Error: can't open file path \n";
        }

        fp.close();
    }

    Table::~Table()
    {   
        std::fstream ofs;
        
        ofs.open(path, std::ios::out | std::ios::trunc);
        
        ofs << width << std::endl;
        ofs << height << std::endl;

        for (int i = 0; i < width; i++){
            for (int j = 0; j < height; j++){
                if (data[i][j].type != empty){
                    if (data[i][j].type == v_string){
                        ofs << data[i][j].line << ", ";
                    } else {
                        ofs << std::to_string(data[i][j].number) << ", ";
                    }
                }
                // ofs << std::to_string(data[i][j]) << ", ";
            }
            ofs << '\n';
        }

        ofs.close();
        for (auto i = 0; i < height; i++) 
            delete[] data[i];
        
        delete[] data; 
    }

        /**
     * @brief Drawing table capacity
     * 
     */
    void Table::display(){
        for (size_t i = 0; i < width; i++){
            for (size_t j = 0; j < height; j ++){
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

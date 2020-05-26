#include <iostream>
#include <fstream>
#include <string>
#include "table.h"

namespace UserTable
{
    Table::Table(const char * path)
    {   
        filePath = path;
        std::ifstream fp(path);
        
        if (fp.is_open()){
            fp >> rows;
            fp >> cols;

            data = new int* [rows];
            for (size_t i = 0; i < rows; i ++){
                data[i] = new int[cols];
            }

            for (size_t i = 0; i < rows; i ++){
                std::string line;
                
                for (size_t j = 0; j < cols; j ++){
                    fp >> line;
                        
                    std::string num;
                    num.reserve(line.size()); // optional, avoids buffer reallocations in the loop
                    for(size_t i = 0; i < line.size(); ++i){
                        if(line[i] != ',') num += line[i];
                    }
                    data[i][j] = stoi(num);
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
        
        ofs.open(filePath, std::ios::out | std::ios::trunc);
        
        ofs << rows << std::endl;
        ofs << cols << std::endl;

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                ofs << std::to_string(data[i][j]) << ", ";
            }
            ofs << '\n';
        }

        ofs.close();
        // for (auto i = 0; i < cols; i++) 
        //     delete[] data[i];
        
        // delete[] data; 
    }

    void Table::display(){
        for (size_t i = 0; i < rows; i++){
            for (size_t j = 0; j < cols; j++){
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void Table::setValue(int xPos, int yPos, int newValue){
        if (xPos <= rows && yPos <= cols){
            data[xPos][yPos] = newValue;
        } else {
            std::cout << "Error: Out of size" << std::endl;
        }
    }

    // void Table::resize(int new_width, int new_height){
    //     int ** temp;
        
    //     temp = new int* [rows];
    //     for (size_t i = 0; i < rows; i++){
    //         temp[i] = new int [cols];
    //     }

    //     for(size_t i = 0; i < rows; i ++){
    //         for(size_t j = 0; j < cols; j ++){
    //             temp[i][j] = data[i][j]; 
    //         }    
    //     }

    //     for (auto i = 0; i < cols; i++) 
    //         delete[] data[i];
        
    //     delete[] data;

    //     data = new int* [new_width];
    //     for (size_t i = 0; i < new_width; i++){
    //         temp[i] = new int [new_height];
    //     }

    //     for(size_t i = 0; i < new_width; i ++){
    //         for(size_t j = 0; j < new_height; j ++){
    //             data[i][j] = temp[i][j];
    //         }    
    //     }
    // }
} // namespace UserTable

#ifndef _TABLE_H_
#define _TABLE_H_

    #include <iostream>

    struct Table
    {
        int ** data;
        int width; 
        int height;
        
        Table(int rows, int cols);
        ~Table();
    };
    
    // constructor
    Table::Table(int rows, int cols) : width(rows), height(cols)
    {
        data = new int* [rows]();
        
        for (int i = 0; i < rows; i++) 
        {
            data[i] = new int[cols]();
        }
    }
    
    // destructor
    Table::~Table()
    {
        for (auto i = 0; i < height; i++) 
            delete[] data[i];
        
        delete[] data; 
    }

    /*
    add value (val) on position (xPos, yPos)
    */
    void set(Table& tab, int xPos, int yPos, int val){

        if (xPos <= tab.width && yPos <= tab.height){
            tab.data[xPos][yPos] = val;
        } 
    }

    void display(Table& tab){
        for (int i = 0; i < tab.width; i++){
            for (int j = 0; j < tab.height; j++){
                std::cout << tab.data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void resize(Table& tab, int new_width, int new_height){
            Table temp(tab.width, tab.height);

            for (size_t i = 0; i < temp.width; i ++){
                for (size_t j = 0; j < temp.height; j ++){
                    temp.data[i][j] = tab.data[i][j];
                }
            }

            for (auto i = 0; i < tab.height; i++) 
                delete[] tab.data[i];
    
            delete[] tab.data; 

            tab.width = new_width;
            tab.height = new_height;
                
            tab.data = new int* [new_width]();
        
            for (size_t i = 0; i < new_width; i++) 
            {
                tab.data[i] = new int[new_height]();
            }

            for (size_t i = 0; i < temp.width; i ++){
                for (size_t j = 0; j < temp.height; j ++){
                    tab.data[i][j] = temp.data[i][j];
                }
            }
    }

#endif
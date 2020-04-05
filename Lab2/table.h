#ifndef _TABLE_H_
#define _TABLE_H_

    struct Table
    {
        int ** data;
        const size_t width; 
        const size_t height;
        
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
    void add(Table& tab, int xPos, int yPos, int val){

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

#endif
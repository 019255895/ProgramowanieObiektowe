#ifndef _TABLE_H_
#define _TABLE_H_

    #include <iostream>
    #include <vector>

    struct cell
    {
        int x;
        int y;
    }Cell;    

    class userTable
    {
    public:
        static void changeSize(std::vector<std::vector<int>> table, int new_width, int new_height);
        static void changeData(std::vector<std::vector<int>> table, int xPos, int yPos, int new_data);
        static void display(std::vector<std::vector<int>> table);
    };
    
    void userTable::display(std::vector<std::vector<int>> table){
        for (int i = 0; i < table.size(); i++){
            for (int j = 0; j < table[i].size(); j++){
                std::cout << table[i][j];
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }

    void userTable::changeData(std::vector<std::vector<int>> table, int xPos, int yPos, int new_data){
        // Error check
        if (table.size() > 0){
            if (yPos > table.size() || xPos > table[0].size()){
                std::cout << "Invalid value" << std::endl;
            } else {
                
                // data change
                table.at(yPos).at(xPos) = new_data;
            }
        }
    }

    void userTable::changeSize(std::vector<std::vector<int>> table, int new_width, int new_height){
        // change height
        table.resize(new_height);

        // change width
        for (int i = 0; i < table.size(); i ++){
            table[i].resize(new_width);
        }
    }

#endif
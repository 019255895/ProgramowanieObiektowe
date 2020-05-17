#include <iostream>
#include "table.h"
#include "calculations.h"

namespace UserCalc{
    int sumInColl(Table &tab, int col){
        int sum;
        if (col <= tab.width){
            for (int i = 0; i < tab.width; i++){
                for (int j = 0; j < tab.height; j ++){
                    if (j == col){
                        sum += tab.data[i][j];
                    }
                }
            }
            return sum;
        } else {
            std::cout << "Error: Out of table size" << std::endl;
        }
    }

    int sumInRow(Table &tab, int row){
        int sum;
        if (row <= tab.height){
            for (int i = 0; i < tab.width; i++){
                for (int j = 0; j < tab.height; j ++){
                    if (i == row){
                        sum += tab.data[i][j];
                    }
                }
            }
            return sum;
        } else {
            std::cout << "Error: Out of table size" << std::endl;
        }
    }

    int maxInColl(Table &tab, int col){
        int max;
        if (col <= tab.width){
            max = tab.data[col][0];
            for (int i = 0; i < tab.width; i++){
                for (int j = 0; j < tab.height; j ++){
                    if (j == col){
                        if (tab.data[i][j] > max){
                            max = tab.data[i][j];
                        }
                    }
                }
            }
            return max;
        } else {
            std::cout << "Error: Out of table size" << std::endl;
        }
    }

    int maxInRow(Table &tab, int row){
        int max;
        if (row <= tab.height){
            for (int i = 0; i < tab.width; i++){
                for (int j = 0; j < tab.height; j ++){
                    if (i == row){
                        if (tab.data[i][j] > max){
                            max = tab.data[i][j];
                        }
                    }
                }
            }
            return max;
        } else {
            std::cout << "Error: Out of table size" << std::endl;
        }
    }

    int meanInColl(Table &tab, int col){
        int sum;
        if (col <= tab.width){
            for (int i = 0; i < tab.width; i++){
                for (int j = 0; j < tab.height; j ++){
                    if (j == col){
                        sum += tab.data[i][j];
                    }
                }
            }
            return sum / tab.height;
        } else {
            std::cout << "Error: Out of table size" << std::endl;
        }
    }

    int meanInRow(Table &tab, int row){
        int sum;
        if (row <= tab.height){
            for (int i = 0; i < tab.width; i++){
                for (int j = 0; j < tab.height; j ++){
                    if (i == row){
                        sum += tab.data[i][j];
                    }
                }
            }
            return sum / tab.width;
        } else {
            std::cout << "Error: Out of table size" << std::endl;
        }
    }
}
#include <iostream>
#include <fstream>
#include <string>
#include "table.h"
#include "actions.h"

using namespace std;

namespace UserActions{
    void readFromFile(Table &tab, string filePath){
        ifstream fp(filePath);
        int width, height;
        int ** readData; ///< read data from a file

        if (fp.is_open()){
            fp >> width;
            fp >> height;
            
            readData = new int* [width];
            for (size_t i = 0; i < width; i ++){
                readData[i] = new int[height];
            }

            for (size_t i = 0; i < width; i ++){
                string line;
                    for (size_t j = 0; j < height; j ++){
                        fp >> line;
                        
                        string num;
                        num.reserve(line.size()); // optional, avoids buffer reallocations in the loop
                        for(size_t i = 0; i < line.size(); ++i){
                            if(line[i] != ',') num += line[i];
                        }
                        readData[i][j] = stoi(num);
                    }
            }

            tab.data = readData;
            tab.width = width;
            tab.height = height;
            tab.isEmpty = false;
        } else {
            cout << "Read file error" << endl;
        }

        fp.close();
    }

    void writeToFile(Table &tab, std::string filePath, std::string fileName){
        fstream ofs;
        ofs.open(fileName, ios::out | ios::trunc);

        ofs << tab.width << endl;
        ofs << tab.height << endl;

        for (int i = 0; i < tab.width; i++){
            for (int j = 0; j < tab.height; j++){
                ofs << std::to_string(tab.data[i][j]) << ", ";
            }
            ofs << '\n';
        }

        ofs.close();
    }

    void display(Table &tab){
        if (!tab.isEmpty){
            for (int i = 0; i < tab.width; i ++){
                for (int j = 0; j < tab.height; j ++){
                    cout << tab.data[i][j] << " ";
                }    
                cout << endl;
            }
        } else {
            cout << "Error: tble is empty." << endl;
        }
    }

    void setCellValue(Table &tab, int xCell, int yCell, int value){
        if (xCell <= tab.width && yCell <= tab.height){
            tab.data[xCell][yCell] = value;
        } else {
            cout << "Error: Out of table size" << endl;
        }
    }

    
}

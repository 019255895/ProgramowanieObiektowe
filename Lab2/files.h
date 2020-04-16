#ifndef _FILES_H_
#define _FILES_H_

    #include <iostream>
    #include <fstream>
    #include <string>
    #include "../include/UserTable.h"

    using namespace std;
    
    void read(string filePath, Table& tab){
        ifstream fp(filePath);
        int width, height;
        
        if (fp.is_open()){
            fp >> width;
            fp >> height;

            resize(tab, width, height);
            for (size_t i = 0; i < width; i ++){
                string line;
                    for (size_t j = 0; j < height; j ++){
                        fp >> line;
                        
                        string num;
                        num.reserve(line.size()); // optional, avoids buffer reallocations in the loop
                        for(size_t i = 0; i < line.size(); ++i){
                            if(line[i] != ',') num += line[i];
                    }
                    set(tab, i, j, stoi(num));
                }
            }
        } else {
            cout << "Read file error" << endl;
        }
        fp.close(); 
    }

    void write(string fileName, Table& tab){
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

#endif
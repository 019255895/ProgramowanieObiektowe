#ifndef _FILES_H_
#define _FILES_H_

    #include <iostream>
    #include <fstream>
    #include <string>
    #include "table.h"

    using namespace std;
    void read(string fileName, Table& tab){
        ifstream fp(fileName);

        if (fp.is_open()){
            fp >> tab.height;
            fp >> tab.width;

            for (size_t i = 0; i < tab.height; i ++){
                string line;
                for (size_t j = 0; j < tab.width; j ++){
                    fp >> line;
                    
                    string num;
                    num.reserve(line.size()); // optional, avoids buffer reallocations in the loop
                    for(size_t i = 0; i < line.size(); ++i){
                        if(line[i] != ',') num += line[i];
                    }

                    tab.data[i][j] = stoi(num);
                }
            }
        } else {
            std::cout << "Read file error" << std::endl;
        }
        fp.close(); 
    }

    void write(string fileName, Table& tab){
        fstream ofs;
        ofs.open(fileName, ios::out | ios::trunc);

        ofs << tab.height << endl;
        ofs << tab.width << endl;

        for (int i = 0; i < tab.width; i++){
            for (int j = 0; j < tab.height; j++){
                std::cout << tab.data[i][j] << ", ";
            }
            std::cout << std::endl;
        }

        ofs.close();
    }

#endif
#pragma once
#include <string>
#include "cell.h"

using namespace UserCell;

namespace UserTable
{   
    typedef enum{
        _int, _string
    } Type;

    // class Column{
    //     public:
    //         virtual void setInteger(int position, int value) = 0;
    //         virtual void setString(int position, string value) = 0;
    //         virtual int getInteger(int position);
    //         virtual string getString(int position);
    // };

    // class NumberColumn

    class Table
    {
        private:
            int width, height;
            string _path;
            Type* type;
            Cell*** table;
        public:
            void init(){
                type = new Type[width];
                
                table = new Cell**[width];

                for (int i = 0; i < width; i++){
                    table[i] = new Cell*[height];
                }

                for (int i = 0; i < width; i++){
                    for (int j = 0; j < height; j++){
                        if (type[i] == _int){
                            table[i][j] = new NumberCell();
                        }
                        if (type[i] == _string){
                            table[i][j] = new TextCell();
                        }
                    }
                }
            }

            void readFromFile(string path);
    };   
} // namespace UserTable


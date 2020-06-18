#pragma once
#include <string>
#include "cell.h"

using namespace UserCell;

namespace UserTable
{   
    typedef enum{
        _int, _string
    } Type;

    class Column{
        public:
            virtual void set(int position, string value) = 0;
            virtual int getInteger(int position) = 0;
            virtual string getString(int position) = 0;
    };

    class NumberColumn : public Column{
        private:
            string _title = "No title";
            int _size;
            Type _type;
            Cell** column;
        public:
            NumberColumn(Type type, int size, string title) : _type(type), _size(size), _title(title){
                column = new Cell*[_size];
                
                for (int i = 0; i < _size; i++){
                    column[i] = new NumberCell();
                }
            }

            void set(int position, string value){
                if (position <= _size){
                    column[position]->set(value); 
                }
            }

            int getInteger(int position){
                if (position <= _size){
                    return column[position]->getInteger();
                }
            }

            string getString(int position){
                return "";
            }
    };

    class TextColumn : public Column{
        private:
            string _title = "No title";
            int _size;
            Type _type;
            Cell** column;
        public:
            TextColumn(Type type, int size, string title) : _type(type), _size(size), _title(title){
                column = new Cell*[_size];
                
                for (int i = 0; i < _size; i++){
                    column[i] = new TextCell();
                }
            }

            void set(int position, string value){
                if (position <= _size){
                    column[position]->set(value); 
                }
            }

            string getString(int position){
                if (position <= _size){
                    return column[position]->getString();
                }
            }

            int getInteger(int position){
                return 0;
            }
    };

    class Table{
        private:
            int width, height;
            Type* types;
            string _path;
            string* titles;
            Column** table;
        public:
            void init(){
                types = new Type[width];
                titles = new string[width];
                table = new Column*[width];

                for (int i = 0; i < width; i++){
                    if (types[i] == _int){
                        table[i] = new NumberColumn(types[i], height, titles[i]);
                    } else 
                    if (types[i] == _string){
                        table[i] = new TextColumn(types[i], height, titles[i]);
                    }
                }
            }

            void readFromFile(string path);
    };
} // namespace UserTable


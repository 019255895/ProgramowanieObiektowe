/**
 * @class Cell
 * @file cell.h
 * @author your name (you@domain.com)
 * @brief Multiplie types cell class 
 * @date 2020-06-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

namespace UserCell
{
    class Cell{
        public:
            Cell();
            virtual int getInteger();
            virtual string getString();
            virtual void set(string value);  
    };

    class NumberCell : public Cell{
        private:
            int _number;
        public:
            NumberCell();
            void set(string value){
                _number = stoi(value);
            }

            int getInteger(){
                return _number;
            }

    };

    class TextCell : public Cell{
        private:
            string _text;
        public:
            void set(string value){
                _text = value;
            }

            string getString(){
                return _text;
            }
    };
} // namespace UserCell

#pragma once
#include "cell.h"

namespace UserTable
{
    class Table
    {
    private:
        Cell ** data;
        int width, height;
        std::string path;        
    public:
        Table(std::string filePath);
        ~Table();

        /// Draw table capacity
        void display();
        /// Set integer value on cell
        void setIntValue(int value, int xPosition, int yPosition);
        /// Set string value on cell
        void setStringValue(std::string value, int xPosition, int yPosition);
    };   

    // struct Component
    // {
    //     const char * selectionText;
    //     virtual void execute() = 0;
    // };

    // struct FirtSelection : public Component
    // {
    //     const char * selectionText = "First selection";
    //     void execute() {
    //         std::cout << "first";
    //     }
    // };

    // class Menu
    // {
    // private:
    //     std::vector<Component*> components;
    // public:
    //     void add(Component* c){
    //         components.push_back(c);
    //     }

    //     void run(){
    //         std::vector<Component*> ::iterator it;
    //         for(it = components.begin(); it < components.end(); it++){
    //             (*it)->execute();
    //         }
    //     }
    // };
} // namespace UserTable


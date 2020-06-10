#pragma once
#include <iostream>
#include <vector>

namespace UserMenu
{   
    typedef void (*Menu_Processing_Function_Pointer)();

    struct Component{
        const char * selectionText;
        Menu_Processing_Function_Pointer processingFunction;
    };

    /**
     * @brief run menu write process
     */
    void run();
    
    
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
} // namespace UserMenu

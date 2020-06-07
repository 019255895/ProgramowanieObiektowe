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
} // namespace UserMenu

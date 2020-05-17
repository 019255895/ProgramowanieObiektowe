/*!
    \warning this is only a late version of the class for rendering the menu, 
             at the moment I am composing a model for using this class, 
             but the execution model will remain the same.
    \warning I also plan to use the "Command" pattern in the future writing the program.
*/

namespace UserMenu{
    typedef void (*Menu_Processing_Function_Pointer)(void);
    
    struct ItemMenu
    {
        const char choice;
        const char * selectionText;
        Menu_Processing_Function_Pointer Action;

        ItemMenu * SubMenu;
    };

    void Run();
}
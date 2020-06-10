#pragma once
#include <iostream>
#include <map>
#include "table.h"

using namespace std;
using namespace UserTable;

namespace UserMenu
{   
    /**
     * @brief called item action
     * 
     * Command pattern realization
     */
    class Command{
    public:
        virtual void execute() = 0;
    };
    
    /**
     * @brief user menu
     */
    class Menu{
    private:
        map<Command*, string> commands;
    public:
        void add(Command* c, string line);
        void run();
    };

    void _initDataTable();
    void _initMenu();
    void _Run();

} // namespace UserMenu

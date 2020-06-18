#include <string>
#include <cstdlib>
#include "menu.h"
#include "table.h"

using namespace UserTable;

namespace UserMenu
{   
    
    // Table tab; // init table 
    Menu menu; // init menu

    /**
     * @brief clearing console in both Windows and Linux
     */
    void clear_screen(); 

    /**
     * @brief add new menu selection
     * 
     * @param c menu component
     * @param line selection text
     */
    void Menu::add(Command* c, string line){
        commands.insert(pair<Command*, string>(c, line));
    }

    void Menu::run(){
        map<Command*, string>::iterator it; // doble-value array
        string choice; // user choice
        int seletionCount = 0, commandCount = 0; 
            
        for(it = commands.begin(); it != commands.end(); it++, seletionCount++){
            cout << seletionCount << '.' << it->second << '\n'; 
        }
            
        // get use input
        cin >> choice;
        for(it = commands.begin(); it != commands.end(); it++, commandCount++){
            if (commandCount == stoi(choice)){
                it->first->execute();
                cout << "Press ENTER...\n";
                getchar();
                getchar();
                clear_screen();
            } 
        }
    }

    /**
     * @brief Close program
     * 
     * exit from programm with 0 code
     */
    class Quit : public Command{
        public:
            virtual void execute(){
                exit(0);
            }
    };

    /**
     * @brief Draw table content
     */
    class Display : public Command{
        public:
            virtual void execute(){
                // tab.display();
            }
    };

    void clear_screen(){
    #ifdef WINDOWS
        std::system("cls");
    #else
        // Assume POSIX
        std::system("clear");
    #endif
    }

    /**
     * @brief initialize data table
     * 
     * get file path from user and init table
     */
    // void _initDataTable(){
    //     string filePath;
    //     cout << "Put file path:\n";
    //     cin >> filePath;

    //     tab._init(filePath);
    // }

    /**
     * @brief initialize menu
     * 
     * add new component to menu
     */
    void _initMenu(){
        menu.add(new Display, "Display");
        menu.add(new Quit, "Quit");
    }

    /**
     * @brief rum menu
     * 
     * function for calling menu in nother files with out init
     */
    void _Run(){
        menu.run();
    }
} // namespace UserMenu

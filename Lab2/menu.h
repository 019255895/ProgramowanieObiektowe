#ifndef _MENU_H_
#define _MENU_H_

    #include <iostream>
    #include "table.h"

    using namespace std;

    Table tab(1, 1); 

    class userMenu
    {
    public:
        static bool isMenu();    
        static void mainMenu();
        static void sizeChangeMenu();
        static void dataChangeMenu();
    };

    bool userMenu::isMenu(){
        char val;

        userMenu::mainMenu();

        cin >> val;
        switch (val)
        {
            case '1':
                userMenu::sizeChangeMenu();
                break;
            
            case '2':
                userMenu::dataChangeMenu();
                break;

            case '3':
                display(tab);
                break;
            
            case 'q':
                return 0;
                break;
            
            case 'Q':
                return 0;
                break;
            
            default:
                return 1;
                break;
        }
        return 1;
    }

        void userMenu::dataChangeMenu(){
        int xPos;
        int yPos;
        int new_data;

        cout << "Column number:" << endl;
        cin >> xPos;
        cout << "Row number:" << endl;
        cin >> yPos;
        cout << "New data" << endl;
        cin >> new_data;

        set(tab, xPos, yPos, new_data);
    }

    void userMenu::sizeChangeMenu(){
        int new_width;
        int new_height;
    
        cout << "New Width:" << endl;
        cin >> new_width;
        cout << "New Height:" << endl;
        cin >> new_height;

        // resize(tab, new_width, new_height);
    }

    void userMenu::mainMenu(){
        cout << "Menu:" << endl;
        cout <<"1. Change table size."<< endl;
        cout <<"2. Change table data."<< endl;
        cout <<"3. Display table."<< endl;
        cout <<"Press q for exit."<< endl;
    }

#endif
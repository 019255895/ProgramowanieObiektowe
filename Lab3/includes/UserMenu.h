/*!
\brief User menu library 
(dog-nail) I'm creating temporary structure before reading from file

Writing user console user menu and do something after user input
*/

#ifndef _USERMENU_H_
#define _USERMENU_H_

    #include <iostream>
    #include "types/UserTable.h"
    #include "UserFiles.h"
    #include <cstdlib>

    using namespace std; 
    
    /*!
    \brief system('cls') in both console Windows and Linux
    */
    void clear_screen();
    
    Table tab(1, 1); ///< temporary table

    bool isMenu(){
        string filePath; ///< table location address
        
        int row, col; ///< value for storing information about row, column
        int new_data; ///< value for storing information about data changing

        /*!
            \brief Сheck if the table is read.
            If table is not read, program reads address to table.
        */

        if (tab.isEmpty){
            cout << "Put table path (press q for exit):" << endl;
            cin >> filePath; 
            
            /// \brief check user input for exit
            if (filePath != "q"){
                read(filePath, tab);
            } else {
                return 0;
            }
        } else {
            bool isDone = true; ///< "temp" variable only for while loop
            char userChoice; ///< user choice input

            clear_screen();
            cout << "Menu:" << endl;
            cout << "(1) Change table size."<< endl;
            cout << "(2) Change table data."<< endl;
            cout << "(3) Calculations."<< endl;
            cout << "(4) Display table."<< endl;
            cout << "(5) Save changes." << endl;
            cout << "Press q for exit."<< endl;

            cin >> userChoice;
            clear_screen();

            /*!
            /param[in] one of '1', '2', '3', '4', '5', 'q', 'Q'
            */
            switch (userChoice)
            {
            /// \brief Size changing
            case '1':
                int new_width, new_height; ///< new size variabes 
                cout << "Put new width:" << endl;
                cin >> new_width;
                cout << "Put new height:" << endl;
                cin >> new_height;

                resize(tab, new_width, new_height);
                
                cout << "Enter something to continue..." << endl;
                cin >> userChoice;
                break;
            
            /// \brief Change data in cell
            case '2':
                cout << "Put row number:" << endl;
                cin >> row;
                cout << "Put column number:" << endl;
                cin >> col;
                cout << "Put new data:" << endl;
                cin >> new_data;
                
                set(tab, row, col, new_data);
                
                cout << "Enter something to continue..." << endl;
                cin >> userChoice;
                break;
            
            /// \brief Branch for calculations menu
            case '3':
                while(isDone){
                    clear_screen();
                    cout << "(1) Summary items in row" << endl;
                    cout << "(2) Summary items in column" << endl;
                    cout << "(3) Maximum value" << endl;
                    cout << "(4) Minimum value" << endl;
                    cout << "(5) Middle value" << endl;
                    cout << "(6) Back" << endl;
                    cout << "Press q for exit."<< endl;

                    cin >> userChoice;
                    clear_screen();
                    
                    /*!
                    /param[in] one of '1', '2', '3', '4', '5', '6', 'q', 'Q'
                    */
                    switch (userChoice)
                    {
                    /// \brief Calculate row elements sum    
                    case '1':
                        cout << "Put row number:" << endl;
                        cin >> row;

                        cout << "Answer: " << SumInRow(tab, row) << endl;
                        cout << "Enter something to continue..." << endl;
                        cin >> userChoice;
                        break;

                    /// \brief Calculate column elements sum    
                    case '2':
                        cout << "Put column number:" << endl;
                        cin >> col;

                        cout << "Answer: " << SumInColumn(tab, col) << endl;
                        cout << "Enter something to continue..." << endl;
                        cin >> userChoice;
                        break;
                    
                    /// \brief Branch for find min menu 
                    case '4':
                        while(isDone){
                            clear_screen();
                            cout << "(1) In Row" << endl;    
                            cout << "(2) In Column" << endl;
                            cout << "(3) Back to menu" << endl;
                            cout << "Press q for exit."<< endl;
                            
                            cin >> userChoice;
                            clear_screen();
                            switch (userChoice)
                            {
                            case '1':
                                cout << "Put row number:" << endl;
                                cin >> row;

                                cout << "Answer: " << MinimumValue(tab, row, 'r') << endl;
                                cout << "Enter something to continue..." << endl;
                                cin >> userChoice;
                                break;
                            case '2':
                                cout << "Put column number:" << endl;
                                cin >> col;

                                cout << "Answer: " << MinimumValue(tab, col, 'c') << endl;
                                cout << "Enter something to continue..." << endl;
                                cin >> userChoice;
                                break;
                            case '3':
                                return 1;
                                break;
                            case 'q':
                            case 'Q':
                                return 0;
                                break;

                            default:
                                cout << "(Invalid value) Press any key..." << endl;
                                cin >> userChoice;
                                break;
                            }
                        }
                        break;
                    
                    /// \brief Branch for find max menu 
                    case '3':
                        while(isDone){
                            clear_screen();
                            cout << "(1) In Row" << endl;    
                            cout << "(2) In Column" << endl;
                            cout << "(3) Back to menu" << endl;
                            cout << "Press q for exit."<< endl;
                            
                            cin >> userChoice;
                            clear_screen();
                            switch (userChoice)
                            {
                            case '1':
                                cout << "Put row number:" << endl;
                                cin >> row;

                                cout << "Answer: " << MaximumValue(tab, row, 'r') << endl;
                                cout << "Enter something to continue..." << endl;
                                cin >> userChoice;
                                break;
                            case '2':
                                cout << "Put column number:" << endl;
                                cin >> col;

                                cout << "Answer: " << MaximumValue(tab, col, 'c') << endl;
                                cout << "Enter something to continue..." << endl;
                                cin >> userChoice;
                                break;
                            case '3':
                                return 1;
                                break;
                            case 'q':
                            case 'Q':
                                return 0;
                                break;

                            default:
                                cout << "(Invalid value) Press any key..." << endl;
                                cin >> userChoice;
                                break;
                            }
                        }
                        break;

                    /// \brief Branch for find medium menu 
                    case '5':
                        while(isDone){
                            clear_screen();
                            cout << "(1) In Row" << endl;    
                            cout << "(2) In Column" << endl;
                            cout << "(3) Back to menu" << endl;
                            cout << "Press q for exit."<< endl;
                            
                            cin >> userChoice;
                            clear_screen();
                            switch (userChoice)
                            {
                            case '1':
                                cout << "Put row number:" << endl;
                                cin >> row;

                                cout << "Answer: " << MediumValue(tab, row, 'r') << endl;
                                cout << "Enter something to continue..." << endl;
                                cin >> userChoice;
                                break;
                            case '2':
                                cout << "Put column number:" << endl;
                                cin >> col;

                                cout << "Answer: " << MediumValue(tab, col, 'c') << endl;
                                cout << "Enter something to continue..." << endl;
                                cin >> userChoice;
                                break;
                            case '3':
                                return 1;
                                break;
                            case 'q':
                            case 'Q':
                                return 0;
                                break;

                            default:
                                cout << "(Invalid value) Press any key..." << endl;
                                cin >> userChoice;
                                break;
                            }
                        }
                        break;
                    case '6':
                        return 1;
                        break;
                    case 'q':
                    case 'Q':
                        return 0;
                        break;

                    default:
                        cout << "(Invalid value) Press any key..." << endl;
                        cin >> userChoice;
                        break;
                    }
                }
                break;
            case '4':
                display(tab);
                
                cout << "Enter something to continue..." << endl;
                cin >> userChoice;
                break;
            case '5':
                cout << "Save file us:" << endl;
                cin >> filePath;
                
                write(filePath, tab);
                return 0;
                break;
            case 'q':
            case 'Q':
                return 0;

            default:
                cout << "(Invalid value) Press any key..." << endl;
                cin >> userChoice;
                break;
            }
        }
    }

    void clear_screen()
    {
        #ifdef WINDOWS
            std::system("cls");
        #else
            // Assume POSIX
            std::system ("clear");
        #endif
    }    
#endif
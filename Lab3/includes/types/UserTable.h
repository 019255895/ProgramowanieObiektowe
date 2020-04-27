/*!
\brief Table class file header   
This class contain structure for convenient work with the table
*/

#ifndef _USERTABLE_H_
#define _USERTABLE_H_

    #include <iostream>

    struct Table
    {
        int ** data; ///< 2D an array for storing information about the contents of the table
        int width; ///< Number of table rows
        int height; ///< Number of table columns
        bool isEmpty = true; ///< indicates whether the table has been read from the file (in this case is the table empty)
        
        Table(int rows, int cols); // Constructor definition
        ~Table(); // Destructor definition
    };
    
    /*!
    \brief Constructor  
    \param[in] rows number of table rows (table width) 
    \param[in] cols number of table cols (table height)

    Automatically called when an object of a class is created
    */
    Table::Table(int rows, int cols) : width(rows), height(cols)
    {   
        /// \brief Allocation memory for table rows
        data = new int* [rows](); 
        
        /// \brief Allocation memory for table column in every row 
        for (int i = 0; i < rows; i++){
            data[i] = new int[cols]();
        }
    }
    
    /*!
    \brief Destructor

    Called when the lifetime of an object ends.
    */
    Table::~Table()
    {
        for (auto i = 0; i < height; i++) 
            delete[] data[i];
        
        delete[] data; 
    }

    /*!
    \brief Change table data size
    \param[in] tab pointer of object  
    \param[in] xPos, yPos cell position
    \param[in] val new cell value
    */
    void set(Table& tab, int xPos, int yPos, int val){
        /// \brief check for user coordinates coming out of table size
        if (xPos <= tab.width && yPos <= tab.height){
            /// \brief set new data 
            tab.data[xPos][yPos] = val;
        } else {
            std::cout << "Out of table size" << std::endl;
        }
    }

    /*!
    \brief Dispay table
    \param[in] tab pointer of object 
    */
    void display(Table& tab){
        for (int i = 0; i < tab.width; i++){
            for (int j = 0; j < tab.height; j++){
                std::cout << tab.data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    /*!
    \brief Change table size
    \param[in] new_width, new_height new table size

    Resizing a table using a temporary table by writing 
    the table data to a temporary table, then deleting it 
    and implementing tables with a new size and 
    writing previous data to it
    */
    void resize(Table& tab, int new_width, int new_height){
        Table temp(tab.width, tab.height); ///< temporary table

        ///\brief Copy exist table data to temporary
        for (size_t i = 0; i < temp.width; i ++){
            for (size_t j = 0; j < temp.height; j ++){
                temp.data[i][j] = tab.data[i][j];
            }
        }

        ///\brief dealocate dynamically allocated memory
        for (auto i = 0; i < tab.height; i++) 
            delete[] tab.data[i];

        delete[] tab.data; 

        ///\brief change number of rows and columns in table class
        tab.width = new_width;
        tab.height = new_height;

        ///\brief allocate memory with new size        
        tab.data = new int* [new_width]();
        
        for (size_t i = 0; i < new_width; i++){
            tab.data[i] = new int[new_height]();
        }

        ///\brief copy temporary data to table 
        for (size_t i = 0; i < temp.width; i ++){
            for (size_t j = 0; j < temp.height; j ++){
                tab.data[i][j] = temp.data[i][j];
            }
        }
    }

    /*!
    \brief summary items in a row
    \param[in] row input row index
    \return sum of elements in tabel row 
    */
    int SumInRow(Table &tab, int row){
        ///\brief check for out size
        if (row <= tab.width){
            int sum = 0;
            for (size_t i = 0; i < tab.width + 1; i++){
                sum += tab.data[row][i];
            }

            return sum;
        } else {
            std::cout << "Out of size" << std::endl;
        }
    }

    /*!
    \brief summary items in a column
    \param[in] column input column index
    \return sum of elements in tabel column 
    */
    int SumInColumn(Table &tab, int column){
        ///\brief check for out size
        if (column <= tab.height){
            int sum = 0;
            for (size_t i = 0; i < tab.height; i++){
                sum += tab.data[i][column];
            }

            return sum;
        } else {
            std::cout << "Out of size" << std::endl;
        }
    }

    /*!
    \brief Find minimum value in item (row or column)
    \param[in] item contain row or column number
    \param[in] option contain information about work mode ('r' or 'c')
    \return minimum value in column or row

    To work in the function you need to pass the value of the option
    'r' if we searching minimum in row 
    'c' if we searching minimum in column
    */
    int MinimumValue(Table &tab, int item, char option){
        int min; ///< contain information about minimum value 

        ///\brief check option
        if (option == 'r'){
            ///\brief check for out size
            if (item <= tab.width){
                min = tab.data[item][1];
                for (int i = 0; i < item; i ++){
                    if (tab.data[item][i] < min){
                        min = tab.data[item][i];
                    } 
                }

                return min;
            } else {
                std::cout << "Out of size" << std::endl;
            }
        } else 
        if (option == 'c'){
            ///\brief check for out size
            if (item <= tab.height){
                min = tab.data[0][item];
                for (int i = 0; i < item + 1; i ++){
                    if (tab.data[i][item] < min){
                        min = tab.data[i][item];
                    } 
                }

                return min;
            } else {
                std::cout << "Out of size" << std::endl;
            }
        } else {
            std::cout << "Option error" << std::endl;
        }  
        
    }

    /*!
    \brief Find maximum value in item (row or column)
    \param[in] item contain row or column number
    \param[in] option contain information about work mode ('r' or 'c')
    \return maximum value in column or row

    To work in the function you need to pass the value of the option
    'r' if we searching maximum in row 
    'c' if we searching maximum in column
    */
    int MaximumValue(Table &tab, int item, char option){
        int max; ///< contain information about maximum value 

        ///\brief check option
        if (option == 'r'){
            ///\brief check for out size
            if (item <= tab.width){
                max = tab.data[item][1];
                for (int i = 0; i < item; i ++){
                    if (tab.data[item][i] > max){
                        max = tab.data[item][i];
                    } 
                }

                return max;
            } else {
                std::cout << "Out of size" << std::endl;
            }
        } else 
        if (option == 'c'){
            ///\brief check for out size
            if (item <= tab.height){
                max = tab.data[0][item];
                for (int i = 0; i < item + 1; i ++){
                    if (tab.data[i][item] > max){
                        max = tab.data[i][item];
                    } 
                }

                return max;
            } else {
                std::cout << "Out of size" << std::endl;
            }
        } else {
            std::cout << "Option error" << std::endl;
        }  
    }
    
    /// \brief Buble sort function
    void Buble(int &arr, int size);

    /// \brief Check if array is sorted
    bool isSorted(int &arr, int size);
    
    /// \brief Swap two nums value
    void swap(int *num1, int *num2);

    /*!
    \brief Find medium value in item (row or column)
    \param[in] item contain row or column number
    \param[in] option contain information about work mode ('r' or 'c')
    \return medium value in column or row

    To work in the function you need to pass the value of the option
    'r' if we searching medium in row 
    'c' if we searching medium in column
    */
    int MediumValue(Table &tab, int item, char option){
        int Medium; ///< contain information about medium value 

        ///\brief check option
        if (option == 'r'){
            ///\brief check for out size
            if (item <= tab.width){
                int *temp = new int[tab.width]; 

                for (size_t i = 0; i < tab.width; i ++){
                    temp[i] = tab.data[item][i];
                }
                
                // Buble(temp, tab.width);
                
                if (tab.width % 2 != 0){
                    return temp[0];
                } else {
                    // return (temp[int(tab.width / 2)] + temp[int(tab.width / 2)  + 1]) / 2;
                }
            } else {
                std::cout << "Out of size" << std::endl;
            }
        } else 
        if (option == 'c'){
            ///\brief check for out size
            if (item <= tab.height){
                



            } else {
                std::cout << "Out of size" << std::endl;
            }
        } else {
            std::cout << "Option error" << std::endl;
        }  
    }

    bool isSorted(int arr[], int size){
        for (int i = 0; i < size - 1; i++){
            if (arr[i] > arr[i + 1]){
                return false;
            }
        }
        return true;
    }

    void Buble(int arr[], int size){
        while (!isSorted(arr, size)){
            for (int i = 0; i < size - 1; i++){
                if (arr[i] > arr[i + 1]){
                    swap(&arr[i], &arr[i + 1]);
                }    
            }   
        }
    }

    void swap(int *num1, int *num2)  
    {  
        int temp = *num1;  
        *num1 = *num2;  
        *num2 = temp;  
    }  
#endif // _USERTABLE_H_
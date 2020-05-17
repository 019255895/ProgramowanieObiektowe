#pragma once 
#include <iostream>
#include <string>
#include "table.h"

/*!
   \brief Space for actions on the table
   
   Actions:
      - readFromFile() reading data from file (set table isEmpty false)
      - writeToFile() writing data to file (
         num of rows,
         num of columns,
         data array 
      )
      - display() display table data
      - setCellValue() set new value at Cell(x, y)
*/
namespace UserActions{
   /*!
    \brief Filling a table with data from a file.
    \param[in] tab - table object pointer
    \param[in] filePath - path to file for reading 
   */     
   void readFromFile(Table &tab, std::string filePath);
   
   /*!
    \brief Write table data to file 
    \param[in] tab - table object pointer
    \param[in] filePath - path to file for writing
    \param[in] fileName - name for saving file as
   */
   void writeToFile(Table &tab, std::string filePath, std::string fileName);

   /*!
    \brief Display table data
    \param[in] tab - table object pointer
   */
   void display(Table &tab);

   /*!
    \brief replacing a cell(x, y) value with "value"
    \param[in] tab - table object pointer
    \param[in] xCell, yCell - cell position
    \param[in] value - new value for replacing
   */
   void setCellValue(Table &tab, int xCell, int yCell, int value);
}